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

int write_to_bin(binInstruction_t);
int create_bin();

int push_to_stack(stack_t*, line_t);
int pop_from_stack(stack_t*, line_t*);
int execute_instruction(line_t*);
int find_label_line(char*, uint32_t*);
int get_labels(line_t*, uint64_t);
int iterate_through_all_line(line_t*, uint64_t);

int iterate_through_all_line(line_t* instructions, uint64_t arrSize){
    ErrorType_t er = create_bin();
    if(er != SUCCESS){
        return er;
    }
    er = get_labels(instructions, arrSize);
    if(er != SUCCESS){
        return er;
    }

    bool error = false;
    for (int i = 0; i < arrSize; i++)
    {
        if(execute_instruction(&instructions[i]) != SUCCESS){
            error = true;
        };
    }

    if(error == false){
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
};

// --- manipulate Labels ---

//A function to translate labels to int.
int find_label_line(char* labelStr, uint32_t* lineOut){
    char** str;
    label_t label = {0, str};

    for (int i = 0; i < labelList.size; i++)
    {
        get_list_label(&labelList, &label, i);
        if(strcmp(*label.labelStr, labelStr) == 0){
            *lineOut = label.line;
            return SUCCESS;
        }
    }

    printf("Error: undefined label \"%s\"\n", labelStr);
    return GENERIC_ERROR;
}

//iterate through the list of instruction to get label and the places they jump to
int get_labels(line_t* instructions, uint64_t arrSize){
    int machineCodeLineNumber = 0;

    for(int i = 0; i < arrSize; i++){
        if(instructions[i].mnemonic == LABEL_){
            label_t tmp = {machineCodeLineNumber+1, &instructions[i].label};
            add_to_list_label(&labelList, tmp);
        }else if(instructions[i].mnemonic != SKIP){
            machineCodeLineNumber++;
            instructions[i].lineNumber = machineCodeLineNumber;
        }
    }

    return SUCCESS;
}

// A switch case to find which operation is being called
int execute_instruction(line_t *instruction)
{
    switch (instruction->mnemonic)
    {
    case SKIP:
        return SUCCESS;
    case LABEL_:
        return SUCCESS;
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
        error = true;
    }

    if(instruction.param2_t == NULL_){
        bin->typeR.destination = instruction.dest;
        bin->typeR.source = instruction.dest;

        if(instruction.param1_t == REGISTER){
            bin->typeR.source2 = instruction.register1;
        }else{
            printf("Error: Invalide data in assembler. Expected Register at line %d\n", instruction.lineNumber);
            error = true;
        }
    }else{
        bin->typeR.destination = instruction.dest;

        if(instruction.param1_t == REGISTER){
            bin->typeR.source = instruction.register1;
        }else{
            printf("Error: Invalide data in assembler. Expected Register at line %d\n", instruction.lineNumber);
            error = true;
        }

        if(instruction.param2_t == REGISTER){
            bin->typeR.source2 = instruction.register2;
        }else{
            printf("Error: Invalide data in assembler. Expected Register at line %d\n", instruction.lineNumber);
            error = true;
        }
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
        error = true;
    }

    if(instruction.param2_t == NULL_){
        bin->typeI.destination = instruction.dest;
        bin->typeI.source = instruction.dest;

        if(instruction.param1_t == IMMEDIATE){
            bin->typeI.immediate = instruction.immediate1;
        }else{
            printf("Error: Invalide data in assembler. Expected Immediate at line %d\n", instruction.lineNumber);
            error = true;
        }
    }else{
        bin->typeI.destination = instruction.dest;

        if(instruction.param1_t == REGISTER){
            bin->typeI.source = instruction.register1;
        }else{
            printf("Error: Invalide data in assembler. Expected Register at line %d\n", instruction.lineNumber);
            error = true;
        }

        if(instruction.param2_t == IMMEDIATE){
            bin->typeI.immediate = instruction.immediate2;
        }else{
            printf("Error: Invalide data in assembler. Expected Immediate at line %d\n", instruction.lineNumber);
            error = true;
        }
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
        error = true;
    }

    if(instruction.dest_t == NULL_){
        bin->typeJ.register_ == 0;
    }else if(instruction.dest_t == REGISTER){
        bin->typeJ.register_ == instruction.dest;
    }else{
        printf("Error: Invalid destination register. Line %d\n", instruction.lineNumber);
        error = true;
    }

    uint32_t addres;
    if(instruction.param1_t == LABEL){
        if(find_label_line(instruction.label1, &addres) != SUCCESS){
            error = true;
        }else{
            addres = addres - instruction.lineNumber;
        }
    }else if (instruction.param1_t = IMMEDIATE)
    {
        addres = instruction.immediate1;
    }else if (instruction.param1_t = NULL_){
        addres = 0;
    }else{
        error = true;
        printf("Error: Invalid Label or Imediate. Line %d\n", instruction.lineNumber);
    }

    bin->typeJ.addres = addres;

    if(error == false){
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

// --- Operations ---

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