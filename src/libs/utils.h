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
    LABEL_ = -2,
    SKIP = -1,
    ABS,
    ADD,
    ADDI,
    AND,
    ANDI,
    B,
    BI,
    BNZ,
    BZ,
    CALL,
    CALLI,
    DIV,
    JMP,
    LD,
    LDI,
    LDP,
    MUL,
    OR,
    ORI,
    POP,
    PUSH,
    RET,
    SET,
    STR,
    STRI,
    STRP,
    SUB,
    SUBI,
    TEQ,
    TEQI,
    TGE,
    TGEI,
    TGT,
    TGTI,
    TLE,
    TLEI,
    TLT,
    TLTI,
    TNE,
    TNEI,
    XCHG,
    XOR,
    XORI
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
    uint64_t lineNumber;
    InstructionType_t mnemonic;
    ParameterType_t dest_t;
    uint8_t dest;
    union
    {
        struct
        {
            uint8_t param1;
            ParameterType_t param2_t;
            union
            {
                uint8_t register2;
                int16_t immediate2;
            };
        };
        struct
        {
            char *label;
        };
    };

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