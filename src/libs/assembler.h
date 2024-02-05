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

int label(line_t instruction);
int abs(line_t instruction);
int add(line_t instruction);
int addi(line_t instruction);
int and_(line_t instruction);
int b(line_t instruction);
int bi(line_t instruction);
int bnz(line_t instruction);
int bz(line_t instruction);
int call(line_t instruction);
int calli(line_t instruction);
int div(line_t instruction);
int jmp(line_t instruction);
int ld(line_t instruction);
int ldi(line_t instruction);
int ldp(line_t instruction);
int mul(line_t instruction);
int or_(line_t instruction);
int ori(line_t instruction);
int pop(line_t instruction);
int push(line_t instruction);
int ret(line_t instruction);
int set(line_t instruction);
int str(line_t instruction);
int stri(line_t instruction);
int strp(line_t instruction);
int sub(line_t instruction);
int subi(line_t instruction);
int teq(line_t instruction);
int teqi(line_t instruction);
int tge(line_t instruction);
int tgei(line_t instruction);
int tgt(line_t instruction);
int tgti(line_t instruction);
int tle(line_t instruction);
int tlei(line_t instruction);
int tlt(line_t instruction);
int tlti(line_t instruction);
int tne(line_t instruction);
int tnei(line_t instruction);
int xchg(line_t instruction);
int xor_(line_t instruction);
int xori(line_t instruction);
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
            uint32_t addres; //23bits
            uint8_t register_; //5bits
        }typeJ;
    };
} binInstruction_t;

listLabel_t labelList = {NULL, 0, NULL};
uint32_t machineCodeLine = 0;

int write_to_bin(binInstruction_t);
int create_bin();

int push_to_stack(stack_t*, line_t);
int pop_from_stack(stack_t*, line_t*);
int find_register(char*, int*);
int execute_instruction(line_t*);
int label_to_int(char*, uint32_t*);

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

//A function to translate labels to int.
int label_to_int(char* labelStr, uint32_t* lineOut){
    char str[256];
    label_t label = {0, str};

    for (int i = 0; i < labelList.size; i++)
    {
        get_list_str(&labelList, &label, i);
        if(strcmp(&label.labelStr, labelStr) == 0){
            lineOut = label.line;
            return SUCCESS;
        }
    }

    printf("Error: undefined label \"%s\"\n", labelStr);
    return GENERIC_ERROR;
}

// A switch case to find which operation is being called
int execute_instruction(line_t *instruction)
{
    switch (instruction->mnemonic)
    {
    case SKIP:
        return SUCCESS;
    case LABEL_:
        return label(*instruction);
    case ABS:
        return abs(*instruction);
    case ADD:
        return add(*instruction);
    case ADDI:
        return addi(*instruction);
    case AND:
        return and_(*instruction);
    case B:
        return b(*instruction);
    case BI:
        return bi(*instruction);
    case BNZ:
        return bnz(*instruction);
    case BZ:
        return bz(*instruction);
    case CALL:
        return call(*instruction);
    case CALLI:
        return calli(*instruction);
    case DIV:
        return div(*instruction);
    case JMP:
        return jmp(*instruction);
    case LD:
        return ld(*instruction);
    case LDI:
        return ldi(*instruction);
    case LDP:
        return ldp(*instruction);
    case MUL:
        return mul(*instruction);
    case OR:
        return or_(*instruction);
    case ORI:
        return ori(*instruction);
    case POP:
        return pop(*instruction);
    case PUSH:
        return push(*instruction);
    case RET:
        return ret(*instruction);
    case SET:
        return set(*instruction);
    case STR:
        return str(*instruction);
    case STRI:
        return stri(*instruction);
    case STRP:
        return strp(*instruction);
    case SUB:
        return sub(*instruction);
    case SUBI:
        return subi(*instruction);
    case TEQ:
        return teq(*instruction);
    case TEQI:
        return teqi(*instruction);
    case TGE:
        return tge(*instruction);
    case TGEI:
        return tgei(*instruction);
    case TGT:
        return tgt(*instruction);
    case TGTI:
        return tgti(*instruction);
    case TLE:
        return tle(*instruction);
    case TLEI:
        return tlei(*instruction);
    case TLT:
        return tlt(*instruction);
    case TLTI:
        return tlti(*instruction);
    case TNE:
        return tne(*instruction);
    case TNEI:
        return tnei(*instruction);
    case XCHG:
        return xchg(*instruction);
    case XOR:
        return xor_(*instruction);
    case XORI:
        return xori(*instruction);
    
    default:
        printf("Error : line %d. Not a valid operation\n", instruction->lineNumber);
        return GENERIC_ERROR;
    }
    return GENERIC_ERROR;
}


