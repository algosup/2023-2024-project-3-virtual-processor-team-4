#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

uint16_t registerArr[32];

uint8_t memory[201326591];


int read_bin(char* inputFile, char* output){
    FILE *f = fopen(inputFile, "rb");

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    rewind(f);

    output = (char*)malloc(sizeof(char)*size);

    if (f == NULL)
    {
        printf("Failed to open file: %s\n\n", inputFile);
        return FILE_NOT_FOUND;
    }

    fclose(f);

    //memcpy(p, &node, sizeof(char));
    return SUCCESS;
}

#endif