#ifndef UTILS_H
#define UTILS_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define STACK_POINTER 30
#define INSTRUCTION_POINTER 31

typedef enum ErrorType // Define all the errors which could happen and their codes
{
    SUCCESS,
    GENERIC_ERROR,
    FILE_NOT_FOUND,
    CANNOT_ACCESS_FILE,
    INVALID_DATA,
    OUT_OF_MEMORY,
    STACK_OVERFLOW,
} ErrorType_t;

typedef enum binType{
    R,
    I,
    J
}binType_t;

typedef struct binInstruction
{
    binType_t type;
    union
    {
        struct typeR
        {
            uint8_t opcode; //7bits
            uint8_t source2; //5bits
            uint8_t source;
            uint8_t destination;
        }typeR;
        struct typeI
        {
            uint8_t opcode; //6bits
            int16_t immediate; //16bits
            uint8_t source; //5bits
            uint8_t destination;
        }typeI;
        struct typeJ
        {
            uint8_t opcode; //4bits
            int32_t address;
            uint8_t register_; //5bits
        }typeJ;
    };
    
} binInstruction_t;

typedef enum InstructionType
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
} InstructionType_t;

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
            int32_t immediate1;
            char *label;
        };
        ParameterType_t param2;
        union
        {
            int register2;
            int32_t immediate2;
        };
    };
    char *labelDeclaration;
    int *lineNumber;
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

int check_is_label(char *str) //Check if the line content is a label
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

//Used to know what kind of input value we're working with
int check_val(char* val){
    if(val == NULL || strcmp(val, "") == 0){
        return NULL_;
    }

    char str2[3];
    strcpy(str2, val);
    char* ptr = str2;
    ptr++;

    if(((*ptr >= '0' && *ptr <= '9') || (*ptr >= 'A' && *ptr <= 'F') || (*ptr >= 'a' && *ptr <= 'f')) 
    && strlen(val) == 2
    && (val[0] == 'R' || val[0] == 'r')){
        return REGISTER;
    }
    if(check_is_number(val) == SUCCESS){
        return IMMEDIATE;
    }
    if(check_is_number(val) == SUCCESS){
        return LABEL;
    }

    return INVALID_DATA;
}

#endif