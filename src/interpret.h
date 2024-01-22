#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum InstructionType{MOV, JMP, CALL, RET}InstructionType_t; // etc...

typedef struct instruction
{
    InstructionType_t instT;
    int reg1;
    int reg2;
    int line;
}instruction_t;

typedef struct stackNode{
    struct stackNode* previous;
    instruction_t val;
}stackNode_t;

typedef struct stack {
    stackNode_t* head;
    unsigned int size;
} stack_t;

int push_to_stack(stack_t* pStack, instruction_t value){
    if(pStack -> head == NULL){
        stackNode_t node = {NULL, value};
        stackNode_t* p = (stackNode_t*)malloc(sizeof(stackNode_t));
        memcpy(p, &node, sizeof(stackNode_t));
        pStack -> size++;
        pStack -> head = p;
    }else{
        stackNode_t node = {NULL, value};
        stackNode_t* p = (stackNode_t*)malloc(sizeof(stackNode_t));
        memcpy(p, &node, sizeof(stackNode_t));
        pStack -> size++;
        pStack -> head -> previous = p;
        pStack -> head = p;
    }
    return EXIT_SUCCESS;
}

int pop_from_stack(stack_t* pStack, instruction_t* value){
    if(pStack -> head == NULL){
        return EXIT_FAILURE;
    } else if(pStack -> size == 1){
        *value = pStack->head->val;
        free(pStack -> head);
        pStack -> size--;
        pStack -> head = NULL;
    }else{
        *value = pStack->head->val;
        free(pStack -> head);
        pStack -> size--;
        pStack -> head -> previous = NULL;
    }
    return EXIT_SUCCESS;
}

int addToReturnStack(stack_t* returnStack, instruction_t call){
    push_to_stack(returnStack, call);

    return 0;
}

int getReturnLine(stack_t* returnStack, instruction_t* call){
    pop_from_stack(returnStack, call);

    return 0;
}

#endif