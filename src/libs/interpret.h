#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

__int32_t registerArr[16];

typedef enum InstructionType
{
    NOOP,
    SET,
    COPY,
    LOAD,
    STORE,
    ADD,
    SUB,
    MUL,
    DIV,
    NOT,
    AND,
    OR,
    XOR,
    CMPEQ,
    CMPGE,
    JTRUE,
    JFALSE,
    JUMP,
    CALL,
    RET,
    HALT,
    INT
} InstructionType_t; // etc...

typedef struct instruction // Definition of an instruction after parsing
{
    InstructionType_t instT;
    char *val1;
    char *val2;
    int line;
} instruction_t;

int load(instruction_t instruction);
int store(instruction_t instruction);
int add(instruction_t instruction);
int sub(instruction_t instruction);
int mul(instruction_t instruction);
int div_(instruction_t instruction);
int not_(instruction_t instruction); // Added _ to avoid conflict with existing keywords
int and_(instruction_t instruction); // Added _ to avoid conflict with existing keywords
int or_(instruction_t instruction);  // Added _ to avoid conflict with existing keywords
int xor_(instruction_t instruction); // Added _ to avoid conflict with existing keywords
int cmpeq(instruction_t instruction);
int cmpge(instruction_t instruction);
int jtrue(instruction_t instruction);
int jfalse(instruction_t instruction);
int jump(instruction_t instruction);
int call(instruction_t instruction);
int ret(instruction_t instruction);
int halt(instruction_t instruction);
int int_(instruction_t instruction); // Added _ to avoid conflict with existing keywords

//int memory[2048];

int load(instruction_t instruction);
int store(instruction_t instruction);
int add(instruction_t instruction);
int sub(instruction_t instruction);
int mul(instruction_t instruction);
int div_(instruction_t instruction);
int not_(instruction_t instruction); // Added _ to avoid conflict with existing keywords
int and_(instruction_t instruction); // Added _ to avoid conflict with existing keywords
int or_(instruction_t instruction);  // Added _ to avoid conflict with existing keywords
int xor_(instruction_t instruction); // Added _ to avoid conflict with existing keywords
int cmpeq(instruction_t instruction);
int cmpge(instruction_t instruction);
int jtrue(instruction_t instruction);
int jfalse(instruction_t instruction);
int jump(instruction_t instruction);
int call(instruction_t instruction);
int ret(instruction_t instruction);
int halt(instruction_t instruction);
int int_(instruction_t instruction); // Added _ to avoid conflict with existing keywords

typedef struct stackNode
{ // Item of linked list
    struct stackNode *previous;
    instruction_t val;
} stackNode_t;

typedef struct stack
{ // Linked list = stack
    stackNode_t *head;
    unsigned int size;
} stack_t;

int findRegister(char *inString, int *registerIndex)
{
    if(strlen(inString) != 2){
        return INVALID_DATA;
    }

    char str2[3];
    strcpy(str2, inString);
    char *ptr = str2;
    ptr++;

    if((*ptr >= '0' && *ptr <= '9') || (*ptr >= 'A' && *ptr <= 'F') || (*ptr >= 'a' && *ptr <= 'f')){
        *registerIndex = (int)strtol(ptr, NULL, 16);
        return SUCCESS;
    }else{
        return INVALID_DATA;
    }
};

int push_to_stack(stack_t *pStack, instruction_t value)
{
    if (pStack->head == NULL)
    {
        stackNode_t node = {NULL, value};
        stackNode_t *p = (stackNode_t *)malloc(sizeof(stackNode_t));
        memcpy(p, &node, sizeof(stackNode_t));
        pStack->size++;
        pStack->head = p;
    }
    else
    {
        stackNode_t node = {NULL, value};
        stackNode_t *p = (stackNode_t *)malloc(sizeof(stackNode_t));
        memcpy(p, &node, sizeof(stackNode_t));
        pStack->size++;
        pStack->head->previous = p;
        pStack->head = p;
    }
    return EXIT_SUCCESS;
}

int pop_from_stack(stack_t *pStack, instruction_t *value)
{
    if (pStack->head == NULL)
    {
        return EXIT_FAILURE;
    }
    else if (pStack->size == 1)
    {
        *value = pStack->head->val;
        free(pStack->head);
        pStack->size--;
        pStack->head = NULL;
    }
    else
    {
        *value = pStack->head->val;
        free(pStack->head);
        pStack->size--;
        pStack->head->previous = NULL;
    }
    return EXIT_SUCCESS;
}

int addToReturnStack(stack_t *returnStack, instruction_t call)
{
    push_to_stack(returnStack, call);

    return 0;
}

int getReturnLine(stack_t *returnStack, instruction_t *call)
{
    pop_from_stack(returnStack, call);

    return 0;
}

