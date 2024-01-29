#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "./libs/utils.h"
#include "./libs/file.h"
#include "./libs/interpret.h"
#include "./libs/errors.h"

int main()
{
    system("cls");
    printf("Welcome to the Team 4 virtual processor interpreter!\n"); // Notify we enter into the processor interpreter
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
            int line_count = 1; // File has at least one line if it exists
            content = (char *)malloc((i + 1) * sizeof(char));
            char *output_content = (char *)malloc((i + 1) * sizeof(char));
            read_file(filename, content, i, &line_count);
            bool fileHasError = false;
            for (int j = 0; j < line_count; j++)
            {
                // malloc line content
                char *line_content = malloc(100 * sizeof(char));

                line_content_from_file_content(content, j, line_content);
                line_t *line = malloc(sizeof(line_t));
                if (preprocess_line(line_content, line, &j) != 0)
                {
                    fileHasError = true;
                    continue;
                }
                
                // Store in stack
                // executeInstruction(ope);
                free(line);
                free(line_content);
            }
            if(fileHasError) {
                printf("Failed to compile!\n");
                continue;
            } else {
                printf("Compiled successfully!\n");
                //Function to output the code into .bin file
                // output_file(filename, output_content, i);
            }
            free(content);
            free(output_content);
        }
        printf("Done!\n");
    }
    return SUCCESS;
}