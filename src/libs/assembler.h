#ifndef COMPILED_H
#define COMPILED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "utils.h"

char *outputFile = "../compiled.bin";

int16_t registerArr[32];

int add(line_t instruction);
int sub(line_t instruction);
int mul(line_t instruction);
int div_(line_t instruction);
int or_(line_t instruction);
int and_(line_t instruction);
int xor_(line_t instruction);
int teq(line_t instruction);
int tne(line_t instruction);
int tlt(line_t instruction);
int tle(line_t instruction);
int tgt(line_t instruction);
int tge(line_t instruction);
int push(line_t instruction);
int pop(line_t instruction);
int str(line_t instruction);
int ld(line_t instruction);
int strp(line_t instruction);
int ldp(line_t instruction);
int xchg(line_t instruction);
int addi(line_t instruction);
int subi(line_t instruction);
int ori(line_t instruction);
int andi(line_t instruction);
int xori(line_t instruction);
int teqi(line_t instruction);
int tnei(line_t instruction);
int tlti(line_t instruction);
int tlei(line_t instruction);
int tgti(line_t instruction);
int tgei(line_t instruction);
int stri(line_t instruction);
int ldi(line_t instruction);
int jz(line_t instruction);
int jnz(line_t instruction);
int call(line_t instruction);
int ret(line_t instruction);
int jabs(line_t instruction);
// Added _ to avoid conflict with existing keywords

typedef enum binType
{
    R,
    I,
    J
} binType_t;

typedef struct binInstruction
{
    binType_t type;
    union
    {
        struct typeR
        {
            uint8_t opcode;  // 7bits
            uint8_t source2; // 5bits
            uint8_t source;
            uint8_t destination;
        } typeR;
        struct typeI
        {
            uint8_t opcode;    // 6bits
            int16_t immediate; // 16bits
            uint8_t source;    // 5bits
            uint8_t destination;
        } typeI;
        struct typeJ
        {
            uint8_t opcode; // 4bits
            union
            {
                uint32_t addres;
                int16_t immediate;
            };
            uint8_t register_; // 5bits
        } typeJ;
    };
} binInstruction_t;

int write_to_bin(binInstruction_t);
int create_bin();
int execute_instruction(line_t *);

// A switch case to find which operation is being called
int execute_instruction(line_t *instruction)
{
    switch (instruction->mnemonic)
    {
    case SKIP:
        return SUCCESS;
    case ADD:
        add(*instruction);
        return SUCCESS;
    case SUB:
        sub(*instruction);
        return SUCCESS;
    case MUL:
        mul(*instruction);
        return SUCCESS;
    case DIV:
        div_(*instruction);
        return SUCCESS;
    case OR:
        or_(*instruction);
        return SUCCESS;
    case AND:
        and_(*instruction);
        return SUCCESS;
    case XOR:
        xor_(*instruction);
        return SUCCESS;
    case TEQ:
        teq(*instruction);
        return SUCCESS;
    case TNE:
        tne(*instruction);
        return SUCCESS;
    case TLT:
        tlt(*instruction);
        return SUCCESS;
    case TLE:
        tle(*instruction);
        return SUCCESS;
    case TGT:
        tgt(*instruction);
        return SUCCESS;
    case TGE:
        tge(*instruction);
        return SUCCESS;
    case PUSH:
        push(*instruction);
        return SUCCESS;
    case POP:
        pop(*instruction);
        return SUCCESS;
    case STR:
        str(*instruction);
        return SUCCESS;
    case LD:
        ld(*instruction);
        return SUCCESS;
    case STRP:
        strp(*instruction);
        return SUCCESS;
    case LDP:
        ldp(*instruction);
        return SUCCESS;
    case XCHG:
        xchg(*instruction);
        return SUCCESS;
    case ADDI:
        addi(*instruction);
        return SUCCESS;
    case SUBI:
        subi(*instruction);
        return SUCCESS;
    case ORI:
        ori(*instruction);
        return SUCCESS;
    case ANDI:
        andi(*instruction);
        return SUCCESS;
    case XORI:
        add(*instruction);
        return SUCCESS;
    case TEQI:
        teqi(*instruction);
        return SUCCESS;
    case TNEI:
        tnei(*instruction);
        return SUCCESS;
    case TLTI:
        tlti(*instruction);
        return SUCCESS;
    case TLEI:
        tlei(*instruction);
        return SUCCESS;
    case TGTI:
        tgti(*instruction);
        return SUCCESS;
    case TGEI:
        tgei(*instruction);
        return SUCCESS;
    case STRI:
        stri(*instruction);
        return SUCCESS;
    case LDI:
        ldi(*instruction);
        return SUCCESS;
    case CALL:
        call(*instruction);
        return SUCCESS;
    case RET:
        ret(*instruction);
        return SUCCESS;
    default:
        printf("Error : line %llu. Not a valid operation\n", instruction->lineNumber);
        return GENERIC_ERROR;
    }
    return GENERIC_ERROR;
}

