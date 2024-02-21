#ifndef UTILS_H
#define UTILS_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum ErrorType // Define all the errors which could happen and their codes
{
    SUCCESS,
    GENERIC_ERROR,
    FILE_NOT_FOUND,
    CANNOT_ACCESS_FILE,
    INVALID_DATA,
    OUT_OF_MEMORY,
    REGISTER_INSTEAD_OF_LABEL
} ErrorType_t;

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
} InstructionType_t; // etc...

typedef enum ParameterType // Define type of parameters in a function
{
    IMMEDIATE,
    REGISTER,
    LABEL,
    NULL_,
} ParameterType_t;

// ************************** END ENUM DECLARATIONS **************************

// ************************** STRUCT DECLARATIONS **************************

typedef struct instruction // Definition of an instruction after parsing
{
    InstructionType_t instT;
    char *val1;
    char *val2;
    int line;
} instruction_t;

typedef struct line // Definition of a line after parsing and checking all its arguments
{
    uint64_t lineNumber;
    InstructionType_t mnemonic;
    ParameterType_t dest_t;
    union
    {
        uint8_t dest;
        char *labelCall;
        int16_t immediateDest;
    };
    union
    {
        struct
        {
            ParameterType_t param1_t;
            union
            {
                uint8_t register1;
                int16_t immediate1;
            };
            ParameterType_t param2_t;
            union
            {
                uint8_t register2;
                int16_t immediate2;
            };
        };
        struct
        {
            char *labelDef;
        };
    };
} line_t;

typedef struct label
{
    uint32_t line;
    char *labelStr;
} label_t;

typedef struct nodeLabel
{
    struct nodeLabel *previous;
    label_t val;
    struct nodeLabel *next;
} nodeLabel_t;

typedef struct listLabel
{
    nodeLabel_t *head;
    unsigned int size;
    nodeLabel_t *tail;
} listLabel_t;

typedef struct stackNode
{ // Item of linked list
    struct stackNode *previous;
    line_t val;
} stackNode_t;

typedef struct stack
{ // Linked list = stack
    stackNode_t *head;
    unsigned int size;
} stack_t;

// ************************** END STRUCT DECLARATIONS **************************

// ************************** FUNCTION DECLARATIONS **************************s
// The functions contained in this section are of general purpose and can be used in any part of the code

int isHexadecimal(const char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        char ch = str[i];
        if (!((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F')))
        {
            return INVALID_DATA;
        }
    }
    return SUCCESS;
}

int check_is_number(char *str) // Check if a string is a number
{
    if (str == NULL || strlen(str) == 0)
    {
        return INVALID_DATA;
    }

    int i = 0;
    if (str[i] == '-')
    {
        i++;
    }

    // Check if it's a hexadecimal number
    if ((str[i] == 'x' || str[i] == 'X'))
    {
        return isHexadecimal(str + 1);
    }

    // Check if it's a decimal number
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
    if ((!(str[0] == 'r' || str[0] == 'R') && !(str[1] >= 'a' && str[1] <= 'z')) || (strlen(str) == 2 && (strcmp(str, "ip") == 0 || strcmp(str, "sp") == 0)))
    {
        return REGISTER_INSTEAD_OF_LABEL;
    } // Check for register

    int i = 0;
    while (str[i] != '\0')
    {
        // Check if character is in alphabet
        if (!(str[i] >= 'a' && str[i] <= 'z'))
        {
            return INVALID_DATA;
        }
        i++;
    }

    return SUCCESS;
}

// Used to know what kind of input value we're working with
int check_val(char *val)
{
    if (val == NULL || strcmp(val, "") == 0)
    {
        return NULL_;
    }

    char str2[3];
    strcpy(str2, val);
    char *ptr = str2;
    ptr++;

    if (((*ptr >= '0' && *ptr <= '9') || (*ptr >= 'a' && *ptr <= 'f')) && strlen(val) == 2 && (val[0] == 'R' || val[0] == 'r' || strcmp(str2, "ip") == 0 || strcmp(str2, "sp") == 0))
    {
        return REGISTER;
    }
    if (check_is_number(val) == SUCCESS)
    {
        return IMMEDIATE;
    }
    if (check_is_number(val) == SUCCESS)
    {
        return LABEL;
    }

    return INVALID_DATA;
}

int find_register(char *inString, uint8_t *registerIndex)
{
    if (inString == NULL || strlen(inString) != 2)
    {
        return INVALID_DATA;
    }

    if (inString[0] != 'R' && inString[0] != 'r')
    {
        return INVALID_DATA;
    }

    if (strcmp(inString, "ip") == 0)
    {
        *registerIndex = 30;
        return SUCCESS;
    }

    if (strcmp(inString, "sp") == 0)
    {
        *registerIndex = 31;
        return SUCCESS;
    }

    char str2[3];
    strcpy(str2, inString);
    char *ptr = str2;
    ptr++;
    if ((*ptr >= 'a' && *ptr <= 'z'))
    {
        *registerIndex = (uint8_t)(*ptr - 97);
        return SUCCESS;
    }
    else
    {
        return INVALID_DATA;
    }
}

int get_list_label(listLabel_t *pList, label_t *value, int index)
{
    if (index >= 0)
    {
        nodeLabel_t *current = pList->head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        strcpy(value->labelStr, current->val.labelStr);
        value->line = current->val.line;
    }
    else
    {
        nodeLabel_t *current = pList->tail;
        for (int i = -1; i > index; i--)
        {
            current = current->previous;
        }
        strcpy(value->labelStr, current->val.labelStr);
        value->line = current->val.line;
    }
    return SUCCESS;
};

int add_to_list_label(listLabel_t *pList, label_t value)
{
    if (pList->head == NULL)
    {
        nodeLabel_t node = {NULL, value, NULL};
        nodeLabel_t *p = (nodeLabel_t *)malloc(sizeof(nodeLabel_t));
        memcpy(p, &node, sizeof(nodeLabel_t));
        pList->size++;
        pList->head = p;
        pList->tail = p;
    }
    else
    {
        nodeLabel_t node = {pList->tail, value, NULL};
        nodeLabel_t *p = (nodeLabel_t *)malloc(sizeof(nodeLabel_t));
        memcpy(p, &node, sizeof(nodeLabel_t));
        pList->size++;
        pList->tail->next = p;
        pList->tail = p;
    }
    return SUCCESS;
}

// int memory_allocation_failed()

#endif