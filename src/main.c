#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <pthread.h> // Include pthread library for threading
#include "./libs/utils.h"
#include "./libs/runtime.h"
#include "./libs/preprocessor.h"
#include "./libs/clock.h"

int main(int argc, char **argv)
{
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

    // ********************** THREADING ************************

    // Initialize mutex for multithreading
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);

    // Create clock thread
    pthread_t clockThread;

    // Create thread for clock workload
    if (pthread_create(&clockThread, NULL, (void *)perform_workload, NULL) != 0)
    {
        perror("Error creating workload thread");
        return 1;
    }

    // ********************** END OF THREADING ************************

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
        uint64_t lineCount = 0; // File has at least one line if it exists

        char *content = malloc((charCount + 1) * sizeof(char));

        read_file(input_file, content, charCount, &lineCount);
        bool fileHasError = false;

        // Allocate memory for instructionMap
        line_t **instructionMap = malloc((lineCount + 1) * sizeof(line_t *));

        if (instructionMap == NULL)
        {
            printf("Failed to allocate memory for instruction map\n");
            return 1;
        }

        for (long long int j = 0; j <= lineCount; j++)
        {
            // malloc line content
            char *lineContent = malloc(100 * sizeof(char));

            line_content_from_file_content(content, j, lineContent);
            line_t *line = malloc(sizeof(line_t));

            if (preprocess_line(lineContent, line, &j) != 0)
            {
                fileHasError = true;
                continue; // Go to next line
            }

            // Assign the pointer to line struct to instructionMap
            instructionMap[j] = line;

            free(lineContent);
        }

        if (fileHasError)
        {
            printf("Failed to compile!\n");
            return GENERIC_ERROR;
        }
        else
        {
            printf("Compiled successfully!\n");
            // Function to write machine code into .o file
        }

        // Free instructionMap memory
        for (long long int j = 0; j <= lineCount; j++)
        {
            free(instructionMap[j]); // Free each line_t struct
        }
        free(instructionMap); // Free the array itself

        // Free file content
        free(content);
    }
    terminateClockThread = true;
    // Wait for threads to finish (this will never happen, as threads run indefinitely)
    pthread_join(clockThread, NULL);

    // Cleanup
    pthread_mutex_destroy(&mutex);

    return SUCCESS;
}
