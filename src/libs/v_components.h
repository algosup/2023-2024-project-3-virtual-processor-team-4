#ifndef V_COMPONENTS_H
#define V_COMPONENTS_H

#include <errno.h>
#include <limits.h>
#include "utils.h"

// Platform specific includes
#ifdef _WIN32
#include <direct.h>
#define mkdir(path, mode) _mkdir(path)
#else
#include <sys/stat.h>
#include <sys/types.h>
#endif

#define DEC 10
#define HEX 16
#define BIN 2

//__________________________________________________________________________________________________
//  THE VIRTUAL COMPONENTS OF THE ARCHITECTURE
//__________________________________________________________________________________________________

//______________________________________________
//  VIRTUAL REGISTERS
//  32 registers of 32 bits

int32_t registerArr[32];

//______________________________________________
//  VIRTUAL MEMORY
//  4GB of memory addressable by 32 bits addresses

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

// Memory ranges
#define CODE_SECTION_START 0x00000000
#define CODE_SECTION_END 0x1FFFFFFF
#define RAM_SECTION_START 0x20000000
#define RAM_SECTION_END 0x7FFFFFFF
#define PERIPHERAL_SECTION_START 0x80000000
#define PERIPHERAL_SECTION_END 0x9FFFFFFF
#define SYSTEM_SECTION_START 0xE0000000
#define SYSTEM_SECTION_END 0xFFFFFFFF



FILE* get_memory_file(int page, const char* mode)
{
    // Get the filename for this file
    char filename[256];
    int err = sprintf(filename, TEMPLATE_MEMORY_FILEPATH, page);
    if (!err)
    {
        fprintf(stderr, "Failed to generate filename for memory file %d\n", page);
        abort();
    }

    // Open the file
    FILE* fs = fopen(filename, mode);
    if (!fs)
    {
        fprintf(stderr, "Failed to open memory file %d: %s\n", page, strerror(errno));
        abort();
    }

    return fs;
}

void init_memory(void)
{
    // Initialize the sp and ip pointers
    registerArr[STACK_POINTER] = SYSTEM_SECTION_END - 3;
    registerArr[INSTRUCTION_POINTER] = CODE_SECTION_START;

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
    for (int i = 0; i < 4; i++)
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
    for (int i = 3; i >= 0; i--)
    {
        set_memory_8(address + i, value & 0xff);
        value >>= 8;
    }
}

//__________________________________________________________________________________

//______________________________________________
// PRINT COMPONENTS
//__________________

int print_registers(int base);
int print_register(int reg, int base);
int print_memory(uint32_t start, uint32_t end, int base);
void print_32b_number(uint32_t number, int base, uint32_t max);


void print_32b_number(uint32_t number, int base, uint32_t max)
{
    //nibbles is the number of nibbles to print, so we print numbers by block of 4 digits in hexa and binary and 3 digits in decimal
    if (base == HEX)
    {   
        int nibbles = 4;
        if (max > 0xFFFF){
            nibbles = 8;
        }
        if (nibbles == 4){
            printf("0x%04X ", number);
        }else{
            uint16_t b = number>> 16;
            printf("0x%04X ", b);
            b = number<<16>>16;
            printf("%04X", b);
        }
    }
    else if (base == BIN)
    {
        int nibbles = 8;
        int counter = nibbles;
        for (int i = 0; i <= counter; i++)
        {
            if (max << i*4 >> i*4 == max){ nibbles--;}
        }
        if (nibbles == 0){nibbles = 1;}
        printf("0b");
        for (int i = nibbles*4-1; i >= 0; i--)
        {
            printf("%d", (number >> i) & 1);
            if (i % 4 == 0)
            {
                printf(" ");
            }
        }
    }
    else if (base == DEC)
    {
        printf("%d", number);
    }
    else
    {
        printf("Invalid base");
    }
}

int print_registers(int base)
{
    if (base != HEX && base != DEC && base != BIN)
    {
        printf("Invalid base\n");
        return GENERIC_ERROR;
    }
    printf("\nRegisters:\n");
    for (int i = 0; i < 32; i++)
    {
        printf("R_%02d: ", i);
        print_32b_number(registerArr[i], base, 32);
        printf("\n");
    }
    return SUCCESS;
}

int print_register(int reg, int base)
{   
    if (base != HEX && base != DEC && base != BIN)
    {
        printf("Invalid base\n");
        return GENERIC_ERROR;
    }
    if (reg < 0 || reg > 31)
    {
        printf("Invalid register (trying to print)\n");
        return GENERIC_ERROR;
    }

    printf("\nR_%02d: ", reg);
    print_32b_number(registerArr[reg], base, 32);
    printf("\n");

    return SUCCESS;
}

int print_memory(uint32_t start, uint32_t end, int base)
{
    if (base != HEX && base != DEC && base != BIN)
    {
        printf("Invalid base\n");
        return GENERIC_ERROR;
    }
    if (start < 0 || start > 0xFFFFFFFF || end < 0 || end > 0xFFFFFFFF || start > end)
    {
        printf("Invalid memory range (trying to print)\n");
        return OUT_OF_MEMORY;
    }
    printf("\nMemory:\n");
    for (uint32_t i = start; i < end; i += 4)
    {   
        print_32b_number(i, HEX, end);
        printf(" : ");
        uint32_t value = read_memory_32(i);
        print_32b_number(value, base, 0xFFFFFFFF);
        printf("\n");
    }
    return SUCCESS;
}
//__________________________________________________________________________________


#endif // V_COMPONENTS_H