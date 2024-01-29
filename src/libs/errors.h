#ifndef ERRORS_H
#define ERRORS_H
#include "file.h"
#include "utils.h"
#include "interpret.h"

int get_operand_name(InstructionType_t instruction, char *output)
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

int is_first_operand_null(InstructionType_t *instructionId, char *param1, int *lineNumber)
{
    // Check if first operand is not null
    if (param1 != NULL)
    {
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction does not accept first operand on line: %d\n", opcode, lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_second_operand_null(InstructionType_t *instructionId, char *param2, int *lineNumber)
{
    // Check if second operand is not null
    if (param2 != NULL)
    {
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction does not accept second operand on line: %d\n", opcode, lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_not_null(InstructionType_t *instructionId, char *param1, int *lineNumber)
{
    // Check if first operand is not null
    if (param1 == NULL)
    {
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction requires first operand on line: %d\n", opcode, lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_second_operand_not_null(InstructionType_t *instructionId, char *param2, int *lineNumber)
{
    // Check if second operand is not null
    if (param2 == NULL)
    {
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction requires second operand on line: %d\n", opcode, lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_register(InstructionType_t *instructionId, char *param1, int *lineNumber)
{
    int paramVerificationReturn;
    char opcode[4];

    if (is_first_operand_not_null(instructionId, param1, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    if (find_register(param1, &paramVerificationReturn) != SUCCESS)
    {

        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction first parameter is not an existing register on line: %d\n", opcode, lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_second_operand_register(InstructionType_t *instructionId, char *param2, int *lineNumber)
{
    int paramVerificationReturn;
    char opcode[4];

    if(is_second_operand_not_null(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    printf("param2: %s\n", param2);

    if (find_register(param2, &paramVerificationReturn) != SUCCESS)
    {

        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction second parameter is not an existing register on line: %d\n", opcode, lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_immediate(InstructionType_t *instructionId, char *param1, int *lineNumber)
{
    int paramVerificationReturn;
    char opcode[4];

    if(is_first_operand_not_null(instructionId, param1, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    if (check_is_number(param1) != SUCCESS)
    {
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction first parameter is not an immediate on line: %d\n", opcode, lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_second_operand_immediate(InstructionType_t *instructionId, char *param2, int *lineNumber)
{
    int paramVerificationReturn;
    char opcode[4];

    if(is_second_operand_not_null(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    if (check_is_number(param2) != SUCCESS)
    {
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction second parameter is not an immediate on line: %d\n", opcode, lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_immediate_or_register(InstructionType_t *instructionId, char *param1, int *lineNumber)
{
    int paramVerificationReturn;
    char opcode[4];

    if(is_first_operand_not_null(instructionId, param1, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    if (check_is_number(param1) != SUCCESS && find_register(param1, &paramVerificationReturn) != SUCCESS)
    {
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction first parameter is nor an immediate or register on line: %d\n", opcode, lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_second_operand_immediate_or_register(InstructionType_t *instructionId, char *param2, int *lineNumber)
{
    int paramVerificationReturn;
    char opcode[4];

    if(is_second_operand_not_null(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    if (check_is_number(param2) != SUCCESS && find_register(param2, &paramVerificationReturn) != SUCCESS)
    {
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction second parameter is nor an immediate or register on line: %d\n", opcode, lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int are_both_operands_registers(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber)
{
    if (is_first_operand_register(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_register(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int are_both_operands_null(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber)
{
    if (is_first_operand_null(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_null(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int are_both_operands_immediate(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber)
{
    if (is_first_operand_immediate(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_immediate(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int are_both_operands_immediate_or_register(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber)
{
    if (is_first_operand_immediate_or_register(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_immediate_or_register(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_register_and_second_operand_register_or_immediate(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber)
{
    if (is_first_operand_register(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_immediate_or_register(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_register_and_second_operand_null(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber)
{
    if (is_first_operand_register(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_null(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_register_or_immediate_and_second_operand_register_or_immediate(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber)
{
    if (is_first_operand_immediate_or_register(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_immediate_or_register(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_register_or_immediate_and_second_operand_null(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber)
{
    if (is_first_operand_immediate_or_register(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_null(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_register_and_second_operand_immediate(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber)
{
    if (is_first_operand_register(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_immediate(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}
#endif