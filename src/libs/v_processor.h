#ifndef V_PROCESSOR_H
#define V_PROCESSOR_H


//__________________________________________________________________________________________________
//  VIRTUAL COMPONENTS
//_____________________

#include "memory.h"

uint32_t registerArr[32];     // the 32 registers

// No flags
//__________________________________________________________________________________________________


//__________________________________________________________________________________________________
//  VIRTUAL INSTRUCTIONS PROTOTYPES
//_____________________

int add(binInstruction_t instruction);
int sub(binInstruction_t instruction);
int mul(binInstruction_t instruction);
//                                     int div(binInstruction_t instruction);
int or(binInstruction_t instruction);
int and(binInstruction_t instruction);
int xor(binInstruction_t instruction);
//                                     int abs(binInstruction_t instruction);
int tlt(binInstruction_t instruction);
int tle(binInstruction_t instruction);
int tgt(binInstruction_t instruction);
int tge(binInstruction_t instruction);
int teq(binInstruction_t instruction);
int tne(binInstruction_t instruction);
int str(binInstruction_t instruction);
int ld(binInstruction_t instruction);
int strp(binInstruction_t instruction);
int ldp(binInstruction_t instruction);
int push(binInstruction_t instruction);
int pop(binInstruction_t instruction);
int xchg(binInstruction_t instruction);
int addi(binInstruction_t instruction);
int subi(binInstruction_t instruction);
int stri(binInstruction_t instruction);
int ldi(binInstruction_t instruction);
int ori(binInstruction_t instruction);
int andi(binInstruction_t instruction);
int xori(binInstruction_t instruction);
int set(binInstruction_t instruction);
int tlti(binInstruction_t instruction);
int tlei(binInstruction_t instruction);
int tgti(binInstruction_t instruction);
int tgei(binInstruction_t instruction);
int teqi(binInstruction_t instruction);
int tnei(binInstruction_t instruction);
int b(binInstruction_t instruction);
int bi(binInstruction_t instruction);
int bz(binInstruction_t instruction);
int bnz(binInstruction_t instruction);
int call(binInstruction_t instruction);
int calli(binInstruction_t instruction);
int ret(binInstruction_t instruction);
int jmp(binInstruction_t instruction);

//__________________________________________________________________________________________________
//  VIRTUAL INSTRUCTIONS IMPLEMENTATION
//_____________________

int add(binInstruction_t instruction)
{
    registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source] + registerArr[instruction.typeR.source2];
    return SUCCESS;
}


int sub(binInstruction_t instruction)
{
    registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source] - registerArr[instruction.typeR.source2];
    return SUCCESS;
}

int mul(binInstruction_t instruction)
{
    registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source] * registerArr[instruction.typeR.source2];
    return SUCCESS;
}

int div_(binInstruction_t instruction)
{
    registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source] / registerArr[instruction.typeR.source2];
    return SUCCESS;
}

int or(binInstruction_t instruction)
{
    registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source] | registerArr[instruction.typeR.source2];
    return SUCCESS;
}

int and(binInstruction_t instruction)
{
    registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source] & registerArr[instruction.typeR.source2];
    return SUCCESS;
}

int xor(binInstruction_t instruction)
{
    registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source] ^ registerArr[instruction.typeR.source2];
    return SUCCESS;
}

int abs_(binInstruction_t instruction)
{
    registerArr[instruction.typeR.destination] = abs(registerArr[instruction.typeR.source]);
    return SUCCESS;
}

int tlt(binInstruction_t instruction)
{
    if (registerArr[instruction.typeR.source] < registerArr[instruction.typeR.source2]){
        registerArr[instruction.typeR.destination] = 1;
    }else{
        registerArr[instruction.typeR.destination] = 0;
    }
    return SUCCESS;
}

