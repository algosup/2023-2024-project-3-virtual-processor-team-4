#ifndef V_INSTRUCTIONS_H
#define V_INSTRUCTIONS_H

extern bool running;

//__________________________________________________________________________________________________
//  VIRTUAL INSTRUCTIONS PROTOTYPES
//_____________________

int instr_add(binInstruction_t instruction);
int instr_sub(binInstruction_t instruction);
int instr_mul(binInstruction_t instruction);
int instr_div(binInstruction_t instruction);
int instr_or(binInstruction_t instruction);
int instr_and(binInstruction_t instruction);
int instr_xor(binInstruction_t instruction);
int instr_abs(binInstruction_t instruction);
int instr_tlt(binInstruction_t instruction);
int instr_tle(binInstruction_t instruction);
int instr_tgt(binInstruction_t instruction);
int instr_tge(binInstruction_t instruction);
int instr_teq(binInstruction_t instruction);
int instr_tne(binInstruction_t instruction);
int instr_str(binInstruction_t instruction);
int instr_ld(binInstruction_t instruction);
int instr_strp(binInstruction_t instruction);
int instr_ldp(binInstruction_t instruction);
int instr_push(binInstruction_t instruction);
int instr_pop(binInstruction_t instruction);
int instr_xchg(binInstruction_t instruction);
int instr_addi(binInstruction_t instruction);
int instr_subi(binInstruction_t instruction);
int instr_stri(binInstruction_t instruction);
int instr_ldi(binInstruction_t instruction);
int instr_ori(binInstruction_t instruction);
int instr_andi(binInstruction_t instruction);
int instr_xori(binInstruction_t instruction);
int instr_set(binInstruction_t instruction);
int instr_tlti(binInstruction_t instruction);
int instr_tlei(binInstruction_t instruction);
int instr_tgti(binInstruction_t instruction);
int instr_tgei(binInstruction_t instruction);
int instr_teqi(binInstruction_t instruction);
int instr_tnei(binInstruction_t instruction);
int instr_b(binInstruction_t instruction);
int instr_bi(binInstruction_t instruction);
int instr_bz(binInstruction_t instruction);
int instr_bnz(binInstruction_t instruction);
int instr_call(binInstruction_t instruction);
int instr_calli(binInstruction_t instruction);
int instr_ret(binInstruction_t instruction);
int instr_jmp(binInstruction_t instruction);

//__________________________________________________________________________________________________
//  VIRTUAL INSTRUCTIONS IMPLEMENTATION
//____________________________________

int instr_add(binInstruction_t instruction)
{
    registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source] + registerArr[instruction.typeR.source2];
    return SUCCESS;
}


int instr_sub(binInstruction_t instruction)
{
    registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source] - registerArr[instruction.typeR.source2];
    return SUCCESS;
}

int instr_mul(binInstruction_t instruction)
{
    registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source] * registerArr[instruction.typeR.source2];
    return SUCCESS;
}

int instr_div(binInstruction_t instruction)
{
    if (registerArr[instruction.typeR.source2] != 0){
        registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source] / registerArr[instruction.typeR.source2];
        return SUCCESS;
    }else{
        return INVALID_DATA;
    }
}

int instr_or(binInstruction_t instruction)
{
    registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source] | registerArr[instruction.typeR.source2];
    return SUCCESS;
}

int instr_and(binInstruction_t instruction)
{
    registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source] & registerArr[instruction.typeR.source2];
    return SUCCESS;
}

int instr_xor(binInstruction_t instruction)
{
    registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source] ^ registerArr[instruction.typeR.source2];
    return SUCCESS;
}

int instr_abs(binInstruction_t instruction)
{
    registerArr[instruction.typeR.destination] = abs(registerArr[instruction.typeR.source]);
    return SUCCESS;
}

int instr_tlt(binInstruction_t instruction)
{
    if (registerArr[instruction.typeR.source] < registerArr[instruction.typeR.source2]){
        registerArr[instruction.typeR.destination] = 1;
    }else{
        registerArr[instruction.typeR.destination] = 0;
    }
    return SUCCESS;
}