int write_to_bin(binInstruction_t input){
    FILE* fPtr = fopen(outputFile, "ab");
    if(fPtr == NULL){
        printf("Error: binary file could not be opened\n");
        return GENERIC_ERROR;
    }

    // 4 8bit to make a 32bit instruction.
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
        printf("Error: writing binary file. Invalid input\n");
        return INVALID_DATA;
        break;
    }

    for (int i = 0; i < 4; i++) {
        fwrite(&byteArr[i], sizeof(int8_t), 1, fPtr);
    }

    if(fclose(fPtr) != 0){
        printf("Error: binary file could not be closed\n");
        return GENERIC_ERROR;
    }

    machineCodeLine++;
    return SUCCESS;
}

int create_bin(){
    FILE* fPtr = fopen(outputFile, "wb");
    if(fPtr == NULL){
        printf("Error: binary file could not be created\n");
        return GENERIC_ERROR;
    }

    if(fclose(fPtr) != 0){
        printf("Error: binary file could not be closed\n");
        return GENERIC_ERROR;
    }
}

int check_type_R(line_t instruction, binInstruction_t* bin){
    bool error = false;
    if(instruction.dest < 32 && instruction.dest >= 0){
        bin->typeR.destination = instruction.dest;
    }else{
        printf("Error: Invalid destination register. Line %d\n", instruction.lineNumber);
        error = true;
    }
    if(instruction.param1 < 32 && instruction.param1 >= 0){
        bin->typeR.source = instruction.param1;
    }else{
        printf("Error: Invalid 1st register. Line %d\n", instruction.lineNumber);
        error = true;
    }
    if(instruction.register2 < 32 && instruction.register2 >= 0){
            bin->typeR.source2 = instruction.register2;
    }else{
        printf("Error: Invalid 2nd register. Line %d\n", instruction.lineNumber);
        error = true;
    }
    if(error == false){
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int check_type_I(line_t instruction, binInstruction_t* bin){
    bool error = false;
    if(instruction.dest < 32 && instruction.dest >= 0){
        bin->typeI.destination = instruction.dest;
    }else{
        printf("Error: Invalid destination register. Line %d\n", instruction.lineNumber);
        error = true;
    }
    if(instruction.param1 < 32 && instruction.param1 >= 0){
        bin->typeI.source = instruction.param1;
    }else{
        printf("Error: Invalid register. Line %d\n", instruction.lineNumber);
        error = true;
    }
    if(instruction.immediate2 < 32768 && instruction.immediate2 >= -32768){
            bin->typeI.immediate = instruction.immediate2;
    }else{
        printf("Error: Invalid immediate. Line %d\n", instruction.lineNumber);
        error = true;
    }
    if(error == false){
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int check_type_J(line_t instruction, binInstruction_t* bin){
    bool error = false;
    if(instruction.dest < 32 && instruction.dest >= 0){
        bin->typeJ.register_ = instruction.dest;
    }else{
        printf("Error: Invalid destination register. Line %d\n", instruction.lineNumber);
        error = true;
    }

    uint32_t addres;
    if(label_to_int(instruction.label, &addres) != SUCCESS){
        error = true;
    }else{
        bin->typeJ.addres = addres;
    }

    if(error == false){
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

// --- Operations ---

int label(line_t instruction){
    if(instruction.mnemonic != LABEL_){
        printf("Error: invalid instruction at line %d", instruction.lineNumber);
        return INVALID_DATA;
    }

    if (labelList.size >= 8388607)
    {
        printf("Error: exceeded maximum amount of possible labels (8388607)\n");
        return GENERIC_ERROR;
    }else{
        label_t label = {machineCodeLine, instruction.label};
        add_to_list_str(&labelList, label);
        return SUCCESS;
    }
}

int abs(line_t instruction){
    return GENERIC_ERROR;
}

int add(line_t instruction){
    binInstruction_t bin;
    bin.type = R;
    if(instruction.mnemonic == ADD){
        bin.typeR.opcode = 0;
    }else{
        printf("Error: Invalide data in assembler. Mnemonic without opcode\n");
        return INVALID_DATA;
    }
    if(check_type_R(instruction, &bin) != SUCCESS){
        return GENERIC_ERROR;
    }

    return write_to_bin(bin);
}

int addi(line_t instruction){
    binInstruction_t bin;
    bin.type = I;
    if(instruction.mnemonic == ADDI){
        bin.typeI.opcode = 16;
    }else{
        printf("Error: Invalide data in assembler. Mnemonic without opcode\n");
        return INVALID_DATA;
    }
    if(check_type_I(instruction, &bin) != SUCCESS){
        return GENERIC_ERROR;
    }

    return write_to_bin(bin);
}

int and_(line_t instruction){
    return GENERIC_ERROR;
}

int b(line_t instruction){
    return GENERIC_ERROR;
}

int bi(line_t instruction){
    return GENERIC_ERROR;
}

int bnz(line_t instruction){
    return GENERIC_ERROR;
}

int bz(line_t instruction){
    return GENERIC_ERROR;
}

int call(line_t instruction){
    binInstruction_t bin;
    bin.type = J;
    if(instruction.mnemonic == CALL){
        bin.typeI.opcode = 12;
    }else{
        printf("Error: Invalide data in assembler. Mnemonic without opcode\n");
        return INVALID_DATA;
    }
    if(check_type_J(instruction, &bin) != SUCCESS){
        return GENERIC_ERROR;
    }

    return write_to_bin(bin);
}

int calli(line_t instruction){
    return GENERIC_ERROR;
}

int div(line_t instruction){
    return GENERIC_ERROR;
}

int jmp(line_t instruction){
    return GENERIC_ERROR;
}

int ld(line_t instruction){
    return GENERIC_ERROR;
}

int ldi(line_t instruction){
    return GENERIC_ERROR;
}

int ldp(line_t instruction){
    return GENERIC_ERROR;
}

int mul(line_t instruction){
    return GENERIC_ERROR;
}

int or_(line_t instruction){
    return GENERIC_ERROR;
}

int ori(line_t instruction){
    return GENERIC_ERROR;
}

int pop(line_t instruction){
    return GENERIC_ERROR;
}

int push(line_t instruction){
    return GENERIC_ERROR;
}

int ret(line_t instruction){
    return GENERIC_ERROR;
}

int set(line_t instruction){
    return GENERIC_ERROR;
}

int str(line_t instruction){
    return GENERIC_ERROR;
}

int stri(line_t instruction){
    return GENERIC_ERROR;
}

int strp(line_t instruction){
    return GENERIC_ERROR;
}

int sub(line_t instruction){
    return GENERIC_ERROR;
}

int subi(line_t instruction){
    return GENERIC_ERROR;
}

int teq(line_t instruction){
    return GENERIC_ERROR;
}

int teqi(line_t instruction){
    return GENERIC_ERROR;
}

int tge(line_t instruction){
    return GENERIC_ERROR;
}

int tgei(line_t instruction){
    return GENERIC_ERROR;
}

int tgt(line_t instruction){
    return GENERIC_ERROR;
}

int tgti(line_t instruction){
    return GENERIC_ERROR;
}

int tle(line_t instruction){
    return GENERIC_ERROR;
}

int tlei(line_t instruction){
    return GENERIC_ERROR;
}

int tlt(line_t instruction){
    return GENERIC_ERROR;
}

int tlti(line_t instruction){
    return GENERIC_ERROR;
}

int tne(line_t instruction){
    return GENERIC_ERROR;
}

int tnei(line_t instruction){
    return GENERIC_ERROR;
}

int xchg(line_t instruction){
    return GENERIC_ERROR;
}

int xor_(line_t instruction){
    return GENERIC_ERROR;
}

int xori(line_t instruction){
    return GENERIC_ERROR;
}

#endif