int tle(binInstruction_t instruction)
{
    if (registerArr[instruction.typeR.source] <= registerArr[instruction.typeR.source2]){
        registerArr[instruction.typeR.destination] = 1;
    }else{
        registerArr[instruction.typeR.destination] = 0;
    }
    return SUCCESS;
}

int tgt(binInstruction_t instruction)
{
    if (registerArr[instruction.typeR.source] > registerArr[instruction.typeR.source2]){
        registerArr[instruction.typeR.destination] = 1;
    }else{
        registerArr[instruction.typeR.destination] = 0;
    }
    return SUCCESS;
}

int tge(binInstruction_t instruction)
{
    if (registerArr[instruction.typeR.source] >= registerArr[instruction.typeR.source2]){
        registerArr[instruction.typeR.destination] = 1;
    }else{
        registerArr[instruction.typeR.destination] = 0;
    }
    return SUCCESS;
}

int teq(binInstruction_t instruction)
{
    if (registerArr[instruction.typeR.source] == registerArr[instruction.typeR.source2]){
        registerArr[instruction.typeR.destination] = 1;
    }else{
        registerArr[instruction.typeR.destination] = 0;
    }
    return SUCCESS;
}

int tne(binInstruction_t instruction)
{
    if (registerArr[instruction.typeR.source] != registerArr[instruction.typeR.source2]){
        registerArr[instruction.typeR.destination] = 1;
    }else{
        registerArr[instruction.typeR.destination] = 0;
    }
    return SUCCESS;
}

int str(binInstruction_t instruction)
{
    registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source];
    return SUCCESS;
}

int ld(binInstruction_t instruction)
{
    registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source];
    return SUCCESS;
}

int strp(binInstruction_t instruction)
{
    registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source];
    return SUCCESS;
}

int ldp(binInstruction_t instruction)
{
    registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source];
    return SUCCESS;
}

int push(binInstruction_t instruction)
{
    uint32_t address = registerArr[STACK_POINTER];
    set_memory_32(address, registerArr[instruction.typeR.source]);
    registerArr[STACK_POINTER] -= 4;
    return SUCCESS;
}

int pop(binInstruction_t instruction)
{
    registerArr[STACK_POINTER] += 4;
    uint32_t address = registerArr[STACK_POINTER];
    registerArr[instruction.typeR.destination] = read_memory_32(address);
    return SUCCESS;
}

int xchg(binInstruction_t instruction)
{
    uint32_t internal = registerArr[instruction.typeR.source];
    registerArr[instruction.typeR.source] = registerArr[instruction.typeR.source2];
    registerArr[instruction.typeR.source2] = internal;
    return SUCCESS;
}

int addi(binInstruction_t instruction)
{
    registerArr[instruction.typeI.destination] = registerArr[instruction.typeI.source] + registerArr[instruction.typeI.immediate];
    return SUCCESS;
}

int subi(binInstruction_t instruction)
{
    registerArr[instruction.typeI.destination] = registerArr[instruction.typeI.source] - registerArr[instruction.typeI.immediate];
    return SUCCESS;
}

int stri(binInstruction_t instruction)
{
    registerArr[instruction.typeI.destination] = registerArr[instruction.typeI.immediate];
    return SUCCESS;
}

int ldi(binInstruction_t instruction)
{
    registerArr[instruction.typeI.destination] = registerArr[instruction.typeI.immediate];
    return SUCCESS;
}

int ori(binInstruction_t instruction)
{
    registerArr[instruction.typeI.destination] = registerArr[instruction.typeI.source] | registerArr[instruction.typeI.immediate];
    return SUCCESS;
}

int andi(binInstruction_t instruction)
{
    registerArr[instruction.typeI.destination] = registerArr[instruction.typeI.source] & registerArr[instruction.typeI.immediate];
    return SUCCESS;
}

int xori(binInstruction_t instruction)
{
    registerArr[instruction.typeI.destination] = registerArr[instruction.typeI.source] ^ registerArr[instruction.typeI.immediate];
    return SUCCESS;
}

