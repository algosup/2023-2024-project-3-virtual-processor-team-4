#ifndef COMPILED_H
#define COMPILED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "utils.h"

char* outputFile = "../compiled.bin";

typedef struct stackNode
{ // Item of linked list
    struct stackNode *previous;
    line_t val;
} stackNode_t;

typedef struct stack
{ // Linked list = stack
    stackNode_t *head;
    unsigned int size;
} stack_t;

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
            int8_t opcode; //7bits
            int8_t source2; //5bits
            int8_t source;
            int8_t destination;
        }typeR;
        struct typeI
        {
            int8_t opcode; //6bits
            int16_t immediate; //16bits
            int8_t source; //5bits
            int8_t destination;
        }typeI;
        struct typeJ
        {
            int8_t opcode; //4bits
            int32_t addres; //23bits
            int8_t register_; //5bits
        }typeJ;
    };
} binInstruction_t;


int write_to_bin(binInstruction_t);
int create_bin();

int push_to_stack(stack_t*, line_t);
int pop_from_stack(stack_t*, line_t*);
int find_register(char*, int*);
int execute_instruction(line_t*);

// --- Stack ---

int push_to_stack(stack_t *pStack, line_t value)
{
    if (pStack->head == NULL)
    {
        stackNode_t node = {NULL, value};
        stackNode_t *p = (stackNode_t *)malloc(sizeof(stackNode_t));
        memcpy(p, &node, sizeof(stackNode_t));
        pStack->size++;
        pStack->head = p;
    }
    else
    {
        stackNode_t node = {NULL, value};
        stackNode_t *p = (stackNode_t *)malloc(sizeof(stackNode_t));
        memcpy(p, &node, sizeof(stackNode_t));
        pStack->size++;
        pStack->head->previous = p;
        pStack->head = p;
    }
    return EXIT_SUCCESS;
}

int pop_from_stack(stack_t *pStack, line_t *value)
{
    if (pStack->head == NULL)
    {
        return EXIT_FAILURE;
    }
    else if (pStack->size == 1)
    {
        *value = pStack->head->val;
        free(pStack->head);
        pStack->size--;
        pStack->head = NULL;
    }
    else
    {
        *value = pStack->head->val;
        free(pStack->head);
        pStack->size--;
        pStack->head->previous = NULL;
    }
    return EXIT_SUCCESS;
}

// --- manipulate register ---

int find_register(char *inString, int *registerIndex)
{
    if(strlen(inString) != 2){
        return INVALID_DATA;
    }

    char str2[3];
    strcpy(str2, inString);
    char *ptr = str2;
    ptr++;

    if((*ptr >= '0' && *ptr <= '9') || (*ptr >= 'A' && *ptr <= 'F') || (*ptr >= 'a' && *ptr <= 'f')){
        *registerIndex = (int)strtol(ptr, NULL, 16);
        return SUCCESS;
    }else{
        return INVALID_DATA;
    }
};

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
    case JZ:
        jz(*instruction);
        return SUCCESS;
    case JNZ:
        jnz(*instruction);
        return SUCCESS;
    case CALL:
        call(*instruction);
        return SUCCESS;
    case RET:
        ret(*instruction);
        return SUCCESS;
    case JABS:
        jabs(*instruction);
        return SUCCESS;
    default:
        printf("Error : line %d. Not a valid operation\n", instruction->lineNumber);
        return GENERIC_ERROR;
    }
    return GENERIC_ERROR;
}

//generate .bin
int write_to_bin(binInstruction_t input){
    FILE* fPtr = fopen(outputFile, "ab");
    if(fPtr == NULL){
        printf("Error: binary file could not be opened");
        return GENERIC_ERROR;
    }

    unsigned char byteArr[4] = {0, 0, 0, 0};

    switch (input.type)
    {
    case R:
        byteArr[0] = byteArr[0] | input.typeR.opcode << 1;
        byteArr[2] = byteArr[2] | input.typeR.source2 << 2;
        byteArr[2] = byteArr[2] | input.typeR.source >> 3;
        byteArr[3] = byteArr[3] | input.typeR.source << 5;
        byteArr[3] = byteArr[3] | input.typeR.destination;
        break;
    case I:
        byteArr[0] = byteArr[0] | input.typeI.opcode << 2;
        byteArr[0] = byteArr[0] | input.typeI.immediate >> 14;
        byteArr[1] = byteArr[1] | input.typeI.immediate >> 6;
        byteArr[2] = byteArr[2] | input.typeI.immediate << 2;
        byteArr[2] = byteArr[2] | input.typeI.source >> 3;
        byteArr[3] = byteArr[3] | input.typeI.source << 5;
        byteArr[3] = byteArr[3] | input.typeI.destination;
        break;
    case J:
        byteArr[0] = byteArr[0] | input.typeJ.opcode << 4;
        byteArr[0] = byteArr[0] | input.typeJ.addres >> 19;
        byteArr[1] = byteArr[1] | input.typeJ.addres >> 11;
        byteArr[2] = byteArr[2] | input.typeJ.addres >> 3;
        byteArr[3] = byteArr[3] | input.typeJ.addres << 5;
        byteArr[3] = byteArr[3] | input.typeJ.register_;
        break;
    default:
        printf("Error: writing binary file. Invalid input");
        return INVALID_DATA;
        break;
    }

    for (int i = 0; i < 4; i++) {
        fwrite(&byteArr[i], sizeof(int8_t), 1, fPtr);
    }

    if(fclose(fPtr) != 0){
        printf("Error: binary file could not be closed");
        return GENERIC_ERROR;
    }

    return SUCCESS;
}

