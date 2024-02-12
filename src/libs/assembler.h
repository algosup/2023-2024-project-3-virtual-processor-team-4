#ifndef COMPILED_H
#define COMPILED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "utils.h"

char* outputFile = "../compiled.bin";

int label(line_t);
int abs_(line_t);
int add(line_t);
int addi(line_t);
int and_(line_t);
int andi(line_t);
int b(line_t);
int bi(line_t);
int bnz(line_t);
int bz(line_t);
int call(line_t);
int calli(line_t);
int div_(line_t);
int jmp(line_t);
int ld(line_t);
int ldi(line_t);
int ldp(line_t);
int mul(line_t);
int or_(line_t);
int ori(line_t);
int pop(line_t);
int push(line_t);
int ret(line_t);
int set(line_t);
int str(line_t);
int stri(line_t);
int strp(line_t);
int sub(line_t);
int subi(line_t);
int teq(line_t);
int teqi(line_t);
int tge(line_t);
int tgei(line_t);
int tgt(line_t);
int tgti(line_t);
int tle(line_t);
int tlei(line_t);
int tlt(line_t);
int tlti(line_t);
int tne(line_t);
int tnei(line_t);
int xchg(line_t);
int xor_(line_t);
int xori(line_t);
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
            union
            {
                uint32_t addres;
                int16_t immediate;
            };
            uint8_t register_; //5bits
        }typeJ;
    };
} binInstruction_t;

listLabel_t labelList = {NULL, 0, NULL};
uint32_t machineCodeLine = 0;
bool firstPass;

int write_to_bin(binInstruction_t);
int create_bin();

