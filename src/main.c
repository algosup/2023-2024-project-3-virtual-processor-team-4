#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "./libs/interpret.h"
#include "./libs/file.h"

int main()
{
    while (true)
    {
        printf("> ");
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
            int line_count = 0;
            content = (char *)malloc((i + 1) * sizeof(char));
            read_file(filename, content, i, &line_count);
            for (int j = 0; j < line_count; j++)
            {
                char line_content[25];
                line_content_from_file_content(content, j, line_content);
                instruction_t *ope = malloc(sizeof(instruction_t));
                parse_content_one_line(line_content, ope, &j);
                free(ope);
            }

            free(content);
        }
        printf("\n");
    }
    return SUCCESS;
}