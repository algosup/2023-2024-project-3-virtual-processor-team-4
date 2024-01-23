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

int parse_content(const char *content)
{
    char str1[5], str2[10], str3[10];
    int offset = 0, read;
    while (sscanf(content + offset, "%s %s %s%n", str1, str2, str3, &read) == 3)
    {
        printf("%s\n%s\n%s\n", str1, str2, str3);
        offset += read;
    }
    return SUCCESS;
}

int parse_content_one_line(char *line_content, instruction_t *operation)
{
    if (line_content == NULL)
    {
        printf("line_content is NULL\n");
        return GENERIC_ERROR; // Return an error code
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
    operation->instT = *word1;
    operation->val1 = word2;
    operation->val2 = word3;
    return SUCCESS;
}

int read_file(char *filename, char *output, int size)
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
        output[count] = ch;
        count++;
    }

    output[count - 1] = '\0';

    fclose(ptr);
    return SUCCESS;
}

int line_content_from_file_content(char *content, int *line_number, char *line_content)
{
    // Returns the content of the line_number unitl next \n
    int i = 0;
    if (content == NULL)
    {
        printf("content is NULL\n");
        return GENERIC_ERROR;
    }

    int content_length = strlen(content);
    if (*line_number >= content_length)
    {
        printf("line_number is out of bounds\n");
        return GENERIC_ERROR;
    }

    while (*line_number < content_length && content[*line_number] != '\n')
    {
        line_content[i] = content[*line_number];
        i++;
        *line_number += 1;
    }
    line_content[i] = '\0';
    *line_number += 1;
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
            content = (char *)malloc(i * sizeof(char));
            read_file(filename, content, i);
            int j = 0;
            for (int j = 0; j < 10; j++)
            {
                char line_content[25];
                line_content_from_file_content(content, &j, line_content);
                instruction_t *ope = malloc(sizeof(instruction_t));
                parse_content_one_line(line_content, ope);
            }
            // free(content);
        }
    }
    return SUCCESS;
}