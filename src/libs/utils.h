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

typedef struct label
{
    uint32_t line;
    char* labelStr;
}label_t;


typedef struct nodeLabel{
    struct nodeLabel* previous;
    label_t val;
    struct nodeLabel* next;
}nodeLabel_t;

typedef struct listLabel {
    nodeLabel_t* head;
    unsigned int size;
    nodeLabel_t* tail;
} listLabel_t;

int get_list_str(listLabel_t* pList, label_t* value, int index){
    if(index >= 0){
        nodeLabel_t* current = pList -> head;
        for(int i = 0; i < index; i++){
            current = current -> next;
        }
        strcpy(value->labelStr, current -> val.labelStr);
        value->line = current -> val.line;
    }else{
        nodeLabel_t* current = pList -> tail;
        for(int i = -1; i > index; i--){
            current = current -> previous;
        }
        strcpy(value->labelStr, current -> val.labelStr);
        value->line = current -> val.line;
    }
    return SUCCESS;
};

int add_to_list_str(listLabel_t* pList, label_t value){
    if(pList -> head == NULL){
        nodeLabel_t node = {NULL, value, NULL};
        nodeLabel_t* p = (nodeLabel_t*)malloc(sizeof(nodeLabel_t));
        memcpy(p, &node, sizeof(nodeLabel_t));
        pList -> size++;
        pList -> head = p;
        pList -> tail = p; 
    }else{        
        nodeLabel_t node = {pList -> tail, value, NULL};
        nodeLabel_t* p = (nodeLabel_t*)malloc(sizeof(nodeLabel_t));
        memcpy(p, &node, sizeof(nodeLabel_t));
        pList -> size++;
        pList -> tail -> next = p;
        pList -> tail = p;
    }
    return SUCCESS;
}

#endif