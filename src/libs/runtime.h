#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int16_t registerArr[16];

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

// int memory[2048];

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

int find_register(char *inString, uint8_t *registerIndex)
{
    if (inString == NULL || strlen(inString) != 2)
    {
        return INVALID_DATA;
    }

    if(inString[0] != 'R' && inString[0] != 'r') {
        return INVALID_DATA;
    }

    char str2[3];
    strcpy(str2, inString);
    char *ptr = str2;
    ptr++;
    if ((*ptr >= '0' && *ptr <= '9') || (*ptr >= 'A' && *ptr <= 'F') || (*ptr >= 'a' && *ptr <= 'f'))
    {
        *registerIndex = (uint8_t)strtol(ptr, NULL, 16);
        return SUCCESS;
    }
    else
    {
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

int add_to_return_stack(stack_t *returnStack, instruction_t call)
{
    push_to_stack(returnStack, call);

    return 0;
}

int get_return_line(stack_t *returnStack, instruction_t *call)
{
    pop_from_stack(returnStack, call);

    return 0;
}

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

    if (((*ptr >= '0' && *ptr <= '9') || (*ptr >= 'A' && *ptr <= 'F') || (*ptr >= 'a' && *ptr <= 'f')) && strlen(val) == 2 && (val[0] == 'R' || val[0] == 'r'))
    {
        return REGISTER;
    }
    if (check_is_number(val) == SUCCESS)
    {
        return IMMEDIATE;
    }
    if (check_is_label(val) == SUCCESS)
    {
        return LABEL;
    }

    return INVALID_DATA;
}

// --- Operations ---

int noop(instruction_t instruction)
{
    if (instruction.instT == SKIP)
    {
        return SUCCESS;
    }
}

int set(instruction_t instruction)
{
    uint8_t i;
    if (check_val(instruction.val1) != REGISTER)
    {
        printf("Error: at line %d. %s is not a valid register.", instruction.line, instruction.val1);
        return INVALID_DATA;
    }
    else
    {
        find_register(instruction.val1, &i);
    }

    if (check_val(instruction.val2) == IMMEDIATE)
    {
        registerArr[i] = (int16_t)strtod(instruction.val2, '\0');
        return SUCCESS;
    }

    printf("Error: at line %d. %s is not a valid input", instruction.line, instruction.val2);
    return INVALID_DATA;
}

int copy(instruction_t instruction)
{
    uint8_t i;
    uint8_t i2;
    if (check_val(instruction.val1) == REGISTER)
    {
        find_register(instruction.val1, &i);
    }
    else
    {
        printf("Error: at line %d. %s is not a valid register", instruction.line, instruction.val1);
        return INVALID_DATA;
    }

    if (check_val(instruction.val2) == REGISTER)
    {
        find_register(instruction.val2, &i2);
        registerArr[i] = registerArr[i2];
        return SUCCESS;
    }
    else
    {
        printf("Error: at line %d. %s is not a valid register", instruction.line, instruction.val2);
        return INVALID_DATA;
    }
}

// int execute_instruction(instruction_t *instruction)
// {
//     switch (instruction->instT)
//     {
//     case SKIP:
//         return SUCCESS;
//     case ADD:
//         add(*instruction);
//         return SUCCESS;
//     case SUB:
//         sub(*instruction);
//         return SUCCESS;
//     case MUL:
//         mul(*instruction);
//         return SUCCESS;
//     case DIV:
//         div_(*instruction);
//         return SUCCESS;
//     case OR:
//         or_(*instruction);
//         return SUCCESS;
//     case AND:
//         and_(*instruction);
//         return SUCCESS;
//     case XOR:
//         xor_(*instruction);
//         return SUCCESS;
//     case TEQ:
//         teq(*instruction);
//         return SUCCESS;
//     case TNE:
//         tne(*instruction);
//         return SUCCESS;
//     case TLT:
//         tlt(*instruction);
//         return SUCCESS;
//     case TLE:
//         tle(*instruction);
//         return SUCCESS;
//     case TGT:
//         tgt(*instruction);
//         return SUCCESS;
//     case TGE:
//         tge(*instruction);
//         return SUCCESS;
//     case PUSH:
//         push(*instruction);
//         return SUCCESS;
//     case POP:
//         pop(*instruction);
//         return SUCCESS;
//     case STR:
//         str(*instruction);
//         return SUCCESS;
//     case LD:
//         ld(*instruction);
//         return SUCCESS;
//     case STRP:
//         strp(*instruction);
//         return SUCCESS;
//     case LDP:
//         ldp(*instruction);
//         return SUCCESS;
//     case XCHG:
//         xchg(*instruction);
//         return SUCCESS;
//     case ADDI:
//         addi(*instruction);
//         return SUCCESS;
//     case SUBI:
//         subi(*instruction);
//         return SUCCESS;
//     case ORI:
//         ori(*instruction);
//         return SUCCESS;
//     case ANDI:
//         andi(*instruction);
//         return SUCCESS;
//     case XORI:
//         add(*instruction);
//         return SUCCESS;
//     case TEQI:
//         teqi(*instruction);
//         return SUCCESS;
//     case TNEI:
//         tnei(*instruction);
//         return SUCCESS;
//     case TLTI:
//         tlti(*instruction);
//         return SUCCESS;
//     case TLEI:
//         tlei(*instruction);
//         return SUCCESS;
//     case TGTI:
//         tgti(*instruction);
//         return SUCCESS;
//     case TGEI:
//         tgei(*instruction);
//         return SUCCESS;
//     case STRI:
//         stri(*instruction);
//         return SUCCESS;
//     case LDI:
//         ldi(*instruction);
//         return SUCCESS;
//     case JZ:
//         jz(*instruction);
//         return SUCCESS;
//     case JNZ:
//         jnz(*instruction);
//         return SUCCESS;
//     case CALL:
//         call(*instruction);
//         return SUCCESS;
//     case RET:
//         ret(*instruction);
//         return SUCCESS;
//     case JABS:
//         jabs(*instruction);
//         return SUCCESS;
//     default:
//         printf("Error : line %d. Not a valid operation\n", instruction->line_number);
//         return GENERIC_ERROR;
//     }
//     return GENERIC_ERROR;
// }

int add(instruction_t instruction)
{
    uint8_t i;
    if (check_val(instruction.val1) == REGISTER)
    {
        find_register(instruction.val1, &i);
        switch (check_val(instruction.val2))
        {
        case REGISTER:
            uint8_t i2;
            find_register(instruction.val2, &i2);
            registerArr[i] = registerArr[i] + registerArr[i2];
            return SUCCESS;

        case IMMEDIATE:
            registerArr[i] = registerArr[i] + (int16_t)strtod(instruction.val2, '\0');
            return SUCCESS;
        default:
            printf("Error: at line %d. %s is not a valid input", instruction.line, instruction.val2);
            return INVALID_DATA;
        }
    }
    else
    {
        printf("Error: at line %d. %s is not a valid register", instruction.line, instruction.val1);
        return INVALID_DATA;
    }
}

int sub(instruction_t instruction)
{
    uint8_t i;
    if (check_val(instruction.val1) == REGISTER)
    {
        find_register(instruction.val1, &i);
        switch (check_val(instruction.val2))
        {
        case REGISTER:
            uint8_t i2;
            find_register(instruction.val2, &i2);
            registerArr[i] = registerArr[i] - registerArr[i2];
            return SUCCESS;

        case IMMEDIATE:
            registerArr[i] = registerArr[i] - (int16_t)strtod(instruction.val2, '\0');
            return SUCCESS;
        default:
            printf("Error: at line %d. %s is not a valid input", instruction.line, instruction.val2);
            return INVALID_DATA;
        }
    }
    else
    {
        printf("Error: at line %d. %s is not a valid register", instruction.line, instruction.val1);
        return INVALID_DATA;
    }
}

int mul(instruction_t instruction)
{
    uint8_t i;
    uint8_t i2;
    if (check_val(instruction.val1) == REGISTER)
    {
        find_register(instruction.val1, &i);
    }
    else
    {
        printf("Error: at line %d. %s is not a valid register", instruction.line, instruction.val1);
        return INVALID_DATA;
    }

    if (check_val(instruction.val2) == REGISTER)
    {
        find_register(instruction.val2, &i2);

        int64_t bigInt64 = (int64_t)registerArr[i] * registerArr[i2];
        int16_t high32 = (int16_t)(bigInt64 >> 32);
        int16_t low32 = (int16_t)bigInt64;

        registerArr[i] = low32;
        registerArr[i2] = high32;

        return SUCCESS;
    }
    else
    {
        printf("Error: at line %d. %s is not a valid register", instruction.line, instruction.val2);
        return INVALID_DATA;
    }
}

int div_(instruction_t instruction)
{
    uint8_t i;
    uint8_t i2;
    if (check_val(instruction.val1) == REGISTER)
    {
        find_register(instruction.val1, &i);
    }
    else
    {
        printf("Error: at line %d. %s is not a valid register", instruction.line, instruction.val1);
        return INVALID_DATA;
    }

    if (check_val(instruction.val2) == REGISTER)
    {
        int16_t tmp = registerArr[i2];

        registerArr[i2] = registerArr[i] % registerArr[i2];
        registerArr[i] = registerArr[i] / tmp;

        return SUCCESS;
    }
    else
    {
        printf("Error: at line %d. %s is not a valid register", instruction.line, instruction.val2);
        return INVALID_DATA;
    }
}

int and_(instruction_t instruction)
{
    uint8_t i;
    if (check_val(instruction.val1) == REGISTER)
    {
        find_register(instruction.val1, &i);
        switch (check_val(instruction.val2))
        {
        case REGISTER:
            uint8_t i2;
            find_register(instruction.val2, &i2);
            registerArr[i] = registerArr[i] & registerArr[i2];
            return SUCCESS;

        case IMMEDIATE:
            registerArr[i] = registerArr[i] & (int16_t)strtod(instruction.val2, '\0');
            return SUCCESS;
        default:
            printf("Error: at line %d. %s is not a valid input", instruction.line, instruction.val2);
            return INVALID_DATA;
        }
    }
    else
    {
        printf("Error: at line %d. %s is not a valid register", instruction.line, instruction.val1);
        return INVALID_DATA;
    }
}

int or_(instruction_t instruction)
{
    uint8_t i;
    if (check_val(instruction.val1) == REGISTER)
    {
        find_register(instruction.val1, &i);
        switch (check_val(instruction.val2))
        {
        case REGISTER:
            uint8_t i2;
            find_register(instruction.val2, &i2);
            registerArr[i] = registerArr[i] | registerArr[i2];
            return SUCCESS;

        case IMMEDIATE:
            registerArr[i] = registerArr[i] | (int16_t)strtod(instruction.val2, '\0');
            return SUCCESS;
        default:
            printf("Error: at line %d. %s is not a valid input", instruction.line, instruction.val2);
            return INVALID_DATA;
        }
    }
    else
    {
        printf("Error: at line %d. %s is not a valid register", instruction.line, instruction.val1);
        return INVALID_DATA;
    }
}

int xor_(instruction_t instruction)
{
    uint8_t i;
    if (check_val(instruction.val1) == REGISTER)
    {
        find_register(instruction.val1, &i);
        switch (check_val(instruction.val2))
        {
        case REGISTER:
            uint8_t i2;
            find_register(instruction.val2, &i2);
            registerArr[i] = registerArr[i] ^ registerArr[i2];
            return SUCCESS;

        case IMMEDIATE:
            registerArr[i] = registerArr[i] ^ (int16_t)strtod(instruction.val2, '\0');
            return SUCCESS;
        default:
            printf("Error: at line %d. %s is not a valid input", instruction.line, instruction.val2);
            return INVALID_DATA;
        }
    }
    else
    {
        printf("Error: at line %d. %s is not a valid register", instruction.line, instruction.val1);
        return INVALID_DATA;
    }
}

int load(instruction_t instruction)
{
    return GENERIC_ERROR;
}
int store(instruction_t instruction)
{
    return GENERIC_ERROR;
}
int not_(instruction_t instruction)
{
    return GENERIC_ERROR;
}
int cmpeq(instruction_t instruction)
{
    return GENERIC_ERROR;
}
int cmpge(instruction_t instruction)
{
    return GENERIC_ERROR;
}
int jtrue(instruction_t instruction)
{
    return GENERIC_ERROR;
}
int jfalse(instruction_t instruction)
{
    return GENERIC_ERROR;
}
int jump(instruction_t instruction)
{
    return GENERIC_ERROR;
}
int call(instruction_t instruction)
{
    return GENERIC_ERROR;
}
int ret(instruction_t instruction)
{
    return GENERIC_ERROR;
}
int halt(instruction_t instruction)
{
    return GENERIC_ERROR;
}
int int_(instruction_t instruction)
{
    return GENERIC_ERROR;
}

#endif