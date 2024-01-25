#ifndef FILE_H
#define FILE_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "interpret.h"
#include "utils.h"

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
    else
    {
        *instruction = NOOP; // Not found returns NOOP
    }
    return 0;
};

int parse_content_one_line(char *line_content, instruction_t *operation, int *line_number)
{
    if (line_content[0] == '/' && line_content[1] == '/') // Check if the line is empty or a comment
    {
        operation->instT = NOOP;
        operation->line = *line_number;
        operation->val1 = NULL;
        operation->val2 = NULL;
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
    else
    {
        word1 = "noop";
    }

    // Extract the second word
    if (token != NULL)
    {
        word2 = token;
        token = strtok(NULL, " ");
    }
    else
    {
        word2 = NULL;
    }

    // Extract the third word
    if (token != NULL)
    {
        word3 = token;
    }
    else
    {
        word3 = NULL;
    }

    InstructionType_t *instType = malloc(sizeof(InstructionType_t)); // check for free afterwhile
    findOperand(word1, instType);
    operation->instT = *instType;
    operation->line = *line_number;
    operation->val1 = word2;
    operation->val2 = word3;
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
        printf("Content is NULL\n");
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

int isLineHavingErrors(instruction_t *instruction, int *line_number)
{
    switch (instruction->instT)
    {
    case NOOP:
        if (instruction->val1 != NULL || instruction->val2 != NULL)
        {
            printf("Error: noop instruction has operands on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        break;
    case SET:
        if (instruction->val1 == NULL || instruction->val2 == NULL)
        {
            printf("Error: set instruction is missing an operand on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val1[0] != 'r')
        {
            printf("Error: set instruction first operator is not a register on line %d\n", *line_number);
            return GENERIC_ERROR;
        }

        if ((instruction->val1[1] < '0' || instruction->val1[1] > '9') && (instruction->val1[1] < 'A' || instruction->val1[1] > 'F') && (instruction->val1[1] < 'a' || instruction->val1[1] > 'f') || strlen(instruction->val1) != 2)
        {
            printf("Error: set instruction first operator is not an existing register on range R0 -> R9 and range RA -> RF on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val2[0] == 'r' && ((instruction->val2[1] >= '0' || instruction->val2[1] <= '9') || (instruction->val2[1] >= 'A' || instruction->val2[1] <= 'F') || (instruction->val2[1] >= 'a' || instruction->val2[1] <= 'f')))
        {
            printf("Error: set instruction second operator is a register, instead should be an immediate value on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        break;
    case COPY:
        if (instruction->val1 == NULL)
        {
            printf("Error: copy instruction is missing operands on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val2 == NULL)
        {
            printf("Error: copy instruction is missing its second operand on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val1[0] != 'r')
        {
            printf("Error: copy instruction first operator is not a register on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val2[0] != 'r')
        {
            printf("Error: copy instruction second operator is not a register on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if ((instruction->val1[1] < '0' || instruction->val1[1] > '9') && (instruction->val1[1] < 'A' || instruction->val1[1] > 'F') && (instruction->val1[1] < 'a' || instruction->val1[1] > 'f') || strlen(instruction->val1) != 2)
        {
            printf("Error: copy instruction first operator is not an existing register on range R0 -> R9 and range RA -> RF on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (((instruction->val2[1] < '0' || instruction->val2[1] > '9') ||
             (instruction->val2[1] < 'A' || instruction->val2[1] > 'F') ||
             (instruction->val2[1] < 'a' || instruction->val2[1] > 'f')) &&
            strlen(instruction->val2) != 2 && strcmp(instruction->val2, "sp") != 0 && strcmp(instruction->val2, "ln") != 0)
        {
            printf("Error: copy instruction second operator is not a register, sp or ln on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        break;
    case LOAD: // Should add checks for memory addresses
        if (instruction->val1 == NULL)
        {
            printf("Error: load instruction is missing operands on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val2 == NULL)
        {
            printf("Error: load instruction is missing its second operand on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val1[0] != 'r')
        {
            printf("Error: load instruction first operator is not a register on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if ((instruction->val1[1] < '0' || instruction->val1[1] > '9') && (instruction->val1[1] < 'A' || instruction->val1[1] > 'F') && (instruction->val1[1] < 'a' || instruction->val1[1] > 'f') || strlen(instruction->val1) != 2)
        {
            printf("Error: load instruction first operator is not an existing register on range R0 -> R9 and range RA -> RF on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if ((instruction->val2[0] != 'r' && (instruction->val2[1] < '0' || instruction->val2[1] > '9') && (instruction->val2[1] < 'A' || instruction->val2[1] > 'F') && (instruction->val2[1] < 'a' || instruction->val2[1] > 'f') || strlen(instruction->val2) != 2) || isdigit(instruction->val2[0]) == 0)
        {
            printf("Error: load instruction second operator is not an existing register on range R0 -> R9 and range RA -> RF on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        break;
    case STORE: // Should add checks for memory addresses
        if (instruction->val1 == NULL)
        {
            printf("Error: STORE instruction is missing operands on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val2 == NULL)
        {
            printf("Error: STORE instruction is missing its second operand on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if ((instruction->val1[0] != 'r' && (instruction->val1[1] < '0' || instruction->val1[1] > '9') && (instruction->val1[1] < 'A' || instruction->val1[1] > 'F') && (instruction->val1[1] < 'a' || instruction->val1[1] > 'f') || strlen(instruction->val1) != 2) || isdigit(instruction->val1[0]) == 0)
        {
            printf("Error: store instruction FISRT operator is not an existing register on range R0 -> R9 and range RA -> RF on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if ((instruction->val2[0] != 'r' && (instruction->val2[1] < '0' || instruction->val2[1] > '9') && (instruction->val2[1] < 'A' || instruction->val2[1] > 'F') && (instruction->val2[1] < 'a' || instruction->val2[1] > 'f') || strlen(instruction->val2) != 2) || isdigit(instruction->val2[0]) == 0)
        {
            printf("Error: store instruction second operator is not an existing register on range R0 -> R9 and range RA -> RF on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        break;
    case ADD:
        if (instruction->val1 == NULL)
        {
            printf("Error: add instruction is missing operands on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val2 == NULL)
        {
            printf("Error: add instruction is missing its second operand on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val1[0] != 'r')
        {
            printf("Error: add instruction first operator is not a register on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if ((instruction->val1[1] < '0' || instruction->val1[1] > '9') && (instruction->val1[1] < 'A' || instruction->val1[1] > 'F') && (instruction->val1[1] < 'a' || instruction->val1[1] > 'f') || strlen(instruction->val1) != 2)
        {
            printf("Error: add instruction first operator is not an existing register on range R0 -> R9 and range RA -> RF on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        // if ((instruction->val2[0] != 'r' || (instruction->val2[1] < '0' || instruction->val2[1] > '9') && (instruction->val2[1] < 'A' || instruction->val2[1] > 'F') && (instruction->val2[1] < 'a' || instruction->val2[1] > 'f') || strlen(instruction->val2) != 2) || isdigit(instruction->val2[0]) == 0)
        // {
        //     printf("Error: add instruction second operator is not an existing register on range R0 -> R9 and range RA -> RF on line %d\n", *line_number);
        //     return GENERIC_ERROR;
        // } // Checks between register and immediate value to be adressed
        break;
    case SUB:
        if (instruction->val1 == NULL)
        {
            printf("Error: sub instruction is missing operands on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val2 == NULL)
        {
            printf("Error: sub instruction is missing its second operand on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val1[0] != 'r')
        {
            printf("Error: sub instruction first operator is not a register on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if ((instruction->val1[1] < '0' || instruction->val1[1] > '9') && (instruction->val1[1] < 'A' || instruction->val1[1] > 'F') && (instruction->val1[1] < 'a' || instruction->val1[1] > 'f') || strlen(instruction->val1) != 2)
        {
            printf("Error: sub instruction first operator is not an existing register on range R0 -> R9 and range RA -> RF on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        // if ((instruction->val2[0] != 'r' && (instruction->val2[1] < '0' || instruction->val2[1] > '9') && (instruction->val2[1] < 'A' || instruction->val2[1] > 'F') && (instruction->val2[1] < 'a' || instruction->val2[1] > 'f') || strlen(instruction->val2) != 2) || isdigit(instruction->val2[0]) == 0)
        // {
        //     printf("Error: sub instruction second operator is not an existing register on range R0 -> R9 and range RA -> RF on line %d\n", *line_number);
        //     return GENERIC_ERROR;
        // } // Checks between register and immediate value to be adressed
        break;
    case MUL:
        if (instruction->val1 == NULL)
        {
            printf("Error: mul instruction is missing operands on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val2 == NULL)
        {
            printf("Error: mul instruction is missing its second operand on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val1[0] != 'r')
        {
            printf("Error: mul instruction first operator is not a register on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val2[0] != 'r')
        {
            printf("Error: mul instruction second operator is not a register on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if ((instruction->val1[1] < '0' || instruction->val1[1] > '9') && (instruction->val1[1] < 'A' || instruction->val1[1] > 'F') && (instruction->val1[1] < 'a' || instruction->val1[1] > 'f') || strlen(instruction->val1) != 2)
        {
            printf("Error: mul instruction first operator is not an existing register on range R0 -> R9 and range RA -> RF on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if ((instruction->val2[1] < '0' || instruction->val2[1] > '9') &&
            (instruction->val2[1] < 'A' || instruction->val2[1] > 'F') &&
            (instruction->val2[1] < 'a' || instruction->val2[1] > 'f'))
        {
            printf("Error: mul instruction second operator is not a register, sp or ln on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        break;
    case DIV:
        if (instruction->val1 == NULL)
        {
            printf("Error: div instruction is missing operands on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val2 == NULL)
        {
            printf("Error: div instruction is missing its second operand on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val1[0] != 'r')
        {
            printf("Error: div instruction first operator is not a register on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val2[0] != 'r')
        {
            printf("Error: div instruction second operator is not a register on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if ((instruction->val1[1] < '0' || instruction->val1[1] > '9') && (instruction->val1[1] < 'A' || instruction->val1[1] > 'F') && (instruction->val1[1] < 'a' || instruction->val1[1] > 'f') || strlen(instruction->val1) != 2)
        {
            printf("Error: div instruction first operator is not an existing register on range R0 -> R9 and range RA -> RF on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if ((instruction->val2[1] < '0' || instruction->val2[1] > '9') &&
            (instruction->val2[1] < 'A' || instruction->val2[1] > 'F') &&
            (instruction->val2[1] < 'a' || instruction->val2[1] > 'f'))
        {
            printf("Error: div instruction second operator is not a register, sp or ln on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        break;
    case NOT:
        if (instruction->val1 == NULL)
        {
            printf("Error: not instruction is missing its operand on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val2 != NULL)
        {
            printf("Error: not instruction has a second operand, but instead, should have only one on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val1[0] != 'r')
        {
            printf("Error: not instruction first operator is not a register on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if ((instruction->val1[1] < '0' || instruction->val1[1] > '9') && (instruction->val1[1] < 'A' || instruction->val1[1] > 'F') && (instruction->val1[1] < 'a' || instruction->val1[1] > 'f') || strlen(instruction->val1) != 2)
        {
            printf("Error: not instruction first operator is not an existing register on range R0 -> R9 and range RA -> RF on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        break;
    case AND:
        if (instruction->val1 == NULL)
        {
            printf("Error: and instruction is missing operands on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val2 == NULL)
        {
            printf("Error: and instruction is missing its second operand on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val1[0] != 'r')
        {
            printf("Error: and instruction first operator is not a register on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if ((instruction->val1[1] < '0' || instruction->val1[1] > '9') && (instruction->val1[1] < 'A' || instruction->val1[1] > 'F') && (instruction->val1[1] < 'a' || instruction->val1[1] > 'f') || strlen(instruction->val1) != 2)
        {
            printf("Error: and instruction first operator is not an existing register on range R0 -> R9 and range RA -> RF on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        // if ((instruction->val2[0] != 'r' && (instruction->val2[1] < '0' || instruction->val2[1] > '9') && (instruction->val2[1] < 'A' || instruction->val2[1] > 'F') && (instruction->val2[1] < 'a' || instruction->val2[1] > 'f') || strlen(instruction->val2) != 2) || isdigit(instruction->val2[0]) == 0)
        // {
        //     printf("Error: and instruction second operator is not an existing register on range R0 -> R9 and range RA -> RF on line %d\n", *line_number);
        //     return GENERIC_ERROR;
        // } // Checks between register and immediate value to be adressed
        break;
    case OR:
        if (instruction->val1 == NULL)
        {
            printf("Error: or instruction is missing operands on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val2 == NULL)
        {
            printf("Error: or instruction is missing its second operand on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val1[0] != 'r')
        {
            printf("Error: or instruction first operator is not a register on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if ((instruction->val1[1] < '0' || instruction->val1[1] > '9') && (instruction->val1[1] < 'A' || instruction->val1[1] > 'F') && (instruction->val1[1] < 'a' || instruction->val1[1] > 'f') || strlen(instruction->val1) != 2)
        {
            printf("Error: or instruction first operator is not an existing register on range R0 -> R9 and range RA -> RF on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        // if ((instruction->val2[0] != 'r' && (instruction->val2[1] < '0' || instruction->val2[1] > '9') && (instruction->val2[1] < 'A' || instruction->val2[1] > 'F') && (instruction->val2[1] < 'a' || instruction->val2[1] > 'f') || strlen(instruction->val2) != 2) || isdigit(instruction->val2[0]) == 0)
        // {
        //     printf("Error: or instruction second operator is not an existing register on range R0 -> R9 and range RA -> RF on line %d\n", *line_number);
        //     return GENERIC_ERROR;
        // } // Checks between register and immediate value to be adressed
        break;
    case XOR:
        if (instruction->val1 == NULL)
        {
            printf("Error: xor instruction is missing operands on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val2 == NULL)
        {
            printf("Error: xor instruction is missing its second operand on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val1[0] != 'r')
        {
            printf("Error: xor instruction first operator is not a register on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if ((instruction->val1[1] < '0' || instruction->val1[1] > '9') && (instruction->val1[1] < 'A' || instruction->val1[1] > 'F') && (instruction->val1[1] < 'a' || instruction->val1[1] > 'f') || strlen(instruction->val1) != 2)
        {
            printf("Error: xor instruction first operator is not an existing register on range R0 -> R9 and range RA -> RF on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        // if ((instruction->val2[0] != 'r' && (instruction->val2[1] < '0' || instruction->val2[1] > '9') && (instruction->val2[1] < 'A' || instruction->val2[1] > 'F') && (instruction->val2[1] < 'a' || instruction->val2[1] > 'f') || strlen(instruction->val2) != 2) || isdigit(instruction->val2[0]) == 0)
        // {
        //     printf("Error: xor instruction second operator is not an existing register on range R0 -> R9 and range RA -> RF on line %d\n", *line_number);
        //     return GENERIC_ERROR;
        // } // Checks between register and immediate value to be adressed
        break;
    case CMPEQ:
        if (instruction->val1 == NULL)
        {
            printf("Error: cmpeq instruction is missing operands on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val2 == NULL)
        {
            printf("Error: cmpeq instruction is missing its second operand on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val1[0] != 'r')
        {
            printf("Error: cmpeq instruction first operator is not a register on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if ((instruction->val1[1] < '0' || instruction->val1[1] > '9') && (instruction->val1[1] < 'A' || instruction->val1[1] > 'F') && (instruction->val1[1] < 'a' || instruction->val1[1] > 'f') || strlen(instruction->val1) != 2)
        {
            printf("Error: cmpeq instruction first operator is not an existing register on range R0 -> R9 and range RA -> RF on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        // if ((instruction->val2[0] != 'r' && (instruction->val2[1] < '0' || instruction->val2[1] > '9') && (instruction->val2[1] < 'A' || instruction->val2[1] > 'F') && (instruction->val2[1] < 'a' || instruction->val2[1] > 'f') || strlen(instruction->val2) != 2) || isdigit(instruction->val2[0]) == 0)
        // {
        //     printf("Error: cmpeq instruction second operator is not an existing register on range R0 -> R9 and range RA -> RF on line %d\n", *line_number);
        //     return GENERIC_ERROR;
        // } // Checks between register and immediate value to be adressed
        break;
    case CMPGE:
        if (instruction->val1 == NULL)
        {
            printf("Error: cmpge instruction is missing operands on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val2 == NULL)
        {
            printf("Error: cmpge instruction is missing its second operand on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if (instruction->val1[0] != 'r')
        {
            printf("Error: cmpge instruction first operator is not a register on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        if ((instruction->val1[1] < '0' || instruction->val1[1] > '9') && (instruction->val1[1] < 'A' || instruction->val1[1] > 'F') && (instruction->val1[1] < 'a' || instruction->val1[1] > 'f') || strlen(instruction->val1) != 2)
        {
            printf("Error: cmpge instruction first operator is not an existing register on range R0 -> R9 and range RA -> RF on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
        // if ((instruction->val2[0] != 'r' && (instruction->val2[1] < '0' || instruction->val2[1] > '9') && (instruction->val2[1] < 'A' || instruction->val2[1] > 'F') && (instruction->val2[1] < 'a' || instruction->val2[1] > 'f') || strlen(instruction->val2) != 2) || isdigit(instruction->val2[0]) == 0)
        // {
        //     printf("Error: cmpge instruction second operator is not an existing register on range R0 -> R9 and range RA -> RF on line %d\n", *line_number);
        //     return GENERIC_ERROR;
        // } // Checks between register and immediate value to be adressed
        break;
    case JTRUE:
        // Not handled yet in code
        break;
    case JFALSE:
        // Not handled yet in code
        break;
    case JUMP:
        // Not handled yet in code
        break;
    case CALL:
        // Not handled yet in code
        break;
    case RET:
        // Not handled yet in code
        break;
    case HALT:
        // Not handled yet in code
        break;
    case INT:
        // Not handled yet in code
        break;
    default:
        printf("Error: instruction not found\n");
        return GENERIC_ERROR;
        break;
    }
    return SUCCESS;
}
#endif