int set(binInstruction_t instruction)
{
    registerArr[instruction.typeI.source] == registerArr[instruction.typeI.immediate];
    return SUCCESS;
}

int tlti(binInstruction_t instruction)
{
    if (registerArr[instruction.typeI.source] < registerArr[instruction.typeI.immediate]) {
        registerArr[instruction.typeI.destination] = 1;
    } else {
        registerArr[instruction.typeI.destination] = 0;
    }
    return SUCCESS;
}

int tlei(binInstruction_t instruction)
{
    if (registerArr[instruction.typeI.source] <= registerArr[instruction.typeI.immediate]) {
        registerArr[instruction.typeI.destination] = 1;
    } else {
        registerArr[instruction.typeI.destination] = 0;
    }
    return SUCCESS;
}

int tgti(binInstruction_t instruction)
{
    if (registerArr[instruction.typeI.source] > registerArr[instruction.typeI.immediate]) {
        registerArr[instruction.typeI.destination] = 1;
    } else {
        registerArr[instruction.typeI.destination] = 0;
    }
    return SUCCESS;
}

int tgei(binInstruction_t instruction)
{
    if (registerArr[instruction.typeI.source] >= registerArr[instruction.typeI.immediate]) {
        registerArr[instruction.typeI.destination] = 1;
    } else {
        registerArr[instruction.typeI.destination] = 0;
    }
    return SUCCESS;
}

int teqi(binInstruction_t instruction)
{
    if (registerArr[instruction.typeI.source] == registerArr[instruction.typeI.immediate]) {
        registerArr[instruction.typeI.destination] = 1;
    } else {
        registerArr[instruction.typeI.destination] = 0;
    }
    return SUCCESS;
}

int tnei(binInstruction_t instruction)
{
    if (registerArr[instruction.typeI.source] != registerArr[instruction.typeI.immediate]) {
        registerArr[instruction.typeI.destination] = 1;
    } else {
        registerArr[instruction.typeI.destination] = 0;
    }
    return SUCCESS;
}

int b(binInstruction_t instruction)
{
    uint32_t address = registerArr[instruction.typeJ.register_] + instruction.typeJ.address;
    registerArr[INSTRUCTION_POINTER] += address << 2;
    return SUCCESS;
}

int bi(binInstruction_t instruction)
{
    uint32_t address = (instruction.typeJ.address << 5) | instruction.typeJ.register_;
    registerArr[INSTRUCTION_POINTER] += address << 2;
    return SUCCESS;
}

int bz(binInstruction_t instruction)
{
    uint32_t value = registerArr[instruction.typeJ.register_];
    if (value == 0)
    {
        return bi(instruction);
    }
    return SUCCESS;
}

int bnz(binInstruction_t instruction)
{
    uint32_t value = registerArr[instruction.typeJ.register_];
    if (value != 0)
    {
        return bi(instruction);
    }
    return SUCCESS;
}

int call(binInstruction_t instruction)
{
    uint32_t address = registerArr[STACK_POINTER];
    set_memory_32(address, registerArr[INSTRUCTION_POINTER] + 4);
    registerArr[STACK_POINTER] -= 4;
    return b(instruction);
}

int calli(binInstruction_t instruction)
{
    uint32_t address = registerArr[STACK_POINTER];
    set_memory_32(address, registerArr[INSTRUCTION_POINTER] + 4);
    registerArr[STACK_POINTER] -= 4;
    return bi(instruction);
}

int ret(binInstruction_t instruction)
{
    registerArr[STACK_POINTER] += 4;
    uint32_t address = registerArr[STACK_POINTER];
    registerArr[INSTRUCTION_POINTER] = read_memory_32(address);
    return SUCCESS;
}

int jmp(binInstruction_t instruction)
{
    registerArr[INSTRUCTION_POINTER] = instruction.typeJ.address << 2;
    return SUCCESS;
}

#endif