#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "utils.h"

int read_bin(char*, uint8_t**, uint32_t*);
int check_opcode(uint8_t*, binInstruction_t*);
int opcode_type_I(binInstruction_t*, uint8_t, uint8_t, uint8_t, int16_t);
int opcode_type_J(binInstruction_t*, uint8_t, uint8_t, int16_t);
int opcode_type_R(binInstruction_t*, uint8_t, uint8_t, uint8_t, uint8_t);

int read_bin(char* inputFile, uint8_t** outputPtr, uint32_t* size){
    FILE *f = fopen(inputFile, "rb");
    if (f == NULL) {
        perror("Error: Failed to open file");
        return FILE_NOT_FOUND;
    }

    fseek(f, 0, SEEK_END);
    *size = ftell(f);
    rewind(f);

    // Adjust allocation size for uint32_t and ensure it is a multiple of 4
    long adjustedSize = *size - (*size % 4);
    if(adjustedSize != *size){
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

int make_map_of_instructions(char* inputFile, binInstruction_t** mapOfInstructions){
    uint8_t* outputPtr;
    uint32_t size;
    read_bin(inputFile, &outputPtr, &size);

    *mapOfInstructions = (binInstruction_t*)malloc(sizeof(binInstruction_t) * size/4);
    if (*mapOfInstructions == NULL) {
        perror("Error: Memory allocation failed");
        return GENERIC_ERROR;
    }

    int instructionCounter = 0;

    for (size_t i = 0; i <= size-3; i+4)
    {
        if(i+3 > size){
            printf("Error: Invalid number of byte in instruction");
            return GENERIC_ERROR;
        }

        uint8_t byteIn[4] = {outputPtr[i], outputPtr[i+1], outputPtr[i+2], outputPtr[i+3]};
        int error = check_opcode(byteIn, mapOfInstructions[instructionCounter]);
        if(error != SUCCESS){
            return error;
        }
        instructionCounter++;
    }

    return SUCCESS;
}

int check_opcode(uint8_t* byteIn, binInstruction_t* instruction){
    uint8_t opcode;

    //calculate source, source2, immediate, and dest
    uint8_t source = byteIn[2] << 3;
    source = source | byteIn[3] >> 5;

    uint8_t source2 = byteIn[2] & 0b01111100;

    uint8_t dest = byteIn[3] & 0b00011111; //mask the last three bits

    int16_t immediate = byteIn[0] << 14;
    immediate = immediate | byteIn[1] << 6;
    immediate = immediate | byteIn[2] >> 2;

    if(byteIn[0] >> 6 == true){
        // every type I instruction has this patern 01000000
        instruction->type = I;
        opcode = byteIn[0] >> 2;

        return opcode_type_I(instruction, opcode, source, dest, immediate);

    }else if(byteIn[0] >> 7 == true){
        // every type I instruction has this patern 01000000
        instruction->type = J;
        opcode = byteIn[0] >> 4;
        return opcode_type_J(instruction, opcode, dest, immediate);
    }else{
        instruction->type = R;
        opcode = byteIn[0] >> 1;
        return opcode_type_R(instruction, opcode, source, source2, dest);
    } 
};

int opcode_type_I(binInstruction_t* instruction, uint8_t opcode, uint8_t source, uint8_t dest, int16_t immediate){

    instruction->typeI.source = source;
    instruction->typeI.destination = dest;
    instruction->typeI.immediate = immediate;

    switch (opcode)
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

int opcode_type_J(binInstruction_t* instruction, uint8_t opcode, uint8_t dest, int16_t immediate){
    instruction->typeJ.register_ = dest;
    instruction->typeJ.address = immediate;

    switch (opcode)
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

int opcode_type_R(binInstruction_t* instruction, uint8_t opcode, uint8_t source, uint8_t source2, uint8_t dest){
    instruction->typeR.source = source;
    instruction->typeR.source2 = source2;
    instruction->typeR.destination = dest;

    switch (opcode)
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