int create_bin(){
    FILE* fPtr = fopen(outputFile, "wb");
    if(fPtr == NULL){
        printf("Error: binary file could not be created");
        return GENERIC_ERROR;
    }

    if(fclose(fPtr) != 0){
        printf("Error: binary file could not be closed");
        return GENERIC_ERROR;
    }
}


// --- Operations ---

int add(line_t instruction){
    binInstruction_t bin;
    bin.type = R;
    bin.typeR.opcode = SUB;
    bin.typeR.destination = instruction.dest;
    bin.typeR.source = instruction.param1;
    bin.typeR.source2 = instruction.register2;

    write_to_bin(bin);

    return GENERIC_ERROR;
}

int sub(line_t instruction){
    return GENERIC_ERROR;
}

int mul(line_t instruction){
    return GENERIC_ERROR;
}

int div_(line_t instruction){
    return GENERIC_ERROR;
}

int or_(line_t instruction){
    return GENERIC_ERROR;
}

int and_(line_t instruction){
    return GENERIC_ERROR;
}

int xor_(line_t instruction){
    return GENERIC_ERROR;
}

int teq(line_t instruction){
    return GENERIC_ERROR;
}

int tne(line_t instruction){
    return GENERIC_ERROR;
}

int tlt(line_t instruction){
    return GENERIC_ERROR;
}

int tle(line_t instruction){
    return GENERIC_ERROR;
}

int tgt(line_t instruction){
    return GENERIC_ERROR;
}

int tge(line_t instruction){
    return GENERIC_ERROR;
}

int push(line_t instruction){
    return GENERIC_ERROR;
}

int pop(line_t instruction){
    return GENERIC_ERROR;
}

int str(line_t instruction){
    return GENERIC_ERROR;
}

int ld(line_t instruction){
    return GENERIC_ERROR;
}

int strp(line_t instruction){
    return GENERIC_ERROR;
}

int ldp(line_t instruction){
    return GENERIC_ERROR;
}

int xchg(line_t instruction){
    return GENERIC_ERROR;
}

int addi(line_t instruction){
    binInstruction_t bin;
    bin.type = I;
    bin.typeI.opcode = ADDI;
    bin.typeI.destination = instruction.dest;
    bin.typeI.source = instruction.param1;
    bin.typeI.immediate = instruction.immediate2;

    write_to_bin(bin);

    return GENERIC_ERROR;
}

int subi(line_t instruction){
    return GENERIC_ERROR;
}

int ori(line_t instruction){
    return GENERIC_ERROR;
}

int andi(line_t instruction){
    return GENERIC_ERROR;
}

int xori(line_t instruction){
    return GENERIC_ERROR;
}

int teqi(line_t instruction){
    return GENERIC_ERROR;
}

int tnei(line_t instruction){
    return GENERIC_ERROR;
}

int tlti(line_t instruction){
    return GENERIC_ERROR;
}

int tlei(line_t instruction){
    return GENERIC_ERROR;
}

int tgti(line_t instruction){
    return GENERIC_ERROR;
}

int tgei(line_t instruction){
    return GENERIC_ERROR;
}

int stri(line_t instruction){
    return GENERIC_ERROR;
}

int ldi(line_t instruction){
    return GENERIC_ERROR;
}

int jz(line_t instruction){
    return GENERIC_ERROR;
}

int jnz(line_t instruction){
    return GENERIC_ERROR;
}

int call(line_t instruction){
    binInstruction_t bin;
    bin.type = J;
    bin.typeJ.opcode = CALL ;
    bin.typeJ.register_ = instruction.dest;
    bin.typeJ.addres = 8388607;

    write_to_bin(bin);

    return GENERIC_ERROR;
}

int ret(line_t instruction){
    return GENERIC_ERROR;
}

int jabs(line_t instruction){
    return GENERIC_ERROR;
}

#endif