int instr_tle(binInstruction_t instruction)
{
    if (registerArr[instruction.typeR.source] <= registerArr[instruction.typeR.source2]){
        registerArr[instruction.typeR.destination] = 1;
    }else{
        registerArr[instruction.typeR.destination] = 0;
    }
    return SUCCESS;
}

int instr_tgt(binInstruction_t instruction)
{
    if (registerArr[instruction.typeR.source] > registerArr[instruction.typeR.source2]){
        registerArr[instruction.typeR.destination] = 1;
    }else{
        registerArr[instruction.typeR.destination] = 0;
    }
    return SUCCESS;
}

int instr_tge(binInstruction_t instruction)
{
    if (registerArr[instruction.typeR.source] >= registerArr[instruction.typeR.source2]){
        registerArr[instruction.typeR.destination] = 1;
    }else{
        registerArr[instruction.typeR.destination] = 0;
    }
    return SUCCESS;
}

int instr_teq(binInstruction_t instruction)
{
    if (registerArr[instruction.typeR.source] == registerArr[instruction.typeR.source2]){
        registerArr[instruction.typeR.destination] = 1;
    }else{
        registerArr[instruction.typeR.destination] = 0;
    }
    return SUCCESS;
}

int instr_tne(binInstruction_t instruction)
{
    if (registerArr[instruction.typeR.source] != registerArr[instruction.typeR.source2]){
        registerArr[instruction.typeR.destination] = 1;
    }else{
        registerArr[instruction.typeR.destination] = 0;
    }
    return SUCCESS;
}

int instr_str(binInstruction_t instruction)
{
    registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source];
    return SUCCESS;
}

int instr_ld(binInstruction_t instruction)
{
    registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source];
    return SUCCESS;
}

int instr_strp(binInstruction_t instruction)
{
    registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source];
    return SUCCESS;
}

int instr_ldp(binInstruction_t instruction)
{
    registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source];
    return SUCCESS;
}

int instr_push(binInstruction_t instruction)
{   
    uint32_t address = registerArr[STACK_POINTER];
    set_memory_32(address, registerArr[instruction.typeR.source]);
    registerArr[STACK_POINTER] -= 4;
    return SUCCESS;
}

int instr_pop(binInstruction_t instruction)
{
    registerArr[STACK_POINTER] += 4;
    uint32_t address = registerArr[STACK_POINTER];
    registerArr[instruction.typeR.destination] = read_memory_32(address);
    return SUCCESS;
}

int instr_xchg(binInstruction_t instruction)
{
    uint32_t internal = registerArr[instruction.typeR.source];
    registerArr[instruction.typeR.source] = registerArr[instruction.typeR.source2];
    registerArr[instruction.typeR.source2] = internal;
    return SUCCESS;
}

int instr_addi(binInstruction_t instruction)
{
    registerArr[instruction.typeI.destination] = registerArr[instruction.typeI.source] + instruction.typeI.immediate;
    return SUCCESS;
}

int instr_subi(binInstruction_t instruction)
{
    registerArr[instruction.typeI.destination] = registerArr[instruction.typeI.source] - instruction.typeI.immediate;
    return SUCCESS;
}

int instr_stri(binInstruction_t instruction)
{
    registerArr[instruction.typeI.destination] = instruction.typeI.immediate;
    return SUCCESS;
}

int instr_ldi(binInstruction_t instruction)
{
    registerArr[instruction.typeI.destination] = instruction.typeI.immediate;
    return SUCCESS;
}

int instr_ori(binInstruction_t instruction)
{
    registerArr[instruction.typeI.destination] = registerArr[instruction.typeI.source] | instruction.typeI.immediate;
    return SUCCESS;
}

int instr_andi(binInstruction_t instruction)
{
    registerArr[instruction.typeI.destination] = registerArr[instruction.typeI.source] & instruction.typeI.immediate;
    return SUCCESS;
}

int instr_xori(binInstruction_t instruction)
{
    registerArr[instruction.typeI.destination] = registerArr[instruction.typeI.source] ^ instruction.typeI.immediate;
    return SUCCESS;
}

int instr_set(binInstruction_t instruction)
{
    registerArr[instruction.typeI.destination] = (instruction.typeI.immediate << 5) | instruction.typeI.source;
    return SUCCESS;
}

