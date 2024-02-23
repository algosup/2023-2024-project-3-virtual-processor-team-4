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
    bool debug = false;

    // Parse arguments

    char opt;
    while((opt = getopt(argc, argv, "d")) != -1)
    {
        switch(opt)
        {
            case 'd':
                debug = true;
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

    if (debug)
    {
        for (int i = 0; i < 26; i++)
        {
            printf("r%c: 0x%08x (%ld)\n", i+'a', registerArr[i], registerArr[i]);
        }
        printf("sp: 0x%08x (%lu)\n", registerArr[STACK_POINTER], registerArr[STACK_POINTER]);
        printf("ip: 0x%08x (%lu)\n", registerArr[INSTRUCTION_POINTER], registerArr[INSTRUCTION_POINTER]);
    }

    return EXIT_SUCCESS;
}