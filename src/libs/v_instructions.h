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

int check_opcode_typeR(binInstruction_t instruction)
{
    int i;

    for (i = 0; i < 42; i++)
    {
        if ((InstructionType_t)i == instruction.typeR.opcode)
        {
            return SUCCESS;
        }
    }

    return INVALID_DATA;
}

int check_opcode_typeI(binInstruction_t instruction)
{
    int i;

    for (i = 0; i < 42; i++)
    {
        if ((InstructionType_t)i == instruction.typeI.opcode)
        {
            return SUCCESS;
        }
    }

    return INVALID_DATA;
}

int check_opcode_typeJ(binInstruction_t instruction)
{
    int i;

    for (i = 0; i < 42; i++)
    {
        if ((InstructionType_t)i == instruction.typeJ.opcode)
        {
            return SUCCESS;
        }
    }

    return INVALID_DATA;
}


int check_three_registers_typeR(binInstruction_t instruction){
    if (instruction.typeR.destination > 31 || instruction.typeR.source > 31 || instruction.typeR.source2 > 31){
        printf("Error: not existing register");
        return INVALID_DATA;
    }

    if (instruction.typeR.destination > 29 || instruction.typeR.source > 29 || instruction.typeR.source2 > 29){
        printf("Error: ip and sp are read-only");
        return INVALID_DATA;
    }

    if (instruction.typeR.destination > 25 || instruction.typeR.source > 25 || instruction.typeR.source2 > 25){
        printf("Error: not existing register");
        return INVALID_DATA;
    }

    return SUCCESS;
}

int check_two_registers_typeR(binInstruction_t instruction){
    if (instruction.typeR.destination > 31 || instruction.typeR.source > 31){
        printf("Error: not existing register");
        return INVALID_DATA;
    }

    if (instruction.typeR.destination > 29 || instruction.typeR.source > 29){
        printf("Error: ip and sp are read-only");
        return INVALID_DATA;
    }

    if (instruction.typeR.destination > 25 || instruction.typeR.source > 25){
        printf("Error: not existing register");
        return INVALID_DATA;
    }

    return SUCCESS;
}

int check_registers_typeI(binInstruction_t instruction){
    if (instruction.typeI.destination > 31 || instruction.typeI.source > 31){
        printf("Error: not existing register");
        return INVALID_DATA;
    }

    if (instruction.typeI.destination > 29 || instruction.typeI.source > 29){
        printf("Error: ip and sp are read-only");
        return INVALID_DATA;
    }

    if (instruction.typeI.destination > 25 || instruction.typeI.source > 25){
        printf("Error: not existing register");
        return INVALID_DATA;
    }

    return SUCCESS;
}

int check_destination_typeI(binInstruction_t instruction){
    if (instruction.typeI.destination > 31){
        printf("Error: not existing register");
        return INVALID_DATA;
    }

    if (instruction.typeI.destination > 29){
        printf("Error: ip and sp are read-only");
        return INVALID_DATA;
    }

    if (instruction.typeI.destination > 25){
        printf("Error: not existing register");
        return INVALID_DATA;
    }

    return SUCCESS;
}

int check_source_typeI(binInstruction_t instruction){
    if (instruction.typeI.source > 31){
        printf("Error: not existing register");
        return INVALID_DATA;
    }

    if (instruction.typeI.source > 29){
        printf("Error: ip and sp are read-only");
        return INVALID_DATA;
    }

    if (instruction.typeI.source > 25){
        printf("Error: not existing register");
        return INVALID_DATA;
    }

    return SUCCESS;
}

int check_register_typeJ(binInstruction_t instruction){
    if (instruction.typeJ.register_ > 31){
        printf("Error: not existing register");
        return INVALID_DATA;
    }

    if (instruction.typeJ.register_ > 29){
        printf("Error: ip and sp are read-only");
        return INVALID_DATA;
    }

    if (instruction.typeJ.register_ > 25){
        printf("Error: not existing register");
        return INVALID_DATA;
    }

    return SUCCESS;
}

int instr_add(binInstruction_t instruction)
{
    if (check_opcode_typeR(instruction) == SUCCESS && check_three_registers_typeR(instruction) == SUCCESS){
        registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source] + registerArr[instruction.typeR.source2];
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}


