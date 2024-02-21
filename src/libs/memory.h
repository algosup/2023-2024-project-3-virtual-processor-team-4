#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Platform specific includes
#ifdef _WIN32
#include <direct.h>
#define mkdir(path, mode) _mkdir(path)
#else
#include <sys/stat.h>
#include <sys/types.h>
#endif



// the memory
#define NUMBER_PAGES 4
#define PAGE_SIZE 1048576

uint8_t memoryPages[NUMBER_PAGES][PAGE_SIZE];
int memoryPagesMapping[NUMBER_PAGES];
int memoryPagesHistory[NUMBER_PAGES]; // In order of usage with most recently used last
bool memoryInitialized = false;

// TODO: Temporary directory
#define TEMPLATE_MEMORY_DIRECTORY "memory"
#define TEMPLATE_MEMORY_FILEPATH (TEMPLATE_MEMORY_DIRECTORY "/%d.mem")
#define MAX_MEMORY_INDEX (UINT32_MAX / PAGE_SIZE)



FILE* get_memory_file(int page, const char* mode)
{
    // Get the filename for this file
    char filename[256];
    int err = sprintf_s(filename, sizeof(filename), TEMPLATE_MEMORY_FILEPATH, page);
    if (!err)
    {
        fprintf(stderr, "Failed to generate filename for memory file %d\n", page);
        abort();
    }

    // Open the file
    FILE* fs;
    err = fopen_s(&fs, filename, mode);
    if (err)
    {
        fprintf(stderr, "Failed to open memory file %d: %s\n", page, strerror(err));
        abort();
    }

    return fs;
}

void init_memory(void)
{
    // Initialize the indices arrays
    for (int i = 0; i < NUMBER_PAGES; i++)
    {
        memoryPagesMapping[i] = i;
        memoryPagesHistory[i] = i;
    }

    // Create the directory for the swap files
    int ret = mkdir(TEMPLATE_MEMORY_DIRECTORY, 0777);
    if (ret != 0 && errno != EEXIST)
    {
        perror("Failed to generate directory for memory files\n");
        abort();
    }

    // Initialize the swap files
    for (int i = 0; i <= MAX_MEMORY_INDEX; i++)
    {
        FILE* fs = get_memory_file(i, "wb");

        // Set the number of bytes we want
        int err = fseek(fs, PAGE_SIZE, SEEK_SET);
        if (err)
        {
            fprintf(stderr, "Failed to write initial memory file %d: %s\n", i, strerror(err));
            abort();
        }

        // Write a character to set the size
        err = fputc(0, fs);
        if (err)
        {
            fprintf(stderr, "Failed to write initial memory file %d: %s\n", i, strerror(err));
            abort();
        }

        // We are done with this file
        fclose(fs);
    }

    memoryInitialized = true;
}

int load_page_memory(int page)
{
    // Update the history
    for (int i = 0; i < NUMBER_PAGES - 1; i++)
    {
        if (memoryPagesHistory[i] != page)
            continue;
        memoryPagesHistory[i] = memoryPagesHistory[i + 1];
        memoryPagesHistory[i + 1] = page;
    }

    // Check if page is already loaded
    if (memoryPagesHistory[NUMBER_PAGES - 1] == page)
        for (int i = 0; i < NUMBER_PAGES; i++)
            if (memoryPagesMapping[i] == page)
                return i;

    // Find the index of the oldest page
    int index = -1;
    for (int i = 0; i < NUMBER_PAGES; i++)
        if (memoryPagesMapping[i] == memoryPagesHistory[0])
            index = i;
    if (index == -1)
    {
        perror("Desync between memory mapping and history");
        abort();
    }
    
    // Write the old page back
    FILE* fs = get_memory_file(memoryPagesHistory[0], "wb");
    int written = fwrite(memoryPages[index], sizeof(uint8_t), PAGE_SIZE, fs);
    if (written != PAGE_SIZE)
    {
        perror("Could not write memory page back");
        abort();
    }
    fclose(fs);

    // Read the new page
    fs = get_memory_file(page, "rb");
    int read = fread(memoryPages[index], sizeof(uint8_t), PAGE_SIZE, fs);
    if (read != PAGE_SIZE)
    {
        perror("Could not read memory page");
        abort();
    }
    fclose(fs);
    memoryPagesMapping[index] = page;
    memoryPagesHistory[0] = page;

    // Re-run the function now that the page is ready
    return load_page_memory(page);
}

uint8_t read_memory_8(uint32_t address)
{
    int page = address / PAGE_SIZE;
    int index = load_page_memory(page);
    return memoryPages[index][address % PAGE_SIZE];
}

uint32_t read_memory_32(uint32_t address)
{
    // Weirdly enough, this code is actually optimized for all edge cases
    uint32_t value;
    for (int i = 3; i >= 0; i--)
    {
        value <<= 8;
        value |= read_memory_8(address + i);
    }
    return value;
}

void set_memory_8(uint32_t address, uint8_t value)
{
    int page = address / PAGE_SIZE;
    int index = load_page_memory(page);
    memoryPages[index][address % PAGE_SIZE] = value;
}

void set_memory_32(uint32_t address, uint32_t value)
{
    // Weirdly enough, this code is actually optimized for all edge cases
    for (int i = 0; i < 4; i++)
    {
        set_memory_8(address + i, value & 0xff);
        value >>= 8;
    }
}