int push_to_stack(stack_t*, line_t);
int pop_from_stack(stack_t*, line_t*);
int find_register(char*, int*);
int execute_instruction(line_t*);
int label_to_int(char*, uint32_t*);

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
        if(strcmp(label.labelStr, labelStr) == 0){
            *lineOut = label.line;
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
        if(firstPass == true){
            return label(*instruction);
        }else{
            return SUCCESS;
        }
    case ABS:
        return abs_(*instruction);
    case ADD:
        return add(*instruction);
    case ADDI:
        return addi(*instruction);
    case AND:
        return and_(*instruction);
    case ANDI:
        return andi(*instruction);
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
        return div_(*instruction);
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
    if(firstPass == false){
        FILE* fPtr = fopen(outputFile, "ab");
        if(fPtr == NULL){
            printf("Error: binary file could not be opened\n");
            return GENERIC_ERROR;
        }

        // 4 8bit to make a 32bit instruction.
        unsigned char byteArr[4] = {0, 0, 0, 0};

        //big blocks of byteshift to organise the bytes for the machine code
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
    }else{
        machineCodeLine++;
    }
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

ErrorType_t check_type_R(line_t instruction, binInstruction_t* bin, InstructionType_t inst, uint8_t opcode){
    bool error = false;

    bin->type = R;
    if(instruction.mnemonic == inst){
        bin->typeR.opcode = opcode;
    }else{
        printf("Error: Invalide data in assembler. Mnemonic without opcode\n");
        return INVALID_DATA;
    }

    if(instruction.dest < 32 && instruction.dest >= 0 && instruction.dest_t == REGISTER){
        bin->typeR.destination = instruction.dest;
    }else if (instruction.dest_t == NULL_){
        bin->typeI.destination = 0;
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

ErrorType_t check_type_I(line_t instruction, binInstruction_t* bin, InstructionType_t inst, uint8_t opcode){
    bool error = false;

    bin->type = I;
    if(instruction.mnemonic == inst){
        bin->typeI.opcode = opcode;
    }else{
        printf("Error: Invalide data in assembler. Mnemonic without opcode\n");
        return INVALID_DATA;
    }

    if(instruction.dest < 32 && instruction.dest >= 0 && instruction.dest_t == REGISTER){
        bin->typeI.destination = instruction.dest;
    }else if (instruction.dest_t == NULL_){
        bin->typeI.destination = 0;
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

ErrorType_t check_type_J(line_t instruction, binInstruction_t* bin, InstructionType_t inst, uint8_t opcode){
    bool error = false;

    bin->type = J;

    if(instruction.mnemonic == inst){
        bin->typeI.opcode = opcode;
    }else{
        printf("Error: Invalide data in assembler. Mnemonic without opcode\n");
        return INVALID_DATA;
    }

    bool isImmediate = false;
    if(instruction.param2_t == IMMEDIATE){
        isImmediate = true;
    }

    if(instruction.dest < 32 && instruction.dest >= 0 && instruction.dest_t == REGISTER){
        bin->typeJ.register_ = instruction.dest;
    }else if (instruction.dest_t == NULL_){
        bin->typeI.destination = 0;
    }else{
        printf("Error: Invalid destination register. Line %d\n", instruction.lineNumber);
        error = true;
    }

    uint32_t addres;
    if((instruction.immediate2 < 32768 && instruction.immediate2 >= -32768) && isImmediate){
        bin->typeJ.immediate = instruction.immediate2;
    }else if(label_to_int(instruction.label, &addres) == SUCCESS && !isImmediate){
        bin->typeJ.addres = addres;
    }
    else{
        error = true;
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

int abs_(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_R(instruction, &bin, ABS, 7);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int add(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_R(instruction, &bin, ADD, 0);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int addi(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_I(instruction, &bin, ADDI, 16);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int and_(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_R(instruction, &bin, AND, 5);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int andi(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_I(instruction, &bin, ANDI, 21);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int b(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_J(instruction, &bin, B, 8);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int bi(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_J(instruction, &bin, BI, 9);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int bnz(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_J(instruction, &bin, BNZ, 11);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int bz(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_J(instruction, &bin, BNZ, 10);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int call(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_J(instruction, &bin, CALL, 12);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int calli(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_J(instruction, &bin, BNZ, 11);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int div_(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_R(instruction, &bin, DIV, 3);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int jmp(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_J(instruction, &bin, BNZ, 11);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int ld(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_R(instruction, &bin, LD, 17);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int ldi(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_I(instruction, &bin, LDI, 19);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int ldp(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_R(instruction, &bin, LDP, 19);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int mul(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_R(instruction, &bin, MUL, 2);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int or_(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_R(instruction, &bin, OR, 4);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int ori(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_I(instruction, &bin, ORI, 20);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int pop(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_R(instruction, &bin, POP, 21);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int push(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_R(instruction, &bin, PUSH, 20);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int ret(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_J(instruction, &bin, BNZ, 11);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int set(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_I(instruction, &bin, SET, 23);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int str(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_R(instruction, &bin, STR, 16);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int stri(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_I(instruction, &bin, STRI, 18);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int strp(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_R(instruction, &bin, STRP, 18);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int sub(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_R(instruction, &bin, SUB, 1);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int subi(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_I(instruction, &bin, SUBI, 17);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int teq(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_R(instruction, &bin, TEQ, 12);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int teqi(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_I(instruction, &bin, TEQI, 28);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int tge(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_R(instruction, &bin, TGE, 11);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int tgei(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_I(instruction, &bin, TGEI, 27);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int tgt(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_R(instruction, &bin, TGT, 10);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int tgti(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_I(instruction, &bin, TGTI, 26);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int tle(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_R(instruction, &bin, TLE, 9);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int tlei(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_I(instruction, &bin, TLEI, 25);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int tlt(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_R(instruction, &bin, TLT, 8);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int tlti(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_I(instruction, &bin, TLTI, 24);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int tne(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_R(instruction, &bin, TNE, 13);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int tnei(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_I(instruction, &bin, TNEI, 29);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int xchg(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_R(instruction, &bin, XCHG, 22);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int xor_(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_R(instruction, &bin, XOR, 6);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

int xori(line_t instruction){
    binInstruction_t bin;
    ErrorType_t err = check_type_I(instruction, &bin, XORI, 22);
    if(err != SUCCESS){
        return err;
    }
    return write_to_bin(bin);
}

#endif