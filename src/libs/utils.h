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

// Define all the errors which could happen and their codes
typedef enum ErrorType 
{
    SUCCESS,
    GENERIC_ERROR,
    FILE_NOT_FOUND,
    CANNOT_ACCESS_FILE,
    INVALID_DATA,
    OUT_OF_MEMORY,
    HALT,
    REGISTER_INSTEAD_OF_LABEL
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
} InstructionType_t; // List of all the instruction types in our assembly language

typedef enum ParameterType // Define type of parameters in a function in line struct
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

typedef struct line // Definition of a line after parsing and checking all its arguments to identify them in assembler.h
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
                char *labelCall1;
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

typedef struct label // Structure of a label in assembler.h
{
    uint32_t line;
    char *labelStr;
} label_t;

typedef struct nodeLabel // Node of a linked list of labels in assembler.h
{
    struct nodeLabel *previous;
    label_t val;
    struct nodeLabel *next;
} nodeLabel_t;

typedef struct listLabel // Linked list of labels in assembler.h
{
    nodeLabel_t *head;
    unsigned int size;
    nodeLabel_t *tail;
} listLabel_t;

typedef struct stackNode // Node of a linked list of stack in assembler.h
{                        // Item of linked list
    struct stackNode *previous;
    line_t val;
} stackNode_t;

typedef struct stack // Linked list of stack in assembler.h
{                    // Linked list = stack
    stackNode_t *head;
    unsigned int size;
} stack_t;

// ************************** END STRUCT DECLARATIONS **************************

// ************************** FUNCTION DECLARATIONS **************************s
// The functions contained in this section are of general purpose and can be used in any part of the code

// Check if a string is an hexadecimal number
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

// Check if a string is a number
int check_is_number(char *str)
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

// Check if the line content is a label
int check_is_label(char *str)
{
    if ((!(str[0] == 'r' || str[0] == 'R') && !(str[1] >= 'a' && str[1] <= 'z')) || (strlen(str) == 2 && (strcmp(str, "ip") == 0 || strcmp(str, "sp") == 0)))
    {
        return REGISTER_INSTEAD_OF_LABEL;
    } // Check for register

    int i = 0;
    while (str[i] != '\0')
    {
        // Check if character is in alphabet upper or lower case
        if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z'))
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

// Function to convert a hexadecimal number to a decimal number
int hex_to_decimal(const char *hex, int16_t *decimal)
{
    int length = strlen(hex);
    if (length > 4)
    {
        return GENERIC_ERROR; // Exceeds the maximum length for a 16-bit integer
    }

    int base = 1;
    *decimal = 0;

    for (int i = length - 1; i >= 0; i--)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            *decimal += (hex[i] - '0') * base;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            *decimal += (hex[i] - 'A' + 10) * base;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            *decimal += (hex[i] - 'a' + 10) * base;
        }
        base *= 16;
    }

    return SUCCESS;
}

// Function to convert a decimal number to a hexadecimal number
int find_register(char *inString, uint8_t *registerIndex)
{
    if (inString == NULL || strlen(inString) != 2)
    {
        return INVALID_DATA;
    }

    if (strcmp(inString, "ip") == 0) // Compare for read-only registers
    {
        *registerIndex = 30;
        return SUCCESS;
    }

    if (strcmp(inString, "sp") == 0) // Compare for read-only registers
    {
        *registerIndex = 31;
        return SUCCESS;
    }

    if (inString[0] != 'R' && inString[0] != 'r') // If it doesn't start with a R or r, it's not a register
    {
        return INVALID_DATA;
    }

    char str2[3];
    strcpy(str2, inString);
    char *ptr = str2;
    ptr++;
    if ((*ptr >= 'a' && *ptr <= 'z')) // Try to see if it is in the range of a-z
    {
        *registerIndex = (uint8_t)(*ptr - 97); // Return the index of the register minus ascii value of A (97)
        return SUCCESS;
    }
    else
    {
        return INVALID_DATA;
    }
}

// Function to get the labels from the stack
int get_list_label(listLabel_t *pList, label_t *value, int index)
{
    if (index >= 0)
    {
        nodeLabel_t *current = pList->head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        value->labelStr = malloc(strlen(current->val.labelStr) + 1);
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

// Function to add a label to the stack
int add_to_list_label(listLabel_t *pList, label_t value)
{
    if (pList->head == NULL) // If no head
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

#endif