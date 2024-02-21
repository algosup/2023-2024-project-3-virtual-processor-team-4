#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "./libs/utils.h"
#include "./libs/preprocessor.h"
#include "./libs/assembler.h"

int main() // int argc, char **argv)
{

    int argc = 2;

    char *fname = "./example.asm";
    char *foutname = "./example";
    char *argv[] = {fname, foutname};
    char *output_file = NULL;
    // Check if we have a source file to compile
    if (argv[1] == NULL)
    {
        printf("Please provide a source file to compile\n");
        return 1;
    };
    // Check if a destination has been provided
    bool destinationProvided = true;
    if (argc < 3 || argv[2] == NULL)
    {
        printf("Did you know? You can provide a third parameter to name your object file?\n");
        destinationProvided = false;
    }
    else
    {
        output_file = malloc(strlen(argv[2]) + 1);
        strcpy(output_file, argv[2]);
    }

    char *input_file = malloc(strlen(argv[1]) + 1);
    strcpy(input_file, argv[1]);

    // Convert input file to lowercase
    for (int i = 0; i < strlen(input_file); i++)
    {
        input_file[i] = tolower(input_file[i]);
    } // convert to lowercase

    if (strcmp(&input_file[strlen(input_file) - 4], ".asm") != 0)
    {
        strcat(input_file, ".asm");
    }

    uint64_t charCount = 0;

    if (get_file_size(input_file, &charCount) != 0)
    {
        return GENERIC_ERROR; // Break the program if an error occurs (mainly if file doesn't exist)
    }
    else
    {
        uint64_t lineCount = 1; // File has at least one line if it exists

        char *content = malloc((charCount + 1) * sizeof(char));

        read_file(input_file, content, charCount, &lineCount);
        bool fileHasError = false;

        // Allocate memory for instructionMap
        line_t *instructionMap = malloc((lineCount) * sizeof(line_t));

        if (instructionMap == NULL)
        {
            printf("Failed to allocate memory for instruction map\n");
            return 1;
        }

        for (uint64_t j = 0; j < lineCount; j++)
        {
            // malloc line content
            char *lineContent = malloc(100 * sizeof(char));

            line_content_from_file_content(content, j, lineContent);

            printf("Line %d: %s\n", j, lineContent);

            if (preprocess_line(lineContent, &instructionMap[j], &j) != 0)
            {
                fileHasError = true;
                continue; // Go to next line
            }

            line_t test = instructionMap[j];

            free(lineContent);
        }

        if (fileHasError)
        {
            printf("Failed to compile!\n");
            return GENERIC_ERROR;
        }
        else
        {
            int resCode = iterate_through_all_line(instructionMap, lineCount);
            if (resCode != 0)
            {
                printf("Failed to compile!\n");
                return GENERIC_ERROR;
            }
            else
            {
                printf("Compiled successfully!\n");
            }
        }

        free(instructionMap); // Free the array itself

        // Free file content
        free(content);
    }

    return SUCCESS;
}
