#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "./libs/utils.h"
//#include "./libs/clock.h"
#include "./libs/v_components.h"
#include "./libs/v_instructions.h"
#include "./libs/interpreter.h" //commented while interpreter is not blocking compilation

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

bool running;

int emulate(char *filepath)
{
    int err;

    // Initialize
    init_memory();

    err = load_bin_to_mem(filepath);
    if (err != SUCCESS) return err;

    // Loop until halt
    running = true;
    while (running)
    {
        uint32_t instructionAddress = registerArr[INSTRUCTION_POINTER];

        uint32_t rawInstruction = read_memory_32(instructionAddress);

        binInstruction_t instruction;
        err = machinecode_to_bininstruction(rawInstruction, &instruction);
        if (err != SUCCESS) return err;

        err = execute_instr(instruction);
        if (err == HALT)
        {
            running = false;
            break;
        }

        if (instruction.type != J)
        {
            registerArr[INSTRUCTION_POINTER] += 4;
        }
    }

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    char *filepath = NULL;
    // bool run_tests = false;

    // Parse arguments

    char opt;
    while((opt = getopt(argc, argv, "t")) != -1)
    {
        switch(opt)
        {
            case 't':
                // run_tests = true;
                break;
            case '?':
                errno = EINVAL;
                return EXIT_FAILURE;
            default:
                errno = EINVAL;
                char message[19];
                sprintf(message, "unknown option '%c'", optopt);
                perror(message);
                return EXIT_FAILURE;
        }
    }

    if (optind != argc - 1)
    {
        errno = EINVAL;
        perror("expecting exactly one argument for file path");
        return EXIT_FAILURE;
    }

    filepath = argv[optind];

    int status = emulate(filepath);
    if (status != SUCCESS)
    {
        perror("failed to execute the code");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}