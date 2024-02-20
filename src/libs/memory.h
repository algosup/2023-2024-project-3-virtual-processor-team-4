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
        // Get the filename for this file
        char filename[256];
        int err = sprintf_s(filename, sizeof(filename), TEMPLATE_MEMORY_FILEPATH, i);
        if (!err)
        {
            fprintf(stderr, "Failed to generate filename for memory file %d\n", i);
            abort();
        }

        // Open the file
        FILE* fs;
        err = fopen_s(&fs, filename, "wb");
        if (err)
        {
            fprintf(stderr, "Failed to open memory file %d for initialization: %s\n", i, strerror(err));
            abort();
        }

        // Set the number of bytes we want
        err = fseek(fs, PAGE_SIZE, SEEK_SET);
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

uint8_t read_memory_8(uint32_t address)
{
    perror("read_memory_8 not implemented");
    abort();
}

uint32_t read_memory_32(uint32_t address)
{
    perror("read_memory_32 not implemented");
    abort();
}

void set_memory_8(uint32_t address, uint8_t value)
{
    perror("set_memory_8 not implemented");
    abort();
}

void set_memory_32(uint32_t address, uint32_t value)
{
    perror("set_memory_32 not implemented");
    abort();
}