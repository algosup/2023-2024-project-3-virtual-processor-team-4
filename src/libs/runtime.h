#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//__________________________________________________________________________________________________
//  VIRTUAL COMPONENTS
//_____________________

uint16_t registerArr[32];     // the 32 registers

// the memory
uint8_t codeSection[33554432];  // 32 MB of the code section
uint8_t dataSection[1073741824];  // 1 GB of the data section
uint8_t inputSection[1024]; // 1 KB of the output section
uint8_t outputSection[32768]; // 32 KB of the input section
uint8_t videoSection[262144]; // 256 KB of the video section
uint8_t stackSection[1048576]; // 1 MB of the stack section

// No flags
//__________________________________________________________________________________________________

typedef enum binType{
    R,
    I,
    J
}binType_t;

typedef struct binInstruction
{
    binType_t type;
    union
    {
        struct typeR
        {
            uint8_t opcode; //7bits
            uint8_t source2; //5bits
            uint8_t source;
            uint8_t destination;
        }typeR;
        struct typeI
        {
            uint8_t opcode; //6bits
            int16_t immediate; //16bits
            uint8_t source; //5bits
            uint8_t destination;
        }typeI;
        struct typeJ
        {
            uint8_t opcode; //4bits
            int32_t addres;
            uint8_t register_; //5bits
        }typeJ;
    };
} binInstruction_t;

int read_bin(char*, uint8_t**);
int check_opcode(uint8_t, binInstruction_t*);
int opcode_type_I(uint8_t, binInstruction_t*);
int opcode_type_J(uint8_t, binInstruction_t*);
int opcode_type_R(uint8_t, binInstruction_t*);

int read_bin(char* inputFile, uint8_t** outputPtr){
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
    if(adjustedSize != size){
        printf("Warning: Total number of bytes should be divisible by 4 but is not.");
    }
    *outputPtr = (uint8_t*)malloc(sizeof(uint8_t) * (adjustedSize));
    if (*outputPtr == NULL) {
        perror("Error: Memory allocation failed");
        fclose(f);
        return GENERIC_ERROR;
    }

    size_t read = fread(*outputPtr, 1, adjustedSize, f);
    if (read < adjustedSize) {
        perror("Error: Failed to read file");
        free(*outputPtr);
        fclose(f);
        return GENERIC_ERROR;
    }

    fclose(f);

    return SUCCESS;
}


int check_opcode(uint8_t byteIn, binInstruction_t* instruction){
    uint8_t buffer;

    if(byteIn >> 6 == true){
        // every type I instruction has this patern 01000000
        instruction->type = I;
        buffer = byteIn >> 2;
        return opcode_type_I(buffer, instruction);
    }else if(byteIn >> 7 == true){
        // every type I instruction has this patern 01000000
        instruction->type = J;
        buffer = byteIn >> 4;
        return opcode_type_J(buffer, instruction);
    }else{
        instruction->type = R;
        buffer = byteIn >> 1;
        return opcode_type_R(buffer, instruction);
    }
};

int opcode_type_I(uint8_t byteIn, binInstruction_t* instruction){
    switch (byteIn)
    {
    case 0b010000:
        instruction->typeI.opcode = ADDI;
        break;
    case 0b010101:
        instruction->typeI.opcode = ANDI;
        break;
    case 0b010011:
        instruction->typeI.opcode = LDI;
        break;
    case 0b010100:
        instruction->typeI.opcode = ORI;
        break;
    case 0b010111:
        instruction->typeI.opcode = SET;
        break;
    case 0b010010:
        instruction->typeI.opcode = STRI;
        break;
    case 0b010001:
        instruction->typeI.opcode = SUBI;
        break;
    case 0b011100:
        instruction->typeI.opcode = TEQI;
        break;
    case 0b011010:
        instruction->typeI.opcode = TGEI;
        break;
    case 0b011011:
        instruction->typeI.opcode = TGTI;
        break;
    case 0b011001:
        instruction->typeI.opcode = TLEI;
        break;
    case 0b011000:
        instruction->typeI.opcode = TLTI;
        break;
    case 0b011101:
        instruction->typeI.opcode = TNEI;
        break;
    case 0b010110:
        instruction->typeI.opcode = XORI;
        break;
    default:
        printf("Error: Invalid machine code operand\n");
        return GENERIC_ERROR;
    }
    return SUCCESS;
};

int opcode_type_J(uint8_t byteIn, binInstruction_t* instruction){
    switch (byteIn)
    {
    case 0b1000:
        instruction->typeJ.opcode = B;
        break;
    case 0b1001:
        instruction->typeJ.opcode = BI;
        break;
    case 0b1011:
        instruction->typeJ.opcode = BNZ;
        break;
    case 0b1010:
        instruction->typeJ.opcode = BZ;
        break;
    case 0b1100:
        instruction->typeJ.opcode = CALL;
        break;
    case 0b1101:
        instruction->typeJ.opcode = CALLI;
        break;
    case 0b1111:
        instruction->typeJ.opcode = JMP;
        break;
    case 0b1110:
        instruction->typeJ.opcode = RET;
        break;
    default:
        printf("Error: Invalid machine code operand\n");
        return GENERIC_ERROR;
    }
    return SUCCESS;
}

int opcode_type_I(uint8_t byteIn, binInstruction_t* instruction){
    switch (byteIn)
    {
    case 0b0000111:
        instruction->typeR.opcode = ABS;
        break;
    case 0b0000000:
        instruction->typeR.opcode = ADD;
        break;
    case 0b0000101:
        instruction->typeR.opcode = AND;
        break;
    case 0b0000011:
        instruction->typeR.opcode = DIV;
        break;
    case 0b0010001:
        instruction->typeR.opcode = LD;
        break;
    case 0b0010011:
        instruction->typeR.opcode = LDP;
        break;
    case 0b0000010:
        instruction->typeR.opcode = MUL;
        break;
    case 0b0000100:
        instruction->typeR.opcode = OR;
        break;
    case 0b0010101:
        instruction->typeR.opcode = POP;
        break;
    case 0b0010100:
        instruction->typeR.opcode = PUSH;
        break;
    case 0b0010000:
        instruction->typeR.opcode = STR;
        break;
    case 0b0010010:
        instruction->typeR.opcode = STRP;
        break;
    case 0b0000001:
        instruction->typeR.opcode = SUB;
        break;
    case 0b0001100:
        instruction->typeR.opcode = TEQ;
        break;
    case 0b0001011:
        instruction->typeR.opcode = TGE;
        break;
    case 0b0001010:
        instruction->typeR.opcode = TGT;
        break;
    case 0b0001001:
        instruction->typeR.opcode = TLE;
        break;
    case 0b0001000:
        instruction->typeR.opcode = TLT;
        break;
    case 0b0001101:
        instruction->typeR.opcode = TNE;
        break;
    case 0b0010110:
        instruction->typeR.opcode = XCHG;
        break;
    case 0b0000110:
        instruction->typeR.opcode = XOR;
        break;
    default:
        printf("Error: Invalid machine code operand\n");
        return GENERIC_ERROR;
    }
    return SUCCESS;
}

#endif