int checkVal(char* val){
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
    if(checkIsNumber(val) == SUCCESS){
        return IMMEDIAT;
    }
    if(checkIsLabel(val) == SUCCESS){
        return LABEL;
    }

    return INVALID_DATA;
}

// --- Operations ---

int noop(instruction_t instruction){
    if(instruction.instT == NOOP){
        return SUCCESS;
    }
}

int set(instruction_t instruction){
    int i;
    if(checkVal(instruction.val1) != REGISTER){
        printf("Error: at line %d. %s is not a valid register.", instruction.line, instruction.val1);
        return INVALID_DATA;
    }
    else{
        findRegister(instruction.val1, &i);
    }

    if(checkVal(instruction.val2) == IMMEDIAT){
        registerArr[i] = (__int32_t)strtod(instruction.val2, '\0');
        return SUCCESS;
    }

    printf("Error: at line %d. %s is not a valid input", instruction.line, instruction.val2);
    return INVALID_DATA;
}

int copy(instruction_t instruction)
{
    int i;
    int i2;
    if(checkVal(instruction.val1) == REGISTER){
        findRegister(instruction.val1, &i);
    }else{
        printf("Error: at line %d. %s is not a valid register", instruction.line, instruction.val1);
        return INVALID_DATA;
    }

    if(checkVal(instruction.val2) == REGISTER){
        findRegister(instruction.val2, &i2);
        registerArr[i] = registerArr[i2];
        return SUCCESS;
    }else{
        printf("Error: at line %d. %s is not a valid register", instruction.line, instruction.val2);
        return INVALID_DATA;
    }
}

int executeInstruction(instruction_t *instruction)
{
    switch (instruction->instT)
    {
    case NOOP:
        break;
    case SET:
        set(*instruction);
        break;
    case COPY:
        copy(*instruction);
        break;
    case LOAD:
        load(*instruction);
        break;
    case STORE:
        store(*instruction);
        break;
    case ADD:
        add(*instruction);
        break;
    case SUB:
        sub(*instruction);
        break;
    case MUL:
        mul(*instruction);
        break;
    case DIV:
        div_(*instruction);
        break;
    case NOT:
        not_(*instruction);
        break;
    case AND:
        and_(*instruction);
        break;
    case OR:
        or_(*instruction);
        break;
    case XOR:
        xor_(*instruction);
        break;
    case CMPEQ:
        cmpeq(*instruction);
        break;
    case CMPGE:
        cmpge(*instruction);
        break;
    case JTRUE:
        jtrue(*instruction);
        break;
    case JFALSE:
        jfalse(*instruction);
        break;
    case JUMP:
        jump(*instruction);
        break;
    case CALL:
        call(*instruction);
        break;
    case RET:
        ret(*instruction);
        break;
    case HALT:
        halt(*instruction);
        break;
    case INT:
        int_(*instruction);
        break;
    default:
        break;
    }
    return SUCCESS;
}

int add(instruction_t instruction)
{
    int i;
    if(checkVal(instruction.val1) == REGISTER){
        findRegister(instruction.val1, &i);
        switch (checkVal(instruction.val2))
        {
        case REGISTER:
            int i2;
            findRegister(instruction.val2, &i2);
            registerArr[i] = registerArr[i] + registerArr[i2];
            return SUCCESS;
        
        case IMMEDIAT:
            registerArr[i] = registerArr[i] + (__int32_t)strtod(instruction.val2, '\0');
            return SUCCESS;
        default:
            printf("Error: at line %d. %s is not a valid input", instruction.line, instruction.val2);
            return INVALID_DATA;
        }
    }else{
        printf("Error: at line %d. %s is not a valid register", instruction.line, instruction.val1);
        return INVALID_DATA;
    }
}

int sub(instruction_t instruction)
{
    int i;
    if(checkVal(instruction.val1) == REGISTER){
        findRegister(instruction.val1, &i);
        switch (checkVal(instruction.val2))
        {
        case REGISTER:
            int i2;
            findRegister(instruction.val2, &i2);
            registerArr[i] = registerArr[i] - registerArr[i2];
            return SUCCESS;
        
        case IMMEDIAT:
            registerArr[i] = registerArr[i] - (__int32_t)strtod(instruction.val2, '\0');
            return SUCCESS;
        default:
            printf("Error: at line %d. %s is not a valid input", instruction.line, instruction.val2);
            return INVALID_DATA;
        }
    }else{
        printf("Error: at line %d. %s is not a valid register", instruction.line, instruction.val1);
        return INVALID_DATA;
    }
}

