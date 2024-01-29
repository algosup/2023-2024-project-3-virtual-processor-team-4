#ifndef FILE_H
#define FILE_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

int find_operand(char *input, InstructionType_t *instruction)
{
    if (strcmp("skip", input) == 0)
    {
        *instruction = SKIP;
    }
    else if (strcmp("noop", input) == 0)
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
        return GENERIC_ERROR;
    }
    return SUCCESS;
};

int fill_line_struct(line_t *line, InstructionType_t *instType, char *word2, char *word3, int *lineNumber)
{
    line->mnemonic = *instType;
    line->lineNumber = lineNumber;
    line->labelDeclaration = NULL;
    if (word2 != NULL)
    {
        if (find_register(word2, &line->register1) == SUCCESS)
        {
            line->param1 = REGISTER;
        }
        else if (check_is_number(word2) == SUCCESS)
        {
            line->param1 = IMMEDIAT;
        }
        else if (check_is_label(word2) == SUCCESS)
        {
            line->param1 = LABEL;
            line->labelDeclaration = word2;
        }
    }
    else
    {
        line->param1 = NULL_;
    }
    if (word3 != NULL)
    {
        if (find_register(word3, &line->register2) == SUCCESS)
        {
            line->param2 = REGISTER;
        }
        else if (check_is_number(word3) == SUCCESS)
        {
            line->param2 = IMMEDIAT;
        }
        else
        {
            printf("Error: Invalid operation (unhandled second param) on line %d\n", *lineNumber);
            return GENERIC_ERROR;
        }
    }
    else
    {
        line->param2 = NULL_;
    }
    return SUCCESS;
}

int are_operation_params_valid(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber)
{
    switch (*instructionId)
    {
    case SKIP:
    case NOOP:
        return are_both_operands_null(instructionId, param1, param2, lineNumber);
        break;
    case SET:
        return is_first_operand_register_and_second_operand_immediate(instructionId, param1, param2, lineNumber);
        break;
    case NOT:
        return is_first_operand_register_and_second_operand_null(instructionId, param1, param2, lineNumber);
        break;
    case STORE:
        return are_both_operands_immediate_or_register(instructionId, param1, param2, lineNumber);
        break;
    case COPY:
    case MUL:
    case DIV:
        return are_both_operands_registers(instructionId, param1, param2, lineNumber);
        break;
    case LOAD:
    case ADD:
    case SUB:
    case AND:
    case OR:
    case XOR:
        return is_first_operand_register_and_second_operand_register_or_immediate(instructionId, param1, param2, lineNumber);
        break;
    default:
        printf("Instruction not found");
        return GENERIC_ERROR;
        break;
        // Following instructions are not implemented yet
    }
}

int preprocess_line(char *lineContent, line_t *line, int *lineNumber)
{
    if (lineContent[0] == '/' && lineContent[1] == '/') // Check if the line is a comment
    {
        line->mnemonic = SKIP;
        line->param1 = NULL_;
        line->register1 = NULL_;
        line->lineNumber = lineNumber;
        return SUCCESS;
    }

    char *token = strtok(lineContent, " ");
    char *word1, *word2, *word3;

    // Extract the first word
    if (token != NULL)
    {
        word1 = token;
        token = strtok(NULL, " ");
    }
    else
    {
        word1 = "skip";
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
    if (find_operand(word1, instType) != SUCCESS)
    {
        printf("Error: Invalid operation on line %d\n", *lineNumber);
        line->mnemonic = SKIP;
        line->lineNumber = lineNumber;
        line->param1 = NULL_;
        line->labelDeclaration = NULL;
        return GENERIC_ERROR;
    }
    if (are_operation_params_valid(instType, word2, word3, lineNumber) != SUCCESS)
    {
        line->mnemonic = SKIP;
        line->lineNumber = lineNumber;
        line->param1 = NULL_;
        line->labelDeclaration = NULL;
        return GENERIC_ERROR;
    }
    if (fill_line_struct(line, instType, word2, word3, lineNumber) != SUCCESS)
    {
        return GENERIC_ERROR;
    }
    return SUCCESS;
}

int read_file(char *filename, char *output, int size, int *numberOfLines)
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
            *numberOfLines += 1;
        }
        output[count] = ch;
        count++;
    }

    output[count - 1] = '\0';

    fclose(ptr);
    return SUCCESS;
}

int line_content_from_file_content(char *content, int lineNumber, char *lineContent)
{
    // Returns the content of the lineNumber until next \n
    int i = 0;

    if (content == NULL)
    {
        printf("Content is NULL\n");
        return GENERIC_ERROR;
    }

    int contentLength = strlen(content);
    if (lineNumber >= contentLength)
    {
        printf("Line number is out of bounds\n");
        return GENERIC_ERROR;
    }

    // Find the starting position of the line
    int currentLine = 0;
    while (currentLine < lineNumber)
    {
        if (content[i] == '\n')
        {
            currentLine++;
        }
        i++;
    }

    // Store the content of the line in line_content
    int j = 0;
    while (content[i] != '\n' && content[i] != '\0')
    {
        lineContent[j++] = content[i++];
    }

    // Add null terminator to line_content
    lineContent[j] = '\0';

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
#endif