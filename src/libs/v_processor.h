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
    struct params = instruction.typeR;
    registerArr[params.destination] = registerArr[params.source] / registerArr[params.source2];
    return SUCCESS;
}

int or(binInstruction_t instruction)
{
    struct params = instruction.typeR;
    registerArr[params.destination] = registerArr[params.source] | registerArr[params.source2];
    return SUCCESS;
}

int and(binInstruction_t instruction)
{
    struct params = instruction.typeR;
    registerArr[params.destination] = registerArr[params.source] & registerArr[params.source2];
    return SUCCESS;
}

int xor(binInstruction_t instruction)
{
    struct params = instruction.typeR;
    registerArr[params.destination] = registerArr[params.source] ^ registerArr[params.source2];
    return SUCCESS;
}

int abs(binInstruction_t instruction)
{
    struct params = instruction.typeR;
    registerArr[params.destination] = abs(registerArr[params.source]);
    return SUCCESS;
}

int tlt(binInstruction_t instruction)
{
    struct params = instruction.typeR;
    if (registerArr[params.source] < registerArr[params.source2]){
        registerArr[params.destination] = 1;
    }else{
        registerArr[params.destination] = 0;
    }
    return SUCCESS;
}

int tle(binInstruction_t instruction)
{
    struct params = instruction.typeR;
    if (registerArr[params.source] <= registerArr[params.source2]){
        registerArr[params.destination] = 1;
    }else{
        registerArr[params.destination] = 0;
    }
    return SUCCESS;
}

int tgt(binInstruction_t instruction)
{
    struct params = instruction.typeR;
    if (registerArr[params.source] > registerArr[params.source2]){
        registerArr[params.destination] = 1;
    }else{
        registerArr[params.destination] = 0;
    }
    return SUCCESS;
}

int tge(binInstruction_t instruction)
{
    struct params = instruction.typeR;
    if (registerArr[params.source] >= registerArr[params.source2]){
        registerArr[params.destination] = 1;
    }else{
        registerArr[params.destination] = 0;
    }
    return SUCCESS;
}

int teq(binInstruction_t instruction)
{
    struct params = instruction.typeR;
    if (registerArr[params.source] == registerArr[params.source2]){
        registerArr[params.destination] = 1;
    }else{
        registerArr[params.destination] = 0;
    }
    return SUCCESS;
}

int tne(binInstruction_t instruction)
{
    struct params = instruction.typeR;
    if (registerArr[params.source] != registerArr[params.source2]){
        registerArr[params.destination] = 1;
    }else{
        registerArr[params.destination] = 0;
    }
    return SUCCESS;
}

int str(binInstruction_t instruction)
{
    struct params = instruction.typeR;
    registerArr[params.destination] = registerArr[params.source];
    return SUCCESS;
}

int ld(binInstruction_t instruction)
{
    struct params = instruction.typeR;
    registerArr[params.destination] = registerArr[params.source];
    return SUCCESS;
}

int strp(binInstruction_t instruction)
{
    struct params = instruction.typeR;
    registerArr[params.destination] = registerArr[params.source];
    return SUCCESS;
}

int ldp(binInstruction_t instruction)
{
    struct params = instruction.typeR;
    registerArr[params.destination] = registerArr[params.source];
    return SUCCESS;
}

int push(binInstruction_t instruction)
{
    struct params = instruction.typeR;
    registerArr[params.destination] = registerArr[params.source];
    return SUCCESS;
}

int pop(binInstruction_t instruction)
{
    return SUCCESS;
}

int xchg(binInstruction_t instruction)
{
    struct params = instruction.typeR;
    int internal = registerArr[params.source];
    registerArr[params.source] = registerArr[params.source2];
    registerArr[params.source2] = internal;
    return SUCCESS;
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
    return 0;
}

int bi(binInstruction_t instruction)
{
    return 0;
}

int bz(binInstruction_t instruction)
{
    return 0;
}

int bnz(binInstruction_t instruction)
{
    return 0;
}

int call(binInstruction_t instruction)
{
    return 0;
}

int calli(binInstruction_t instruction)
{
    return 0;
}

int ret(binInstruction_t instruction)
{
    return 0;
}

int jmp(binInstruction_t instruction)
{
    return 0;
}

#endif