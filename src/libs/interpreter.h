#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "utils.h"
#include "memory.h"

int read_bin(char*, uint8_t**, uint32_t*);
int load_bin_to_mem(char*);
int machinecode_to_bininstruction(uint32_t, binInstruction_t*);
int opcode_type_I(binInstruction_t*, uint8_t, uint8_t, uint8_t, int16_t);
int opcode_type_J(binInstruction_t*, uint8_t, uint8_t, int32_t);
int opcode_type_R(binInstruction_t*, uint8_t, uint8_t, uint8_t, uint8_t);
int execute_instr(binInstruction_t);

int read_bin(char* inputFile, uint8_t** outputPtr, uint32_t* size){
    FILE *f = fopen(inputFile, "rb");
    if (f == NULL) {
        perror("Error: Failed to open file");
        return FILE_NOT_FOUND;
    }

    fseek(f, 0, SEEK_END);
    *size = ftell(f);
    rewind(f);

    // Adjust allocation size for uint32_t and ensure it is a multiple of 4
    long adjustedSize = *size - (*size % 4);
    if(adjustedSize != *size){
        printf("Warning: Total number of bytes should be divisible by 4 but is not.");
    }
    *outputPtr = (uint8_t*)malloc(sizeof(uint8_t) * (adjustedSize));
    if (*outputPtr == NULL) {
        perror("Error: Memory allocation failed");
        fclose(f);
        return GENERIC_ERROR;
    }

    size_t read = fread(*outputPtr, 1, adjustedSize, f);
    if (read < adjustedSize) {
        perror("Error: Failed to read file");
        free(*outputPtr);
        fclose(f);
        return GENERIC_ERROR;
    }

    fclose(f);

    return SUCCESS;
}

int load_bin_to_mem(char* inputFile){
    uint8_t* outputPtr;
    uint32_t size;
    read_bin(inputFile, &outputPtr, &size);

    size_t i = 0;
    for (i;i <= size; i++)
    {
        set_memory_8(i, outputPtr[i]);
    }
    
    free(outputPtr);

    return SUCCESS;
}

int machinecode_to_bininstruction(uint32_t bytes, binInstruction_t* instruction){
    uint8_t opcode;

    uint8_t source = (bytes >> 5) & 0b11111;
    uint8_t dest = bytes & 0b11111;

    if(bytes & 0x80000000){
        // every type J instruction has the first bit set
        instruction->type = J;
        opcode = bytes >> 28;
        int32_t address = bytes & 0x08000000 ? 0xFFC00000 : 0;
        address |= (bytes >> 5) & 0x003FFFFF;
        return opcode_type_J(instruction, opcode, dest, address);
    } else if(bytes & 0x40000000) {
        // every type I instruction has first bit unset and second bit set
        instruction->type = I;
        opcode = bytes >> 26;
        int16_t immediate = bytes >> 10;
        return opcode_type_I(instruction, opcode, source, dest, immediate);
    }else{
        instruction->type = R;
        opcode = bytes >> 25;
        uint8_t source2 = (bytes >> 10) & 0b11111;
        return opcode_type_R(instruction, opcode, source, source2, dest);
    } 
};

int opcode_type_I(binInstruction_t* instruction, uint8_t opcode, uint8_t source, uint8_t dest, int16_t immediate){

    instruction->typeI.source = source;
    instruction->typeI.destination = dest;
    instruction->typeI.immediate = immediate;

    switch (opcode)
    {
    case 0b010000:
        instruction->typeI.opcode = ADDI;
        break;
    case 0b010101:
        instruction->typeI.opcode = ANDI;
        break;
    case 0b010011:
        instruction->typeI.opcode = LDI;
        break;
    case 0b010100:
        instruction->typeI.opcode = ORI;
        break;
    case 0b010111:
        instruction->typeI.opcode = SET;
        break;
    case 0b010010:
        instruction->typeI.opcode = STRI;
        break;
    case 0b010001:
        instruction->typeI.opcode = SUBI;
        break;
    case 0b011100:
        instruction->typeI.opcode = TEQI;
        break;
    case 0b011010:
        instruction->typeI.opcode = TGEI;
        break;
    case 0b011011:
        instruction->typeI.opcode = TGTI;
        break;
    case 0b011001:
        instruction->typeI.opcode = TLEI;
        break;
    case 0b011000:
        instruction->typeI.opcode = TLTI;
        break;
    case 0b011101:
        instruction->typeI.opcode = TNEI;
        break;
    case 0b010110:
        instruction->typeI.opcode = XORI;
        break;
    default:
        printf("Error: Invalid machine code operand\n");
        return GENERIC_ERROR;
    }

    return SUCCESS;
};

int opcode_type_J(binInstruction_t* instruction, uint8_t opcode, uint8_t dest, int32_t address){
    instruction->typeJ.register_ = dest;
    instruction->typeJ.address = address;

    switch (opcode)
    {
    case 0b1000:
        instruction->typeJ.opcode = B;
        break;
    case 0b1001:
        instruction->typeJ.opcode = BI;
        break;
    case 0b1011:
        instruction->typeJ.opcode = BNZ;
        break;
    case 0b1010:
        instruction->typeJ.opcode = BZ;
        break;
    case 0b1100:
        instruction->typeJ.opcode = CALL;
        break;
    case 0b1101:
        instruction->typeJ.opcode = CALLI;
        break;
    case 0b1111:
        instruction->typeJ.opcode = JMP;
        break;
    case 0b1110:
        instruction->typeJ.opcode = RET;
        break;
    default:
        printf("Error: Invalid machine code operand\n");
        return GENERIC_ERROR;
    }
    return SUCCESS;
}

