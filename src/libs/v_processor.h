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
}

int sub(binInstruction_t instruction)
{
    struct params = instruction.typeR;
    registerArr[params.destination] = registerArr[params.source] - registerArr[params.source2];
}

int mul(binInstruction_t instruction)
{
    struct params = instruction.typeR;
    registerArr[params.destination] = registerArr[params.source] * registerArr[params.source2];
}

int div(binInstruction_t instruction)
{
    return 0;
}

int or(binInstruction_t instruction)
{
    return 0;
}

int and(binInstruction_t instruction)
{
    return 0;
}

int xor(binInstruction_t instruction)
{
    return 0;
}

int abs(binInstruction_t instruction)
{
    return 0;
}

int tlt(binInstruction_t instruction)
{
    return 0;
}

int tle(binInstruction_t instruction)
{
    return 0;
}

int tgt(binInstruction_t instruction)
{
    return 0;
}

int tge(binInstruction_t instruction)
{
    return 0;
}

int teq(binInstruction_t instruction)
{
    return 0;
}

int tne(binInstruction_t instruction)
{
    return 0;
}

int str(binInstruction_t instruction)
{
    return 0;
}

int ld(binInstruction_t instruction)
{
    return 0;
}

int strp(binInstruction_t instruction)
{
    return 0;
}

int ldp(binInstruction_t instruction)
{
    return 0;
}

int push(binInstruction_t instruction)
{
    return 0;
}

int pop(binInstruction_t instruction)
{
    return 0;
}

int xchg(binInstruction_t instruction)
{
    return 0;
}

int addi(binInstruction_t instruction)
{
    return 0;
}

int subi(binInstruction_t instruction)
{
    return 0;
}

int stri(binInstruction_t instruction)
{
    return 0;
}

int ldi(binInstruction_t instruction)
{
    return 0;
}

int ori(binInstruction_t instruction)
{
    return 0;
}

int andi(binInstruction_t instruction)
{
    return 0;
}

int xori(binInstruction_t instruction)
{
    return 0;
}

int set(binInstruction_t instruction)
{
    return 0;
}

int tlti(binInstruction_t instruction)
{
    return 0;
}

int tlei(binInstruction_t instruction)
{
    return 0;
}

int tgti(binInstruction_t instruction)
{
    return 0;
}

int tgei(binInstruction_t instruction)
{
    return 0;
}

int teqi(binInstruction_t instruction)
{
    return 0;
}

int tnei(binInstruction_t instruction)
{
    return 0;
}

int b(binInstruction_t instruction)
{
    address = registerArr[instruction.typeJ.register_] + instruction.typeJ.address;
    registerArr[INSTRUCTION_POINTER] += address << 4;
    return 0;
}

int bi(binInstruction_t instruction)
{
    address = instruction.typeJ.address + (instruction.typeJ.register_ << 5);
    registerArr[INSTRUCTION_POINTER] += address << 4;
    return 0;
}

int bz(binInstruction_t instruction)
{
    uint32_t value = registerArr[instruction.typeJ.register_];
    if (value == 0)
    {
        return bi(instruction);
    }
    return 0;
}

int bnz(binInstruction_t instruction)
{
    uint32_t value = registerArr[instruction.typeJ.register_];
    if (value != 0)
    {
        return bi(instruction);
    }
    return 0;
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
    return 0;
}

int jmp(binInstruction_t instruction)
{
    registerArr[INSTRUCTION_POINTER] = instruction.typeJ.address << 4;
    return 0;
}

#endif