int instr_sub(binInstruction_t instruction)
{
    if (check_opcode_typeR(instruction) == SUCCESS && check_three_registers_typeR(instruction) == SUCCESS){
        registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source] - registerArr[instruction.typeR.source2];
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_mul(binInstruction_t instruction)
{
    if (check_opcode_typeR(instruction) == SUCCESS && check_three_registers_typeR(instruction) == SUCCESS){
        registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source] * registerArr[instruction.typeR.source2];
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_div(binInstruction_t instruction)
{
    if (check_opcode_typeR(instruction) == SUCCESS && check_three_registers_typeR(instruction) == SUCCESS){
        if (registerArr[instruction.typeR.source2] != 0){
            registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source] / registerArr[instruction.typeR.source2];
            return SUCCESS;
        }else{
            return INVALID_DATA;
        }
    }else{
        return GENERIC_ERROR;
    }
}

int instr_or(binInstruction_t instruction)
{
    if (check_opcode_typeR(instruction) == SUCCESS && check_three_registers_typeR(instruction) == SUCCESS){
        registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source] | registerArr[instruction.typeR.source2];
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_and(binInstruction_t instruction)
{
    if (check_opcode_typeR(instruction) == SUCCESS && check_three_registers_typeR(instruction) == SUCCESS){
        registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source] & registerArr[instruction.typeR.source2];
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_xor(binInstruction_t instruction)
{
    if (check_opcode_typeR(instruction) == SUCCESS && check_three_registers_typeR(instruction) == SUCCESS){
        registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source] ^ registerArr[instruction.typeR.source2];
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_abs(binInstruction_t instruction)
{
    if (check_opcode_typeR(instruction) == SUCCESS && check_three_registers_typeR(instruction) == SUCCESS){
        registerArr[instruction.typeR.destination] = abs(registerArr[instruction.typeR.source]);
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_tlt(binInstruction_t instruction)
{
    if (check_opcode_typeR(instruction) == SUCCESS && check_three_registers_typeR(instruction) == SUCCESS){
        if (registerArr[instruction.typeR.source] < registerArr[instruction.typeR.source2]){
            registerArr[instruction.typeR.destination] = 1;
        }else{
            registerArr[instruction.typeR.destination] = 0;
        }
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_tle(binInstruction_t instruction)
{
    if (check_opcode_typeR(instruction) == SUCCESS && check_three_registers_typeR(instruction) == SUCCESS){
        if (registerArr[instruction.typeR.source] <= registerArr[instruction.typeR.source2]){
            registerArr[instruction.typeR.destination] = 1;
        }else{
            registerArr[instruction.typeR.destination] = 0;
        }
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_tgt(binInstruction_t instruction)
{
    if (check_opcode_typeR(instruction) == SUCCESS && check_three_registers_typeR(instruction) == SUCCESS){
        if (registerArr[instruction.typeR.source] > registerArr[instruction.typeR.source2]){
            registerArr[instruction.typeR.destination] = 1;
        }else{
            registerArr[instruction.typeR.destination] = 0;
        }
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_tge(binInstruction_t instruction)
{
    if (check_opcode_typeR(instruction) == SUCCESS && check_three_registers_typeR(instruction) == SUCCESS){
        if (registerArr[instruction.typeR.source] >= registerArr[instruction.typeR.source2]){
            registerArr[instruction.typeR.destination] = 1;
        }else{
            registerArr[instruction.typeR.destination] = 0;
        }
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_teq(binInstruction_t instruction)
{
    if (check_opcode_typeR(instruction) == SUCCESS && check_three_registers_typeR(instruction) == SUCCESS){
        if (registerArr[instruction.typeR.source] == registerArr[instruction.typeR.source2]){
            registerArr[instruction.typeR.destination] = 1;
        }else{
            registerArr[instruction.typeR.destination] = 0;
        }
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_tne(binInstruction_t instruction)
{
    if (check_opcode_typeR(instruction) == SUCCESS && check_three_registers_typeR(instruction) == 0){
        if (registerArr[instruction.typeR.source] != registerArr[instruction.typeR.source2]){
            registerArr[instruction.typeR.destination] = 1;
        }else{
            registerArr[instruction.typeR.destination] = 0;
        }
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_str(binInstruction_t instruction)
{
    if (check_opcode_typeR(instruction) == SUCCESS && check_two_registers_typeR(instruction) == SUCCESS){
        registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source];
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_ld(binInstruction_t instruction)
{
    if (check_opcode_typeR(instruction) == SUCCESS && check_two_registers_typeR(instruction) == SUCCESS){
        registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source];
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_strp(binInstruction_t instruction)
{
    if (check_opcode_typeR(instruction) == SUCCESS && check_two_registers_typeR(instruction) == SUCCESS){
        registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source];
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_ldp(binInstruction_t instruction)
{
    if (check_opcode_typeR(instruction) == SUCCESS && check_two_registers_typeR(instruction) == SUCCESS){
        registerArr[instruction.typeR.destination] = registerArr[instruction.typeR.source];
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_push(binInstruction_t instruction)
{
    check_opcode_typeR(instruction);
    uint32_t address = registerArr[STACK_POINTER];
    set_memory_32(address, registerArr[instruction.typeR.source]);
    registerArr[STACK_POINTER] -= 4;
    return SUCCESS;
}

int instr_pop(binInstruction_t instruction)
{
    check_opcode_typeR(instruction);
    registerArr[STACK_POINTER] += 4;
    uint32_t address = registerArr[STACK_POINTER];
    registerArr[instruction.typeR.destination] = read_memory_32(address);
    return SUCCESS;
}

int instr_xchg(binInstruction_t instruction)
{
    if (check_opcode_typeR(instruction) == SUCCESS && check_three_registers_typeR(instruction) == SUCCESS){
        uint32_t internal = registerArr[instruction.typeR.source];
        registerArr[instruction.typeR.source] = registerArr[instruction.typeR.source2];
        registerArr[instruction.typeR.source2] = internal;
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_addi(binInstruction_t instruction)
{
    if (check_opcode_typeI(instruction) == SUCCESS && check_registers_typeI(instruction) == SUCCESS){
        registerArr[instruction.typeI.destination] = registerArr[instruction.typeI.source] + instruction.typeI.immediate;
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_subi(binInstruction_t instruction)
{
    if (check_opcode_typeI(instruction) == SUCCESS && check_registers_typeI(instruction) == SUCCESS){
        registerArr[instruction.typeI.destination] = registerArr[instruction.typeI.source] - instruction.typeI.immediate;
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_stri(binInstruction_t instruction)
{
    if (check_opcode_typeI(instruction) == SUCCESS && check_destination_typeI(instruction) == SUCCESS){
        registerArr[instruction.typeI.destination] = instruction.typeI.immediate;
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_ldi(binInstruction_t instruction)
{
    if (check_opcode_typeI(instruction) == SUCCESS && check_destination_typeI(instruction) == SUCCESS){
        registerArr[instruction.typeI.destination] = instruction.typeI.immediate;
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_ori(binInstruction_t instruction)
{
    if (check_opcode_typeI(instruction) == SUCCESS && check_registers_typeI(instruction) == SUCCESS){
        registerArr[instruction.typeI.destination] = registerArr[instruction.typeI.source] | instruction.typeI.immediate;
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_andi(binInstruction_t instruction)
{
    if (check_opcode_typeI(instruction) == SUCCESS && check_registers_typeI(instruction) == SUCCESS){
        registerArr[instruction.typeI.destination] = registerArr[instruction.typeI.source] & instruction.typeI.immediate;
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_xori(binInstruction_t instruction)
{
    if (check_opcode_typeI(instruction) == SUCCESS && check_registers_typeI(instruction) == SUCCESS){
        registerArr[instruction.typeI.destination] = registerArr[instruction.typeI.source] ^ instruction.typeI.immediate;
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_set(binInstruction_t instruction)
{
    if (check_opcode_typeI(instruction) == SUCCESS && check_source_typeI(instruction) == SUCCESS){
        registerArr[instruction.typeI.destination] = (instruction.typeI.immediate << 5) | instruction.typeI.source;
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_tlti(binInstruction_t instruction)
{
    if (check_opcode_typeI(instruction) == SUCCESS && check_registers_typeI(instruction) == SUCCESS){
        if (registerArr[instruction.typeI.source] < instruction.typeI.immediate) {
            registerArr[instruction.typeI.destination] = 1;
        } else {
            registerArr[instruction.typeI.destination] = 0;
        }
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_tlei(binInstruction_t instruction)
{
    if (check_opcode_typeI(instruction) == SUCCESS && check_registers_typeI(instruction) == SUCCESS){
        if (registerArr[instruction.typeI.source] <= instruction.typeI.immediate) {
            registerArr[instruction.typeI.destination] = 1;
        } else {
            registerArr[instruction.typeI.destination] = 0;
        }
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_tgti(binInstruction_t instruction)
{
    if (check_opcode_typeI(instruction) == SUCCESS && check_registers_typeI(instruction) == SUCCESS){
        if (registerArr[instruction.typeI.source] > instruction.typeI.immediate) {
            registerArr[instruction.typeI.destination] = 1;
        } else {
            registerArr[instruction.typeI.destination] = 0;
        }
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_tgei(binInstruction_t instruction)
{
    if (check_opcode_typeI(instruction) == SUCCESS && check_registers_typeI(instruction) == SUCCESS){
        if (registerArr[instruction.typeI.source] >= instruction.typeI.immediate) {
            registerArr[instruction.typeI.destination] = 1;
        } else {
            registerArr[instruction.typeI.destination] = 0;
        }
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_teqi(binInstruction_t instruction)
{
    if (check_opcode_typeI(instruction) == SUCCESS && check_registers_typeI(instruction) == SUCCESS){
        if (registerArr[instruction.typeI.source] == instruction.typeI.immediate) {
            registerArr[instruction.typeI.destination] = 1;
        } else {
            registerArr[instruction.typeI.destination] = 0;
        }
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_tnei(binInstruction_t instruction)
{
    if (check_opcode_typeI(instruction) == SUCCESS && check_registers_typeI(instruction) == SUCCESS){
        if (registerArr[instruction.typeI.source] != instruction.typeI.immediate) {
            registerArr[instruction.typeI.destination] = 1;
        } else {
            registerArr[instruction.typeI.destination] = 0;
        }
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_b(binInstruction_t instruction)
{
    if (check_opcode_typeJ(instruction) == SUCCESS && check_register_typeJ(instruction) == SUCCESS){
        int32_t address = registerArr[instruction.typeJ.register_] + instruction.typeJ.address;
        registerArr[INSTRUCTION_POINTER] += address << 2;
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_bi(binInstruction_t instruction)
{
    if (check_opcode_typeJ(instruction) == SUCCESS && check_register_typeJ(instruction) == SUCCESS){
        int32_t address = (instruction.typeJ.address);
        registerArr[INSTRUCTION_POINTER] += address << 2;
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_bz(binInstruction_t instruction)
{
    if (check_opcode_typeJ(instruction) == SUCCESS && check_register_typeJ(instruction) == SUCCESS){
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
    }else{
        return GENERIC_ERROR;
    }
}

int instr_bnz(binInstruction_t instruction)
{
    if (check_opcode_typeJ(instruction) == SUCCESS && check_register_typeJ(instruction) == SUCCESS){
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
    }else{
        return GENERIC_ERROR;
    }
}

int instr_call(binInstruction_t instruction)
{
    if (check_opcode_typeJ(instruction) == SUCCESS && check_register_typeJ(instruction) == SUCCESS){
        set_memory_32(registerArr[STACK_POINTER], registerArr[INSTRUCTION_POINTER] + 4);
        registerArr[STACK_POINTER] -= 4;
        int32_t address = registerArr[instruction.typeJ.register_] + instruction.typeJ.address;
        registerArr[INSTRUCTION_POINTER] += address << 2;
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_calli(binInstruction_t instruction)
{
    if (check_opcode_typeJ(instruction) == SUCCESS && check_register_typeJ(instruction) == SUCCESS){
        set_memory_32(registerArr[STACK_POINTER], registerArr[INSTRUCTION_POINTER] + 4);
        registerArr[STACK_POINTER] -= 4;
        int32_t address = (instruction.typeJ.address);
        registerArr[INSTRUCTION_POINTER] += address << 2;
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_ret(binInstruction_t instruction)
{
    if (check_opcode_typeJ(instruction) == SUCCESS && check_register_typeJ(instruction) == SUCCESS){
        if (instruction.typeJ.register_)
        {
            return HALT_PROGRAM;
        }
        registerArr[STACK_POINTER] += 4;
        uint32_t address = registerArr[STACK_POINTER];
        registerArr[INSTRUCTION_POINTER] = read_memory_32(address);
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

int instr_jmp(binInstruction_t instruction)
{
    if (check_opcode_typeJ(instruction) == SUCCESS && check_register_typeJ(instruction) == SUCCESS){
        registerArr[INSTRUCTION_POINTER] = instruction.typeJ.address << 2;
        return SUCCESS;
    }else{
        return GENERIC_ERROR;
    }
}

#endif