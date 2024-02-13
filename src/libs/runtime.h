#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

uint16_t registerArr[32];

uint8_t memory[201326591];


int read_bin(char* inputFile, uint8_t** output){
    FILE *f = fopen(inputFile, "rb");
    if (f == NULL)
    {
        perror("Error: Failed to open file");
        return FILE_NOT_FOUND;
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    rewind(f);

    *output = (uint8_t*)malloc(sizeof(uint8_t)*size);
    if (*output == NULL) {
        perror("Error: Memory allocation failed");
        fclose(f);
        return GENERIC_ERROR;
    }

    size_t read = fread(*output, 1, size, f);
    if (read < size) {
        perror("Error: Failed to read file");
        free(*output);
        fclose(f);
        return GENERIC_ERROR;
    }

    fclose(f);
    return SUCCESS;
}

#endif