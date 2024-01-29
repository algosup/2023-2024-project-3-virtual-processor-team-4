#ifndef FILE_H
#define FILE_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

int findOperand(char *input, InstructionType_t *instruction)
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

int getOperandName(InstructionType_t instruction, char *output)
{
    switch (instruction)
    {
    case SKIP:
        strcpy(output, "skip");
        break;
    case NOOP:
        strcpy(output, "noop");
        break;
    case SET:
        strcpy(output, "set");
        break;
    case COPY:
        strcpy(output, "copy");
        break;
    case LOAD:
        strcpy(output, "load");
        break;
    case STORE:
        strcpy(output, "store");
        break;
    case ADD:
        strcpy(output, "add");
        break;
    case SUB:
        strcpy(output, "sub");
        break;
    case MUL:
        strcpy(output, "mul");
        break;
    case DIV:
        strcpy(output, "div");
        break;
    case NOT:
        strcpy(output, "not");
        break;
    case AND:
        strcpy(output, "and");
        break;
    case OR:
        strcpy(output, "or");
        break;
    case XOR:
        strcpy(output, "xor");
        break;
    case CMPEQ:
        strcpy(output, "cmpeq");
        break;
    case CMPGE:
        strcpy(output, "cmpge");
        break;
    case JTRUE:
        strcpy(output, "jtrue");
        break;
    case JFALSE:
        strcpy(output, "jfalse");
        break;
    case JUMP:
        strcpy(output, "jump");
        break;
    case CALL:
        strcpy(output, "call");
        break;
    case RET:
        strcpy(output, "ret");
        break;
    case HALT:
        strcpy(output, "halt");
        break;
    case INT:
        strcpy(output, "int");
        break;
    default:
        return GENERIC_ERROR;
    }
    return SUCCESS;
}

int fillLineStruct(line_t *line, InstructionType_t *instType, char *word2, char *word3, int *line_number)
{
    line->mnemonic = *instType;
    line->line_number = line_number;
    line->label_declaration = NULL;
    if (word2 != NULL)
    {
        if (findRegister(word2, &line->register1) == SUCCESS)
        {
            line->param1 = REGISTER;
        }
        else if (checkIsNumber(word2) == SUCCESS)
        {
            line->param1 = IMMEDIAT;
        }
        else if (checkIsLabel(word2) == SUCCESS)
        {
            line->param1 = LABEL;
            line->label_declaration = word2;
        }
    }
    else
    {
        line->param1 = NULL_;
    }
    if (word3 != NULL)
    {
        if (findRegister(word3, &line->register2) == SUCCESS)
        {
            line->param2 = REGISTER;
        }
        else if (checkIsNumber(word3) == SUCCESS)
        {
            line->param2 = IMMEDIAT;
        }
        else
        {
            printf("Error: Invalid operation (unhandled second param) on line %d\n", *line_number);
            return GENERIC_ERROR;
        }
    }
    else
    {
        line->param2 = NULL_;
    }
    return SUCCESS;
}

int areOperationParamsValid(InstructionType_t *instructionId, char *param1, char *param2, int *line_number)
{
    printf("Instruction: %d\nParam 1: %s\nParam 2: %s\n\n", *instructionId, param1, param2);
    switch (*instructionId)
    {
    case SKIP:
    case NOOP:
        areBothOperandsNull(instructionId, param1, param2, line_number);
        break;
    case SET:
        isFirstOperandRegisterAndSecondOperandImmediate(instructionId, param1, param2, line_number);
        break;
    case NOT:
        isFirstOperandRegisterAndSecondOperandNull(instructionId, param1, param2, line_number);
        break;
    case STORE:
        areBothOperandsImmediateOrRegister(instructionId, param1, param2, line_number);
        break;
    case COPY:
    case MUL:
    case DIV:
        areBothOperandsRegisters(instructionId, param1, param2, line_number);
        break;
    case LOAD:
    case ADD:
    case SUB:
    case AND:
    case OR:
    case XOR:
        return isFirstOperandRegisterAndSecondOperandRegisterOrImmediate(instructionId, param1, param2, line_number);
        break;
    default:
        printf("Instruction not found");
        return GENERIC_ERROR;
        break;
        // Following instructions are not implemented yet
    }
}

int preprocess_line(char *line_content, line_t *line, int *line_number)
{
    if (line_content[0] == '/' && line_content[1] == '/') // Check if the line is a comment
    {
        line->mnemonic = SKIP;
        line->param1 = NULL_;
        line->register1 = NULL_;
        line->line_number = line_number;
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
    // Add checks for the operands
    //  Check if operation mnemonic exists => If not, throw error
    //  Check the arguments for mnemonic
    InstructionType_t *instType = malloc(sizeof(InstructionType_t)); // check for free afterwhile
    if (findOperand(word1, instType) != SUCCESS)
    {
        printf("Error: Invalid operation on line %d\n", *line_number);
        line->mnemonic = SKIP;
        line->line_number = line_number;
        line->param1 = NULL_;
        line->label_declaration = NULL;
        return GENERIC_ERROR;
    }
    if (areOperationParamsValid(instType, word2, word3, line_number) != SUCCESS)
    {
        line->mnemonic = SKIP;
        line->line_number = line_number;
        line->param1 = NULL_;
        line->label_declaration = NULL;
        return GENERIC_ERROR;
    }
    if (fillLineStruct(line, instType, word2, word3, line_number) != SUCCESS)
    {
        return GENERIC_ERROR;
    }
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
#endif