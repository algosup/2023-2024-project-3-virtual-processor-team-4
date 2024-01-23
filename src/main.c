#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "interpret.h"

typedef enum ErrorType
{
    SUCCESS,
    GENERIC_ERROR,
    FILE_NOT_FOUND,
    CANNOT_ACCESS_FILE,
    INVALID_DATA,
    OUT_OF_MEMORY,
} errorType_t;

int findOperand(char *input, InstructionType_t *instruction)
{
    if (strcmp("noop", input) == 0)
    {
        *instruction = NOOP;
    }
    else if (strcmp("set", input) == 0)
    {
        *instruction = SET;
    }
    else if (strcmp("copy", input) == 0)
    {
        *instruction = COPY;
    }
    else if (strcmp("load", input) == 0)
    {
        *instruction = LOAD;
    }
    else if (strcmp("store", input) == 0)
    {
        *instruction = STORE;
    }
    else if (strcmp("add", input) == 0)
    {
        *instruction = ADD;
    }
    else if (strcmp("sub", input) == 0)
    {
        *instruction = SUB;
    }
    else if (strcmp("mul", input) == 0)
    {
        *instruction = MUL;
    }
    else if (strcmp("div", input) == 0)
    {
        *instruction = DIV;
    }
    else if (strcmp("not", input) == 0)
    {
        *instruction = NOT;
    }
    else if (strcmp("and", input) == 0)
    {
        *instruction = AND;
    }
    else if (strcmp("or", input) == 0)
    {
        *instruction = OR;
    }
    else if (strcmp("xor", input) == 0)
    {
        *instruction = XOR;
    }
    else if (strcmp("input", input) == 0)
    {
        *instruction = INPUT;
    }
    else if (strcmp("output", input) == 0)
    {
        *instruction = OUTPUT;
    }
    else if (strcmp("cmpeq", input) == 0)
    {
        *instruction = CMPEQ;
    }
    else if (strcmp("cmpge", input) == 0)
    {
        *instruction = CMPGE;
    }
    else if (strcmp("jtrue", input) == 0)
    {
        *instruction = JTRUE;
    }
    else if (strcmp("jfalse", input) == 0)
    {
        *instruction = JFALSE;
    }
    else if (strcmp("jump", input) == 0)
    {
        *instruction = JUMP;
    }
    else if (strcmp("call", input) == 0)
    {
        *instruction = CALL;
    }
    else if (strcmp("ret", input) == 0)
    {
        *instruction = RET;
    }
    else if (strcmp("halt", input) == 0)
    {
        *instruction = HALT;
    }
    else if (strcmp("int", input) == 0)
    {
        *instruction = INT;
    }

    return 0;
};

int parse_content_one_line(char *line_content, instruction_t *operation, int *line_number)
{
    if (strcmp(line_content, "") == 0 || line_content == NULL || line_content == "") // Check if the line is empty
    {
        return SUCCESS;
    }
    char *token = strtok(line_content, " ");
    char *word1, *word2, *word3;

    // Extract the first word
    if (token != NULL)
    {
        word1 = token;
        token = strtok(NULL, " ");
    }

    // Extract the second word
    if (token != NULL)
    {
        word2 = token;
        token = strtok(NULL, " ");
    }

    // Extract the third word
    if (token != NULL)
    {
        word3 = token;
    }
    InstructionType_t *instType = malloc(sizeof(InstructionType_t));
    findOperand(word1, instType);
    operation->instT = *instType;
    operation->val1 = word2;
    operation->val2 = word3;
    operation->line = *line_number;
    return SUCCESS;
}

int read_file(char *filename, char *output, int size, int *number_of_lines)
{
    FILE *ptr;
    char ch;
    ptr = fopen(filename, "r");

    if (ptr == NULL)
    {
        printf("Failed to open file: %s\n\n", filename);
        return FILE_NOT_FOUND;
    }

    int count = 0;
    while (!feof(ptr))
    {
        ch = fgetc(ptr);
        if (ch == '\n')
        {
            *number_of_lines += 1;
        }
        output[count] = ch;
        count++;
    }

    output[count - 1] = '\0';

    fclose(ptr);
    return SUCCESS;
}

int line_content_from_file_content(char *content, int line_number, char *line_content)
{
    // Returns the content of the line_number until next \n
    int i = 0;

    if (content == NULL)
    {
        printf("content is NULL\n");
        return GENERIC_ERROR;
    }

    int content_length = strlen(content);
    if (line_number >= content_length)
    {
        printf("line_number is out of bounds\n");
        return GENERIC_ERROR;
    }

    // Find the starting position of the line
    int current_line = 0;
    while (current_line < line_number)
    {
        if (content[i] == '\n')
        {
            current_line++;
        }
        i++;
    }

    // Store the content of the line in line_content
    int j = 0;
    while (content[i] != '\n' && content[i] != '\0')
    {
        line_content[j++] = content[i++];
    }

    // Add null terminator to line_content
    line_content[j] = '\0';

    return SUCCESS;
}

int get_file_size(char *filename, int *size)
{
    FILE *fp;

    *size = 0;
    char c;

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Could not open file: %s\n\n", filename);
        return FILE_NOT_FOUND;
    }

    for (c = getc(fp); c != EOF; c = getc(fp))
        *size += 1;

    fclose(fp);

    return SUCCESS;
}

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