#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

uint16_t registerArr[32];

uint8_t memory[201326591];


int read_bin(char* inputFile, uint32_t** outputPtr){
    FILE *f = fopen(inputFile, "rb");
    if (f == NULL) {
        perror("Error: Failed to open file");
        return FILE_NOT_FOUND;
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    rewind(f);

    // Adjust allocation size for uint32_t and ensure it is a multiple of 4
    long adjustedSize = size - (size % 4);
    *outputPtr = (uint32_t*)malloc(sizeof(uint32_t) * (adjustedSize / 4));
    if (*outputPtr == NULL) {
        perror("Error: Memory allocation failed");
        fclose(f);
        return GENERIC_ERROR;
    }

    size_t read = fread(*outputPtr, 4, adjustedSize / 4, f);
    if (read < (adjustedSize / 4)) {
        perror("Error: Failed to read file");
        free(*outputPtr);
        fclose(f);
        return GENERIC_ERROR;
    }

    fclose(f);

    return SUCCESS;
}


#endif