int mul(instruction_t instruction){
    int i;
    int i2;
    if(checkVal(instruction.val1) == REGISTER){
        findRegister(instruction.val1, &i);
    }else{
        printf("Error: at line %d. %s is not a valid register", instruction.line, instruction.val1);
        return INVALID_DATA;
    }

    if(checkVal(instruction.val2) == REGISTER){
        findRegister(instruction.val2, &i2);

        __int64_t bigInt64 = (__int64_t)registerArr[i]*registerArr[i2];
        __int32_t high32 = (__int32_t)(bigInt64 >> 32);
        __int32_t low32 = (__int32_t)bigInt64;

        registerArr[i] = low32;
        registerArr[i2] = high32;

        return SUCCESS;
    }else{
        printf("Error: at line %d. %s is not a valid register", instruction.line, instruction.val2);
        return INVALID_DATA;
    }
}

int div_(instruction_t instruction){
    int i;
    int i2;
    if(checkVal(instruction.val1) == REGISTER){
        findRegister(instruction.val1, &i);
    }else{
        printf("Error: at line %d. %s is not a valid register", instruction.line, instruction.val1);
        return INVALID_DATA;
    }

    if(checkVal(instruction.val2) == REGISTER){
        __int32_t tmp = registerArr[i2];

        registerArr[i2] = registerArr[i]%registerArr[i2];
        registerArr[i] = registerArr[i]/tmp;

        return SUCCESS;
    }else{
        printf("Error: at line %d. %s is not a valid register", instruction.line, instruction.val2);
        return INVALID_DATA;
    }
}

int and_ (instruction_t instruction){
    int i;
    if(checkVal(instruction.val1) == REGISTER){
        findRegister(instruction.val1, &i);
        switch (checkVal(instruction.val2))
        {
        case REGISTER:
            int i2;
            findRegister(instruction.val2, &i2);
            registerArr[i] = registerArr[i] & registerArr[i2];
            return SUCCESS;
        
        case IMMEDIAT:
            registerArr[i] = registerArr[i] & (__int32_t)strtod(instruction.val2, '\0');
            return SUCCESS;
        default:
            printf("Error: at line %d. %s is not a valid input", instruction.line, instruction.val2);
            return INVALID_DATA;
        }
    }else{
        printf("Error: at line %d. %s is not a valid register", instruction.line, instruction.val1);
        return INVALID_DATA;
    }
}

int or_ (instruction_t instruction){
    int i;
    if(checkVal(instruction.val1) == REGISTER){
        findRegister(instruction.val1, &i);
        switch (checkVal(instruction.val2))
        {
        case REGISTER:
            int i2;
            findRegister(instruction.val2, &i2);
            registerArr[i] = registerArr[i] | registerArr[i2];
            return SUCCESS;
        
        case IMMEDIAT:
            registerArr[i] = registerArr[i] | (__int32_t)strtod(instruction.val2, '\0');
            return SUCCESS;
        default:
            printf("Error: at line %d. %s is not a valid input", instruction.line, instruction.val2);
            return INVALID_DATA;
        }
    }else{
        printf("Error: at line %d. %s is not a valid register", instruction.line, instruction.val1);
        return INVALID_DATA;
    }
}

int xor_ (instruction_t instruction){
    int i;
    if(checkVal(instruction.val1) == REGISTER){
        findRegister(instruction.val1, &i);
        switch (checkVal(instruction.val2))
        {
        case REGISTER:
            int i2;
            findRegister(instruction.val2, &i2);
            registerArr[i] = registerArr[i] ^ registerArr[i2];
            return SUCCESS;
        
        case IMMEDIAT:
            registerArr[i] = registerArr[i] ^ (__int32_t)strtod(instruction.val2, '\0');
            return SUCCESS;
        default:
            printf("Error: at line %d. %s is not a valid input", instruction.line, instruction.val2);
            return INVALID_DATA;
        }
    }else{
        printf("Error: at line %d. %s is not a valid register", instruction.line, instruction.val1);
        return INVALID_DATA;
    }
}

int load(instruction_t instruction){
    return GENERIC_ERROR;
}
int store(instruction_t instruction){
    return GENERIC_ERROR;
}
int not_(instruction_t instruction){
    return GENERIC_ERROR;
}
int cmpeq(instruction_t instruction){
    return GENERIC_ERROR;
}
int cmpge(instruction_t instruction){
    return GENERIC_ERROR;
}
int jtrue(instruction_t instruction){
    return GENERIC_ERROR;
}
int jfalse(instruction_t instruction){
    return GENERIC_ERROR;
}
int jump(instruction_t instruction){
    return GENERIC_ERROR;
}
int call(instruction_t instruction){
    return GENERIC_ERROR;
}
int ret(instruction_t instruction){
    return GENERIC_ERROR;
}
int halt(instruction_t instruction){
    return GENERIC_ERROR;
}
int int_(instruction_t instruction){
    return GENERIC_ERROR;
} 


#endif