// generate .bin
int write_to_bin(binInstruction_t input)
{
    /*FILE* fPtr = fopen(outputFile, "ab");
    if(fPtr == NULL){
        printf("Error: binary file could not be opened");
        return GENERIC_ERROR;
    }

    int8_t firstByte = input.inst | input.isRegister2 << 5;
    firstByte = firstByte | input.isRegister1 << 6;
    firstByte = firstByte | input.isLabel << 7;

    fwrite(&firstByte, sizeof(int8_t), 1, fPtr);
    fwrite(&input.val1, sizeof(int16_t), 1, fPtr);
    fwrite(&input.val2, sizeof(int16_t), 1, fPtr);

    if(fclose(fPtr) != 0){
        printf("Error: binary file could not be closed");
        return GENERIC_ERROR;
    }*/

    return SUCCESS;
}

int create_bin()
{
    FILE *fPtr = fopen(outputFile, "wb");
    if (fPtr == NULL)
    {
        printf("Error: binary file could not be created");
        return GENERIC_ERROR;
    }

    if (fclose(fPtr) != 0)
    {
        printf("Error: binary file could not be closed");
        return GENERIC_ERROR;
    }
    return SUCCESS;
}

// --- Operations ---

int add(line_t instruction)
{
    return GENERIC_ERROR;
}

int sub(line_t instruction)
{
    return GENERIC_ERROR;
}

int mul(line_t instruction)
{
    return GENERIC_ERROR;
}

int div_(line_t instruction)
{
    return GENERIC_ERROR;
}

int or_(line_t instruction)
{
    return GENERIC_ERROR;
}

int and_(line_t instruction)
{
    return GENERIC_ERROR;
}

int xor_(line_t instruction)
{
    return GENERIC_ERROR;
}

int teq(line_t instruction)
{
    return GENERIC_ERROR;
}

int tne(line_t instruction)
{
    return GENERIC_ERROR;
}

int tlt(line_t instruction)
{
    return GENERIC_ERROR;
}

int tle(line_t instruction)
{
    return GENERIC_ERROR;
}

int tgt(line_t instruction)
{
    return GENERIC_ERROR;
}

int tge(line_t instruction)
{
    return GENERIC_ERROR;
}

int push(line_t instruction)
{
    return GENERIC_ERROR;
}

int pop(line_t instruction)
{
    return GENERIC_ERROR;
}

int str(line_t instruction)
{
    return GENERIC_ERROR;
}

int ld(line_t instruction)
{
    return GENERIC_ERROR;
}

int strp(line_t instruction)
{
    return GENERIC_ERROR;
}

int ldp(line_t instruction)
{
    return GENERIC_ERROR;
}

int xchg(line_t instruction)
{
    return GENERIC_ERROR;
}

int addi(line_t instruction)
{
    return GENERIC_ERROR;
}

int subi(line_t instruction)
{
    return GENERIC_ERROR;
}

int ori(line_t instruction)
{
    return GENERIC_ERROR;
}

int andi(line_t instruction)
{
    return GENERIC_ERROR;
}

int xori(line_t instruction)
{
    return GENERIC_ERROR;
}

int teqi(line_t instruction)
{
    return GENERIC_ERROR;
}

int tnei(line_t instruction)
{
    return GENERIC_ERROR;
}

int tlti(line_t instruction)
{
    return GENERIC_ERROR;
}

int tlei(line_t instruction)
{
    return GENERIC_ERROR;
}

int tgti(line_t instruction)
{
    return GENERIC_ERROR;
}

int tgei(line_t instruction)
{
    return GENERIC_ERROR;
}

int stri(line_t instruction)
{
    return GENERIC_ERROR;
}

int ldi(line_t instruction)
{
    return GENERIC_ERROR;
}

int jz(line_t instruction)
{
    return GENERIC_ERROR;
}

int jnz(line_t instruction)
{
    return GENERIC_ERROR;
}

int call(line_t instruction)
{
    return GENERIC_ERROR;
}

int ret(line_t instruction)
{
    return GENERIC_ERROR;
}

int jabs(line_t instruction)
{
    return GENERIC_ERROR;
}

#endif