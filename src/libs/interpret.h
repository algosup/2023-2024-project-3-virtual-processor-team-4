#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int registerArr[16];

int load(instruction_t instruction);
int store(instruction_t instruction);
int add(instruction_t instruction);
int sub(instruction_t instruction);
int mul(instruction_t instruction);
int div(instruction_t instruction);
int not_(instruction_t instruction); // Added _ to avoid conflict with existing keywords
int and_(instruction_t instruction); // Added _ to avoid conflict with existing keywords
int or_(instruction_t instruction);  // Added _ to avoid conflict with existing keywords
int xor_(instruction_t instruction); // Added _ to avoid conflict with existing keywords
int input(instruction_t instruction);
int output(instruction_t instruction);
int cmpeq(instruction_t instruction);
int cmpge(instruction_t instruction);
int jtrue(instruction_t instruction);
int jfalse(instruction_t instruction);
int jump(instruction_t instruction);
int call(instruction_t instruction);
int ret(instruction_t instruction);
int halt(instruction_t instruction);
int int_(instruction_t instruction); // Added _ to avoid conflict with existing keywords

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
    INPUT,
    OUTPUT,
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
    if (strlen(inString) > 3)
    {
        return INVALID_DATA;
    }

    char str2[3];
    strcpy(str2, inString);
    char *ptr = str2;
    ptr++;
    *registerIndex = (int)strtol(ptr, NULL, 16);

    return SUCCESS;
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

// --- Operations ---

int set(instruction_t instruction)
{
    int i;
    findRegister(instruction.val1, &i);

    registerArr[i] = instruction.val2;
    return SUCCESS;
}

int copy(instruction_t instruction)
{
    int i;
    findRegister(instruction.val1, &i);

    int i2;
    findRegister(instruction.val2, &i2);

    registerArr[i] = registerArr[i2];
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
        div(*instruction);
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
    case INPUT:
        input(*instruction);
        break;
    case OUTPUT:
        output(*instruction);
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

#endif