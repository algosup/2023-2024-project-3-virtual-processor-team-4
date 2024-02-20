#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include <pthread.h>
#include "./libs/utils.h"

#include "./libs/assembler.h"
#include "./libs/preprocessor.h"

// #define TARGET_OPS_PER_SEC 10000

// Global vars for sync between threads
pthread_mutex_t mutex;
long long int loopCounter = 0;
int operationsCounter = 0;

// Funtion to use processor time and set a more consistent clock
void performWorkload()
{
    while (1)
    {

        for (int i = 0; i < 58000; ++i)
        {
        }

        pthread_mutex_lock(&mutex);
        operationsCounter++;
        pthread_mutex_unlock(&mutex);
    }
}

// Function to print the operations per second
void printOperations()
{
    while (1)
    {
        sleep(1);
        pthread_mutex_lock(&mutex);
        int opsInLastSecond = operationsCounter;
        operationsCounter = 0;
        pthread_mutex_unlock(&mutex);

        printf("Operations performed in the last second: %d\n", opsInLastSecond);
    }
}

int main()
{
    system("cls");
    printf("Welcome to the Team 4 virtual processor interpreter!\n"); // Notify we enter into the processor interpreter
                                                                      // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_t workloadThread, printThread;

    // Create thread for clock workload
    if (pthread_create(&workloadThread, NULL, (void *)performWorkload, NULL) != 0)
    {
        perror("Error creating workload thread");
        return 1;
    }

    // Create thread for printing operations
    // if (pthread_create(&printThread, NULL, (void *)printOperations, NULL) != 0)
    // {
    //     perror("Error creating print thread");
    //     return 1;
    // }

    while (true)
    {
        printf("\n> ");
        char filename[100]; // File name in input
        scanf("%s", filename);
        for (int i = 0; filename[i]; i++)
        {
            filename[i] = tolower(filename[i]);
        } // convert to lowercase

        if (strcmp(&filename[strlen(filename) - 4], ".asm") != 0)
        {
            strcat(filename, ".asm");
        }

        int i = 0;
        if (get_file_size(filename, &i) != 0)
        {
            continue; // Go back to the beginning of the loop
        }
        else
        {
            char *content;
            int lineCount = 1; // File has at least one line if it exists

            content = (char *)malloc((i + 1) * sizeof(char));
            char *outputContent = (char *)malloc((i + 1) * sizeof(char));

            read_file(filename, content, i, &lineCount);
            bool fileHasError = false;

            for (int j = 0; j < lineCount; j++)
            {
                // malloc line content
                char *lineContent = malloc(100 * sizeof(char));

                line_content_from_file_content(content, j, lineContent);
                line_t *line = malloc(sizeof(line_t));

                if (preprocess_line(lineContent, line, &j) != 0)
                {
                    fileHasError = true;
                    continue;
                }

                // Store in stack
                // execute_instruction(ope);
                free(line);
                free(lineContent);
            }

            if (fileHasError)
            {
                printf("Failed to compile!\n");
                continue;
            }
            else
            {
                printf("Compiled successfully!\n");
                // Function to output the code into .bin file
                //  output_file(filename, outputContent, i);
            }

            free(content);
            free(outputContent); // empty the memory from the
        }
        printf("Done!\n");
    }

    // Wait for threads to finish (this will never happen, as threads run indefinitely)
    pthread_join(workloadThread, NULL);
    pthread_join(printThread, NULL);

    // Cleanup
    pthread_mutex_destroy(&mutex);

    return SUCCESS;
}