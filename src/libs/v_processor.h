#ifndef V_PROCESSOR_H
#define V_PROCESSOR_H


//__________________________________________________________________________________________________
//  VIRTUAL COMPONENTS
//_____________________

uint32_t registerArr[32]={0};     // the 32 registers

// the memory
uint8_t memory[1073741824]; // Memory does only 1GB of RAM

// Sections order and their size inside the memory
// inputSection  :         1,024 Bytes (1 KB)
// outputSection :        32,768 Bytes (32 KB)
// videoSection  :       262,144 Bytes (256 KB)
// stackSection  :     1,048,576 Bytes (1 MB)
// codeSection   :    33,554,432 Bytes (32 MB)
// dataSection   : 1,038,842,880 Bytes (1,014,495 KB) (aproximately 0.968,75 GB)

// Memory adresses of each section on 30 bits (so the 2 first bits are always 0 on 32 bits addresses)
// inputSection   : HEX 0000 0000   : BIN 0000 0000 0000 0000 0000 0000 0000 0000
// outputSection  : HEX 0000 0400   : BIN 0000 0000 0000 0000 0000 0100 0000 0000
// videoSection   : HEX 0000 8400   : BIN 0000 0000 0000 0000 1000 0100 0000 0000
// stackSection   : HEX 0004 8400   : BIN 0000 0000 0000 0100 1000 0100 0000 0000
// codeSection    : HEX 0014 8400   : BIN 0000 0000 0010 0100 1000 0100 0000 0000
// dataSection    : HEX 0214 8400   : BIN 0000 0010 0001 0100 1000 0100 0000 0000


// No flags
//__________________________________________________________________________________________________


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

/* int div(binInstruction_t instruction)
{
    registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source] / registerArr[instruction.typeR.source2];
    return SUCCESS;
} */

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

/* int abs(binInstruction_t instruction)
{
    registerArr[instruction.typeR.destination] = abs(registerArr[instruction.typeR.source]);
    return SUCCESS;
} */

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
    memory[address] = registerArr[instruction.typeR.source];
    registerArr[STACK_POINTER] -= 4;
    return SUCCESS;
}

int pop(binInstruction_t instruction)
{
    registerArr[STACK_POINTER] += 4;
    uint32_t address = registerArr[STACK_POINTER];
    registerArr[instruction.typeR.destination] = memory[address];
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
    memory[address] = registerArr[INSTRUCTION_POINTER] + 4;
    registerArr[STACK_POINTER] -= 4;
    return b(instruction);
}

int calli(binInstruction_t instruction)
{
    uint32_t address = registerArr[STACK_POINTER];
    memory[address] = registerArr[INSTRUCTION_POINTER] + 4;
    registerArr[STACK_POINTER] -= 4;
    return bi(instruction);
}

int ret(binInstruction_t instruction)
{
    registerArr[STACK_POINTER] += 4;
    uint32_t address = registerArr[STACK_POINTER];
    registerArr[INSTRUCTION_POINTER] = memory[address];
    return SUCCESS;
}

int jmp(binInstruction_t instruction)
{
    registerArr[INSTRUCTION_POINTER] = instruction.typeJ.address << 2;
    return SUCCESS;
}

#endif