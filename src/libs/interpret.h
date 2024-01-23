#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int registerArr[16];

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

int findRegister(char* inString, int* registerIndex)
{
    char str2[3];
    strcpy(str2, inString);
    char* ptr = str2;
    ptr++;
    *registerIndex = (int)strtol(ptr, NULL, 16);

    return 0;
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

#endif