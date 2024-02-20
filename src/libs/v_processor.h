#ifndef V_PROCESSOR_H
#define V_PROCESSOR_H

// rest of v_processor.h

#include ".libs/utils.h"

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

int add(binInstruction_t instruction)
{
    struct params = instruction.typeR;
    registerArr[params.destination] = registerArr[params.source] + registerArr[params.source2];
    return SUCCESS;
}

int sub(binInstruction_t instruction)
{
    struct params = instruction.typeR;
    registerArr[params.destination] = registerArr[params.source] - registerArr[params.source2];
    return SUCCESS;
}

int mul(binInstruction_t instruction)
{
    struct params = instruction.typeR;
    registerArr[params.destination] = registerArr[params.source] * registerArr[params.source2];
    return SUCCESS;
}

int div(binInstruction_t instruction)
{
    return SUCCESS;
}

int or(binInstruction_t instruction)
{
    return SUCCESS;
}

int and(binInstruction_t instruction)
{
    return SUCCESS;
}

int xor(binInstruction_t instruction)
{
    return SUCCESS;
}

int abs(binInstruction_t instruction)
{
    return SUCCESS;
}

int tlt(binInstruction_t instruction)
{
    return SUCCESS;
}

int tle(binInstruction_t instruction)
{
    return SUCCESS;
}

int tgt(binInstruction_t instruction)
{
    return SUCCESS;
}

int tge(binInstruction_t instruction)
{
    return SUCCESS;
}

int teq(binInstruction_t instruction)
{
    return SUCCESS;
}

int tne(binInstruction_t instruction)
{
    return SUCCESS;
}

int str(binInstruction_t instruction)
{
    return SUCCESS;
}

int ld(binInstruction_t instruction)
{
    return SUCCESS;
}

int strp(binInstruction_t instruction)
{
    return SUCCESS;
}

int ldp(binInstruction_t instruction)
{
    return SUCCESS;
}

int push(binInstruction_t instruction)
{
    return SUCCESS;
}

int pop(binInstruction_t instruction)
{
    return SUCCESS;
}

int xchg(binInstruction_t instruction)
{
    return SUCCESS;
}

int addi(binInstruction_t instruction)
{
    return SUCCESS;
}

int subi(binInstruction_t instruction)
{
    return SUCCESS;
}

int stri(binInstruction_t instruction)
{
    return SUCCESS;
}

int ldi(binInstruction_t instruction)
{
    return SUCCESS;
}

int ori(binInstruction_t instruction)
{
    return SUCCESS;
}

int andi(binInstruction_t instruction)
{
    return SUCCESS;
}

int xori(binInstruction_t instruction)
{
    return SUCCESS;
}

int set(binInstruction_t instruction)
{
    return SUCCESS;
}

int tlti(binInstruction_t instruction)
{
    return SUCCESS;
}

int tlei(binInstruction_t instruction)
{
    return SUCCESS;
}

int tgti(binInstruction_t instruction)
{
    return SUCCESS;
}

int tgei(binInstruction_t instruction)
{
    return SUCCESS;
}

int teqi(binInstruction_t instruction)
{
    return SUCCESS;
}

int tnei(binInstruction_t instruction)
{
    return SUCCESS;
}

int b(binInstruction_t instruction)
{
    address = registerArr[instruction.typeJ.register_] + instruction.typeJ.address;
    registerArr[INSTRUCTION_POINTER] += address << 4;
    return SUCCESS;
}

int bi(binInstruction_t instruction)
{
    address = instruction.typeJ.address + (instruction.typeJ.register_ << 5);
    registerArr[INSTRUCTION_POINTER] += address << 4;
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
    memory[address] = (registerArr[INSTRUCTION_POINTER] + 1) << 4;
    registerArr[STACK_POINTER] -= 1;
    return b(instruction);
}

int calli(binInstruction_t instruction)
{
    uint32_t address = registerArr[STACK_POINTER];
    memory[address] = (registerArr[INSTRUCTION_POINTER] + 1) << 4;
    registerArr[STACK_POINTER] -= 1;
    return bi(instruction);
}

int ret(binInstruction_t instruction)
{
    registerArr[STACK_POINTER] += 1;
    uint32_t address = registerArr[STACK_POINTER];
    registerArr[INSTRUCTION_POINTER] = memory[address];
    return SUCCESS;
}

int jmp(binInstruction_t instruction)
{
    registerArr[INSTRUCTION_POINTER] = instruction.typeJ.address << 4;
    return SUCCESS;
}

#endif