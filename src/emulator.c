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

    // Execution

    // TODO: Execute the file
    puts(filepath); // TEMP

    return EXIT_SUCCESS;
}