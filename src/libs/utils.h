#ifndef UTILS_H
#define UTILS_H
#include <stdint.h>
#include <stdio.h>

typedef enum ErrorType // Define all the errors which could happen and their codes
{
    SUCCESS,
    GENERIC_ERROR,
    FILE_NOT_FOUND,
    CANNOT_ACCESS_FILE,
    INVALID_DATA,
    OUT_OF_MEMORY,
} ErrorType_t;

typedef enum InstructionType // Define all the instructions with a linked identifier
{
    SKIP = -1,
    ADD,
    SUB,
    MUL,
    DIV,
    OR,
    AND,
    XOR,
    TEQ,
    TNE,
    TLT,
    TLE,
    TGT,
    TGE,
    PUSH,
    POP,
    STR,
    LD,
    STRP,
    LDP,
    XCHG,
    ADDI,
    SUBI,
    ORI,
    ANDI,
    XORI,
    TEQI,
    TNEI,
    TLTI,
    TLEI,
    TGTI,
    TGEI,
    STRI,
    LDI,
    JZ,
    JNZ,
    CALL,
    RET,
    JABS
} InstructionType_t; // etc...

typedef struct instruction // Definition of an instruction after parsing
{
    InstructionType_t instT;
    char *val1;
    char *val2;
    int line;
} instruction_t;

typedef enum ParameterType // Define type of parameters in a function
{
    IMMEDIATE,
    REGISTER,
    LABEL,
    NULL_,
} ParameterType_t;

typedef struct line // Definition of a line after parsing and checking all its arguments
{
    struct
    {
        InstructionType_t mnemonic;
        ParameterType_t param1;
        union
        {
            int register1; // 0-15
            char *label;
        };
        ParameterType_t param2;
        union
        {
            int register2;
        };
        ParameterType_t param3;
        union
        {
            int register3;
            int16_t immediate3;
        };
    };
    char *labelDeclaration;
    int lineNumber;
} line_t;

int check_is_number(char *str) // Check if a string is a number
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
        {
            return INVALID_DATA;
        }
        i++;
    }
    return SUCCESS;
}

int check_is_label(char *str) // Check if the line content is a label
{
    if (!(str[0] >= 'A' && str[0] <= 'F') || !(str[0] >= 'a' && str[0] <= 'f'))
    {
        return INVALID_DATA;
    }
    int i = 1;
    while (str[i] != '\0')
    {
        if (!(str[i] >= '0' && str[i] <= '9') || !(str[i] >= 'A' && str[i] <= 'F') || !(str[i] >= 'a' && str[i] <= 'f'))
        {
            return INVALID_DATA;
        }
        i++;
    }
    return SUCCESS;
}

#endif