int opcode_type_R(binInstruction_t* instruction, uint8_t opcode, uint8_t source, uint8_t source2, uint8_t dest){
    instruction->typeR.source = source;
    instruction->typeR.source2 = source2;
    instruction->typeR.destination = dest;

    switch (opcode)
    {
    case 0b0000111:
        instruction->typeR.opcode = ABS;
        break;
    case 0b0000000:
        instruction->typeR.opcode = ADD;
        break;
    case 0b0000101:
        instruction->typeR.opcode = AND;
        break;
    case 0b0000011:
        instruction->typeR.opcode = DIV;
        break;
    case 0b0010001:
        instruction->typeR.opcode = LD;
        break;
    case 0b0010011:
        instruction->typeR.opcode = LDP;
        break;
    case 0b0000010:
        instruction->typeR.opcode = MUL;
        break;
    case 0b0000100:
        instruction->typeR.opcode = OR;
        break;
    case 0b0010101:
        instruction->typeR.opcode = POP;
        break;
    case 0b0010100:
        instruction->typeR.opcode = PUSH;
        break;
    case 0b0010000:
        instruction->typeR.opcode = STR;
        break;
    case 0b0010010:
        instruction->typeR.opcode = STRP;
        break;
    case 0b0000001:
        instruction->typeR.opcode = SUB;
        break;
    case 0b0001100:
        instruction->typeR.opcode = TEQ;
        break;
    case 0b0001011:
        instruction->typeR.opcode = TGE;
        break;
    case 0b0001010:
        instruction->typeR.opcode = TGT;
        break;
    case 0b0001001:
        instruction->typeR.opcode = TLE;
        break;
    case 0b0001000:
        instruction->typeR.opcode = TLT;
        break;
    case 0b0001101:
        instruction->typeR.opcode = TNE;
        break;
    case 0b0010110:
        instruction->typeR.opcode = XCHG;
        break;
    case 0b0000110:
        instruction->typeR.opcode = XOR;
        break;
    default:
        printf("Error: Invalid machine code operand\n");
        return GENERIC_ERROR;
    }
    return SUCCESS;
}

int execute_instr(binInstruction_t instruction)
{
    switch (instruction.type)
    {
        case (R):
            switch (instruction.typeR.opcode)
            {
                case ADD:
                    return instr_add(instruction);
                case SUB:
                    return instr_sub(instruction);
                case MUL:
                    return instr_mul(instruction);
                case DIV:
                    return instr_div(instruction);
                case OR:
                    return instr_or(instruction);
                case AND:
                    return instr_and(instruction);
                case XOR:
                    return instr_xor(instruction);
                case ABS:
                    return instr_abs(instruction);
                case TLT:
                    return instr_tlt(instruction);
                case TLE:
                    return instr_tle(instruction);
                case TGT:
                    return instr_tgt(instruction);
                case TGE:
                    return instr_tge(instruction);
                case TEQ:
                    return instr_teq(instruction);
                case TNE:
                    return instr_tne(instruction);
                case STR:
                    return instr_str(instruction);
                case LD:
                    return instr_ld(instruction);
                case STRP:
                    return instr_strp(instruction);
                case LDP:
                    return instr_ldp(instruction);
                case PUSH:
                    return instr_push(instruction);
                case POP:
                    return instr_pop(instruction);
                case XCHG:
                    return instr_xchg(instruction);
                default:
                    break;
            }
            break;

        case (I):
            switch (instruction.typeI.opcode)
            {
                case ADDI:
                    return instr_addi(instruction);
                case SUBI:
                    return instr_subi(instruction);
                case STRI:
                    return instr_stri(instruction);
                case LDI:
                    return instr_ldi(instruction);
                case ORI:
                    return instr_ori(instruction);
                case ANDI:
                    return instr_andi(instruction);
                case XORI:
                    return instr_xori(instruction);
                case SET:
                    return instr_set(instruction);
                case TLTI:
                    return instr_tlti(instruction);
                case TLEI:
                    return instr_tlei(instruction);
                case TGTI:
                    return instr_tgti(instruction);
                case TGEI:
                    return instr_tgei(instruction);
                case TEQI:
                    return instr_teqi(instruction);
                case TNEI:
                    return instr_tnei(instruction);
                default:
                    break;
            }
            break;
        
        case (J):
            switch (instruction.typeJ.opcode)
            {
                case B:
                    return instr_b(instruction);
                case BI:
                    return instr_bi(instruction);
                case BZ:
                    return instr_bz(instruction);
                case BNZ:
                    return instr_bnz(instruction);
                case CALL:
                    return instr_call(instruction);
                case CALLI:
                    return instr_calli(instruction);
                case RET:
                    return instr_ret(instruction);
                case JMP:
                    return instr_jmp(instruction);
                default:
                    break;
            }
            break;

        default:
            break;
    }
    return GENERIC_ERROR;
}

#endif