int instr_tlti(binInstruction_t instruction)
{
    if (registerArr[instruction.typeI.source] < instruction.typeI.immediate) {
        registerArr[instruction.typeI.destination] = 1;
    } else {
        registerArr[instruction.typeI.destination] = 0;
    }
    return SUCCESS;
}

int instr_tlei(binInstruction_t instruction)
{
    if (registerArr[instruction.typeI.source] <= instruction.typeI.immediate) {
        registerArr[instruction.typeI.destination] = 1;
    } else {
        registerArr[instruction.typeI.destination] = 0;
    }
    return SUCCESS;
}

int instr_tgti(binInstruction_t instruction)
{
    if (registerArr[instruction.typeI.source] > instruction.typeI.immediate) {
        registerArr[instruction.typeI.destination] = 1;
    } else {
        registerArr[instruction.typeI.destination] = 0;
    }
    return SUCCESS;
}

int instr_tgei(binInstruction_t instruction)
{
    if (registerArr[instruction.typeI.source] >= instruction.typeI.immediate) {
        registerArr[instruction.typeI.destination] = 1;
    } else {
        registerArr[instruction.typeI.destination] = 0;
    }
    return SUCCESS;
}

int instr_teqi(binInstruction_t instruction)
{
    if (registerArr[instruction.typeI.source] == instruction.typeI.immediate) {
        registerArr[instruction.typeI.destination] = 1;
    } else {
        registerArr[instruction.typeI.destination] = 0;
    }
    return SUCCESS;
}

int instr_tnei(binInstruction_t instruction)
{
    if (registerArr[instruction.typeI.source] != instruction.typeI.immediate) {
        registerArr[instruction.typeI.destination] = 1;
    } else {
        registerArr[instruction.typeI.destination] = 0;
    }
    return SUCCESS;
}

int instr_b(binInstruction_t instruction)
{
    int32_t address = registerArr[instruction.typeJ.register_] + instruction.typeJ.address;
    registerArr[INSTRUCTION_POINTER] += address << 2;
    return SUCCESS;
}

int instr_bi(binInstruction_t instruction)
{
    int32_t address = (instruction.typeJ.address << 5) | instruction.typeJ.register_;
    registerArr[INSTRUCTION_POINTER] += address << 2;
    return SUCCESS;
}

int instr_bz(binInstruction_t instruction)
{
    int32_t value = registerArr[instruction.typeJ.register_];
    if (value == 0)
    {
        registerArr[INSTRUCTION_POINTER] += instruction.typeJ.address << 2;
    }
    else
    {
        registerArr[INSTRUCTION_POINTER] += 4;
    }
    return SUCCESS;
}

int instr_bnz(binInstruction_t instruction)
{
    int32_t value = registerArr[instruction.typeJ.register_];
    if (value == 0)
    {
        registerArr[INSTRUCTION_POINTER] += 4;
    }
    else
    {
        registerArr[INSTRUCTION_POINTER] += instruction.typeJ.address << 2;
    }
    return SUCCESS;
}

int instr_call(binInstruction_t instruction)
{
    set_memory_32(registerArr[STACK_POINTER], registerArr[INSTRUCTION_POINTER] + 4);
    registerArr[STACK_POINTER] -= 4;
    int32_t address = registerArr[instruction.typeJ.register_] + instruction.typeJ.address;
    registerArr[INSTRUCTION_POINTER] += address << 2;
    return SUCCESS;
}

int instr_calli(binInstruction_t instruction)
{
    set_memory_32(registerArr[STACK_POINTER], registerArr[INSTRUCTION_POINTER] + 4);
    registerArr[STACK_POINTER] -= 4;
    int32_t address = (instruction.typeJ.address << 5) | instruction.typeJ.register_;
    registerArr[INSTRUCTION_POINTER] += address << 2;
    return SUCCESS;
}

int instr_ret(binInstruction_t instruction)
{
    if (instruction.typeJ.register_)
    {
        return HALT;
    }
    registerArr[STACK_POINTER] += 4;
    uint32_t address = registerArr[STACK_POINTER];
    registerArr[INSTRUCTION_POINTER] = read_memory_32(address);
    return SUCCESS;
}

int instr_jmp(binInstruction_t instruction)
{
    registerArr[INSTRUCTION_POINTER] = instruction.typeJ.address << 2;
    return SUCCESS;
}

#endif