#ifndef ERRORS_H
#define ERRORS_H
#include "file.h"
#include "utils.h"
#include "interpret.h"

// Checks for non-null operands will be implemented later

int getOperandName(InstructionType_t instruction, char *output); // May break at any time, will be deleted at refactor

int isFirstOperandNull(InstructionType_t *instructionId, char *param1, int *line_number)
{
    // Check if first operand is not null
    if (param1 != NULL)
    {
        char opcode[4];
        getOperandName(*instructionId, opcode);
        printf("Error: %s instruction does not accept first operand on line: %d\n", opcode, line_number);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int isSecondOperandNull(InstructionType_t *instructionId, char *param2, int *line_number)
{
    // Check if second operand is not null
    if (param2 != NULL)
    {
        char opcode[4];
        getOperandName(*instructionId, opcode);
        printf("Error: %s instruction does not accept second operand on line: %d\n", opcode, line_number);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int isFirstOperandRegister(InstructionType_t *instructionId, char *param1, int *line_number)
{
    int paramVerificationReturn;
    char opcode[4];

    // if (isFirstOperandNull(instructionId, param1, line_number) == SUCCESS)
    // {
    //     getOperandName(*instructionId, opcode);
    //     printf("Error: %s instruction first parameter should not be null or undefined on line: %d\n", opcode, line_number);
    //     return INVALID_DATA;
    // }

    // printf("param1: %s\n", &param1);

    if (findRegister(param1, &paramVerificationReturn) != SUCCESS)
    {

        getOperandName(*instructionId, opcode);
        printf("Error: %s instruction first parameter is not an existing register on line: %d\n", opcode, line_number);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int isSecondOperandRegister(InstructionType_t *instructionId, char *param2, int *line_number)
{
    int paramVerificationReturn;
    char opcode[4];

    // if (isSecondOperandNull(instructionId, param2, line_number) == SUCCESS)
    // {
    //     getOperandName(*instructionId, opcode);
    //     printf("Error: %s instruction second parameter should not be null or undefined on line: %d\n", opcode, line_number);
    //     return INVALID_DATA;
    // }

    // printf("param2: %s\n", param2);

    if (findRegister(param2, &paramVerificationReturn) != SUCCESS)
    {

        getOperandName(*instructionId, opcode);
        printf("Error: %s instruction second parameter is not an existing register on line: %d\n", opcode, line_number);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int isFirstOperandImmediate(InstructionType_t *instructionId, char *param1, int *line_number)
{
    int paramVerificationReturn;
    char opcode[4];

    // if (isFirstOperandNull(instructionId, param1, line_number) == SUCCESS)
    // {
    //     getOperandName(*instructionId, opcode);
    //     printf("Error: %s instruction first parameter should not be null or undefined on line: %d\n", opcode, line_number);
    //     return INVALID_DATA;
    // }

    if (checkIsNumber(param1) != SUCCESS)
    {
        getOperandName(*instructionId, opcode);
        printf("Error: %s instruction first parameter is not an immediate on line: %d\n", opcode, line_number);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int isSecondOperandImmediate(InstructionType_t *instructionId, char *param2, int *line_number)
{
    int paramVerificationReturn;
    char opcode[4];

    // if (isSecondOperandNull(instructionId, param2, line_number) == SUCCESS)
    // {
    //     getOperandName(*instructionId, opcode);
    //     printf("Error: %s instruction second parameter should not be null or undefined on line: %d\n", opcode, line_number);
    //     return INVALID_DATA;
    // }

    if (checkIsNumber(param2) != SUCCESS)
    {
        getOperandName(*instructionId, opcode);
        printf("Error: %s instruction second parameter is not an immediate on line: %d\n", opcode, line_number);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int isFirstOperandImmediateOrRegister(InstructionType_t *instructionId, char *param1, int *line_number)
{
    int paramVerificationReturn;
    char opcode[4];

    // if (isFirstOperandNull(instructionId, param1, line_number) == SUCCESS)
    // {
    //     getOperandName(*instructionId, opcode);
    //     printf("Error: %s instruction first parameter should not be null or undefined on line: %d\n", opcode, line_number);
    //     return INVALID_DATA;
    // }

    if (checkIsNumber(param1) != SUCCESS && findRegister(param1, &paramVerificationReturn) != SUCCESS)
    {
        getOperandName(*instructionId, opcode);
        printf("Error: %s instruction first parameter is nor an immediate or register on line: %d\n", opcode, line_number);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int isSecondOperandImmediateOrRegister(InstructionType_t *instructionId, char *param2, int *line_number)
{
    int paramVerificationReturn;
    char opcode[4];

    // if (isSecondOperandNull(instructionId, param2, line_number) == SUCCESS)
    // {
    //     getOperandName(*instructionId, opcode);
    //     printf("Error: %s instruction second parameter should not be null or undefined on line: %d\n", opcode, line_number);
    //     return INVALID_DATA;
    // }

    if (checkIsNumber(param2) != SUCCESS && findRegister(param2, &paramVerificationReturn) != SUCCESS)
    {
        getOperandName(*instructionId, opcode);
        printf("Error: %s instruction second parameter is nor an immediate or register on line: %d\n", opcode, line_number);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int areBothOperandsRegisters(InstructionType_t *instructionId, char *param1, char *param2, int *line_number)
{
    if (isFirstOperandRegister(instructionId, param1, line_number) != SUCCESS || isSecondOperandRegister(instructionId, param2, line_number) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int areBothOperandsNull(InstructionType_t *instructionId, char *param1, char *param2, int *line_number)
{
    if (isFirstOperandNull(instructionId, param1, line_number) != SUCCESS || isSecondOperandNull(instructionId, param2, line_number) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int areBothOperandsImmediate(InstructionType_t *instructionId, char *param1, char *param2, int *line_number)
{
    if (isFirstOperandImmediate(instructionId, param1, line_number) != SUCCESS || isSecondOperandImmediate(instructionId, param2, line_number) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int areBothOperandsImmediateOrRegister(InstructionType_t *instructionId, char *param1, char *param2, int *line_number)
{
    if (isFirstOperandImmediateOrRegister(instructionId, param1, line_number) != SUCCESS || isSecondOperandImmediateOrRegister(instructionId, param2, line_number) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int isFirstOperandRegisterAndSecondOperandRegisterOrImmediate(InstructionType_t *instructionId, char *param1, char *param2, int *line_number)
{
    if (isFirstOperandRegister(instructionId, param1, line_number) != SUCCESS || isSecondOperandImmediateOrRegister(instructionId, param2, line_number) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int isFirstOperandRegisterAndSecondOperandNull(InstructionType_t *instructionId, char *param1, char *param2, int *line_number)
{
    if (isFirstOperandRegister(instructionId, param1, line_number) != SUCCESS || isSecondOperandNull(instructionId, param2, line_number) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int isFirstOperandRegisterOrImmediateAndSecondOperandRegisterOrImmediate(InstructionType_t *instructionId, char *param1, char *param2, int *line_number)
{
    if (isFirstOperandImmediateOrRegister(instructionId, param1, line_number) != SUCCESS || isSecondOperandImmediateOrRegister(instructionId, param2, line_number) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int isFirstOperandRegisterOrImmediateAndSecondOperandNull(InstructionType_t *instructionId, char *param1, char *param2, int *line_number)
{
    if (isFirstOperandImmediateOrRegister(instructionId, param1, line_number) != SUCCESS || isSecondOperandNull(instructionId, param2, line_number) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int isFirstOperandRegisterAndSecondOperandImmediate(InstructionType_t *instructionId, char *param1, char *param2, int *line_number)
{
    if (isFirstOperandRegister(instructionId, param1, line_number) != SUCCESS || isSecondOperandImmediate(instructionId, param2, line_number) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}
#endif