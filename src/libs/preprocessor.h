#ifndef PREPROCESS_H
#define PREPROCESS_H
#include "utils.h"
#include "runtime.h"
#include <string.h>
#include <stdlib.h>


// ************************** FUNCTION DECLARATIONS **************************

int is_first_operand_null(InstructionType_t *instructionId, char *param1, int *lineNumber);
int is_second_operand_null(InstructionType_t *instructionId, char *param2, int *lineNumber);
int is_first_operand_not_null(InstructionType_t *instructionId, char *param1, int *lineNumber);
int is_second_operand_not_null(InstructionType_t *instructionId, char *param2, int *lineNumber);
int is_first_operand_register(InstructionType_t *instructionId, char *param1, int *lineNumber);
int is_second_operand_register(InstructionType_t *instructionId, char *param2, int *lineNumber);
int is_first_operand_immediate(InstructionType_t *instructionId, char *param1, int *lineNumber);
int is_second_operand_immediate(InstructionType_t *instructionId, char *param2, int *lineNumber);
int is_first_operand_immediate_or_register(InstructionType_t *instructionId, char *param1, int *lineNumber);
int is_second_operand_immediate_or_register(InstructionType_t *instructionId, char *param2, int *lineNumber);
int are_both_operands_registers(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber);
int are_both_operands_null(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber);
int are_both_operands_immediate(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber);
int are_both_operands_immediate_or_register(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber);
int is_first_operand_register_and_second_operand_register_or_immediate(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber);
int is_first_operand_register_and_second_operand_null(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber);
int is_first_operand_register_or_immediate_and_second_operand_register_or_immediate(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber);
int is_first_operand_register_or_immediate_and_second_operand_null(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber);
int is_first_operand_register_and_second_operand_immediate(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber);
int get_operand_name(InstructionType_t instruction, char *output);
int find_operand(char *input, InstructionType_t *instruction);
int fill_line_struct(line_t *line, InstructionType_t *instructionType, char *word2, char *word3, int *lineNumber);
int are_operation_params_valid(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber);
int preprocess_line(char *lineContent, line_t *line, int *lineNumber);
int read_file(char *filename, char *output, int size, int *numberOfLines);
int line_content_from_file_content(char *content, int lineNumber, char *lineContent);
int get_file_size(char *filename, int *size);

// ************************** END FUNCTION DECLARATIONS **************************

// ************************** PREPROCESS AND DATA STRUCTURE FUNCTIONS **************************

int preprocess_line(char *lineContent, line_t *line, int *lineNumber) // Function to handle the whole preprocessing of a line
{
    if (lineContent[0] == '/' && lineContent[1] == '/') // Check if the line is a comment
    {
        line->mnemonic = SKIP;
        line->param1 = NULL_;
        line->register1 = NULL_;
        line->lineNumber = lineNumber; // Returns skip instruciton with all params nullified
        return SUCCESS;
    }

    char *token = strtok(lineContent, " ");
    char *opcode, *param1, *param2;

    // Extract the opcode
    if (token != NULL)
    {
        opcode = token;
        token = strtok(NULL, " ");
    }
    else
    {
        opcode = "skip"; // By default, we skip the line if it is empty
    }

    // Extract the second word
    if (token != NULL)
    {
        param1 = token;
        token = strtok(NULL, " ");
    }
    else
    {
        param1 = NULL; // By default, undefined arguments are nullified
    }

    // Extract the third word
    if (token != NULL)
    {
        param2 = token;
    }
    else
    {
        param2 = NULL; // By default, undefined arguments are nullified
    }

    InstructionType_t *instructionType = (InstructionType_t *)malloc(sizeof(InstructionType_t)); // check for free afterwhile
    if (find_operand(opcode, instructionType) != SUCCESS)
    {
        printf("Error: Invalid operation on line %d\n", *lineNumber);
        line->mnemonic = SKIP;
        line->lineNumber = lineNumber;
        line->param1 = NULL_;
        line->labelDeclaration = NULL;
        return GENERIC_ERROR;
    }
    if (are_operation_params_valid(instructionType, param1, param2, lineNumber) != SUCCESS)
    {
        line->mnemonic = SKIP;
        line->lineNumber = lineNumber;
        line->param1 = NULL_;
        line->labelDeclaration = NULL;
        return GENERIC_ERROR;
    }
    if (fill_line_struct(line, instructionType, param1, param2, lineNumber) != SUCCESS)
    {
        return GENERIC_ERROR;
    }
    return SUCCESS;
}

int fill_line_struct(line_t *line, InstructionType_t *instructionType, char *param1, char *param2, int *lineNumber) //Create the final 
{
    line->mnemonic = *instructionType;
    line->lineNumber = lineNumber;
    line->labelDeclaration = NULL;
    if (param1 != NULL)
    {
        if (find_register(param1, &line->register1) == SUCCESS)
        {
            line->param1 = REGISTER;
        }
        else if (check_is_number(param1) == SUCCESS)
        {
            line->param1 = IMMEDIATE;
        }
        else if (check_is_label(param1) == SUCCESS)
        {
            line->param1 = LABEL;
            line->labelDeclaration = param1;
        }
    }
    else
    {
        line->param1 = NULL_;
    }
    if (param2 != NULL)
    {
        if (find_register(param2, &line->register2) == SUCCESS)
        {
            line->param2 = REGISTER;
        }
        else if (check_is_number(param2) == SUCCESS)
        {
            line->param2 = IMMEDIATE;
        }
        else
        {
            printf("Error: Invalid operation (unhandled second param) on line %d\n", *lineNumber);
            return GENERIC_ERROR;
        }
    }
    else
    {
        line->param2 = NULL_;
    }
    return SUCCESS;
}

// ************************** END PREPROCESS AND DATA STRUCTURE FUNCTIONS **************************

// ************************** FILE READING AND DATA EXTRACTION FUNCTIONS **************************

int get_file_size(char *filename, int *size) // Get the number of characters in the file to malloc the correct number of bytes
{
    FILE *fp;

    *size = 0;
    char c;

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Could not open file: %s\n\n", filename);
        return FILE_NOT_FOUND;
    }

    for (c = getc(fp); c != EOF; c = getc(fp))
        *size += 1;

    fclose(fp);

    return SUCCESS;
}

int read_file(char *filename, char *output, int size, int *numberOfLines) //Read content of specified file and store it in output
{
    FILE *ptr;
    char ch;
    ptr = fopen(filename, "r");

    if (ptr == NULL)
    {
        printf("Failed to open file: %s\n\n", filename);
        return FILE_NOT_FOUND;
    }

    int count = 0;
    while (!feof(ptr))
    {
        ch = fgetc(ptr);
        if (ch == '\n')
        {
            *numberOfLines += 1;
        }
        output[count] = ch;
        count++;
    }

    output[count - 1] = '\0';

    fclose(ptr);
    return SUCCESS;
}

int line_content_from_file_content(char *content, int lineNumber, char *lineContent) //Extract the content of a specified line from a file content
{
    // Returns the content of the lineNumber until next \n
    int i = 0;

    if (content == NULL)
    {
        printf("Content is NULL\n");
        return GENERIC_ERROR;
    }

    int contentLength = strlen(content);
    if (lineNumber >= contentLength)
    {
        printf("Line number is out of bounds\n");
        return GENERIC_ERROR;
    }

    // Find the starting position of the line
    int currentLine = 0;
    while (currentLine < lineNumber)
    {
        if (content[i] == '\n')
        {
            currentLine++;
        }
        i++;
    }

    // Store the content of the line in line_content
    int j = 0;
    while (content[i] != '\n' && content[i] != '\0')
    {
        lineContent[j++] = content[i++];
    }

    // Add null terminator to line_content
    lineContent[j] = '\0';

    return SUCCESS;
}

// ************************** END FILE READING AND DATA EXTRACTION FUNCTIONS **************************

// ********************* INSTRUCTION PARAMS VERIFICATION *********************

int are_operation_params_valid(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber)
{
    switch (*instructionId)
    {
    case SKIP:
    case NOOP:
        return are_both_operands_null(instructionId, param1, param2, lineNumber);
        break;
    case SET:
        return is_first_operand_register_and_second_operand_immediate(instructionId, param1, param2, lineNumber);
        break;
    case NOT:
        return is_first_operand_register_and_second_operand_null(instructionId, param1, param2, lineNumber);
        break;
    case STORE:
        return are_both_operands_immediate_or_register(instructionId, param1, param2, lineNumber);
        break;
    case COPY:
    case MUL:
    case DIV:
        return are_both_operands_registers(instructionId, param1, param2, lineNumber);
        break;
    case LOAD:
    case ADD:
    case SUB:
    case AND:
    case OR:
    case XOR:
        return is_first_operand_register_and_second_operand_register_or_immediate(instructionId, param1, param2, lineNumber);
        break;
    default:
        printf("Instruction not found");
        return GENERIC_ERROR;
        break;
        // Following instructions are not implemented yet
    }
}

int is_first_operand_null(InstructionType_t *instructionId, char *param1, int *lineNumber)
{
    // Check if first operand is null
    if (param1 != NULL)
    {
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction does not accept first operand on line: %d\n", opcode, lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_second_operand_null(InstructionType_t *instructionId, char *param2, int *lineNumber)
{
    // Check if second operand is null
    if (param2 != NULL)
    {
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction does not accept second operand on line: %d\n", opcode, lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_not_null(InstructionType_t *instructionId, char *param1, int *lineNumber)
{
    // Check if first operand is not null
    if (param1 == NULL)
    {
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction requires first operand on line: %d\n", opcode, lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_second_operand_not_null(InstructionType_t *instructionId, char *param2, int *lineNumber)
{
    // Check if second operand is not null
    if (param2 == NULL)
    {
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction requires second operand on line: %d\n", opcode, lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_register(InstructionType_t *instructionId, char *param1, int *lineNumber)
{
    int paramVerificationReturn;
    char opcode[4];

    if (is_first_operand_not_null(instructionId, param1, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    if (find_register(param1, &paramVerificationReturn) != SUCCESS)
    {

        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction first parameter is not an existing register on line: %d\n", opcode, lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_second_operand_register(InstructionType_t *instructionId, char *param2, int *lineNumber)
{
    int paramVerificationReturn;
    char opcode[4];

    if(is_second_operand_not_null(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    
    if (find_register(param2, &paramVerificationReturn) != SUCCESS)
    {

        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction second parameter is not an existing register on line: %d\n", opcode, lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_immediate(InstructionType_t *instructionId, char *param1, int *lineNumber)
{
    int paramVerificationReturn;
    char opcode[4];

    if(is_first_operand_not_null(instructionId, param1, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    if (check_is_number(param1) != SUCCESS)
    {
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction first parameter is not an immediate on line: %d\n", opcode, lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_second_operand_immediate(InstructionType_t *instructionId, char *param2, int *lineNumber)
{
    int paramVerificationReturn;
    char opcode[4];

    if(is_second_operand_not_null(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    if (check_is_number(param2) != SUCCESS)
    {
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction second parameter is not an immediate on line: %d\n", opcode, lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_immediate_or_register(InstructionType_t *instructionId, char *param1, int *lineNumber)
{
    int paramVerificationReturn;
    char opcode[4];

    if(is_first_operand_not_null(instructionId, param1, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    if (check_is_number(param1) != SUCCESS && find_register(param1, &paramVerificationReturn) != SUCCESS)
    {
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction first parameter is nor an immediate or register on line: %d\n", opcode, lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_second_operand_immediate_or_register(InstructionType_t *instructionId, char *param2, int *lineNumber)
{
    int paramVerificationReturn;
    char opcode[4];

    if(is_second_operand_not_null(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    if (check_is_number(param2) != SUCCESS && find_register(param2, &paramVerificationReturn) != SUCCESS)
    {
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction second parameter is nor an immediate or register on line: %d\n", opcode, lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int are_both_operands_registers(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber)
{
    if (is_first_operand_register(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_register(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int are_both_operands_null(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber)
{
    if (is_first_operand_null(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_null(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int are_both_operands_immediate(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber)
{
    if (is_first_operand_immediate(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_immediate(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int are_both_operands_immediate_or_register(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber)
{
    if (is_first_operand_immediate_or_register(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_immediate_or_register(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_register_and_second_operand_register_or_immediate(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber)
{
    if (is_first_operand_register(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_immediate_or_register(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_register_and_second_operand_null(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber)
{
    if (is_first_operand_register(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_null(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_register_or_immediate_and_second_operand_register_or_immediate(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber)
{
    if (is_first_operand_immediate_or_register(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_immediate_or_register(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_register_or_immediate_and_second_operand_null(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber)
{
    if (is_first_operand_immediate_or_register(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_null(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_register_and_second_operand_immediate(InstructionType_t *instructionId, char *param1, char *param2, int *lineNumber)
{
    if (is_first_operand_register(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_immediate(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

// ********************* END OF INSTRUCTION PARAMS VERIFICATION *********************

// ************************** TRANSLATION OPCODE - INSTRUCTION CODE DEFINITIONS **************************

int get_operand_name(InstructionType_t instruction, char *output)
{
    switch (instruction)
    {
    case SKIP:
        strcpy(output, "skip");
        break;
    case NOOP:
        strcpy(output, "noop");
        break;
    case SET:
        strcpy(output, "set");
        break;
    case COPY:
        strcpy(output, "copy");
        break;
    case LOAD:
        strcpy(output, "load");
        break;
    case STORE:
        strcpy(output, "store");
        break;
    case ADD:
        strcpy(output, "add");
        break;
    case SUB:
        strcpy(output, "sub");
        break;
    case MUL:
        strcpy(output, "mul");
        break;
    case DIV:
        strcpy(output, "div");
        break;
    case NOT:
        strcpy(output, "not");
        break;
    case AND:
        strcpy(output, "and");
        break;
    case OR:
        strcpy(output, "or");
        break;
    case XOR:
        strcpy(output, "xor");
        break;
    case CMPEQ:
        strcpy(output, "cmpeq");
        break;
    case CMPGE:
        strcpy(output, "cmpge");
        break;
    case JTRUE:
        strcpy(output, "jtrue");
        break;
    case JFALSE:
        strcpy(output, "jfalse");
        break;
    case JUMP:
        strcpy(output, "jump");
        break;
    case CALL:
        strcpy(output, "call");
        break;
    case RET:
        strcpy(output, "ret");
        break;
    case HALT:
        strcpy(output, "halt");
        break;
    case INT:
        strcpy(output, "int");
        break;
    default:
        return GENERIC_ERROR;
    }
    return SUCCESS;
}

int find_operand(char *input, InstructionType_t *instruction)
{
    if (strcmp("skip", input) == 0)
    {
        *instruction = SKIP;
    }
    else if (strcmp("noop", input) == 0)
    {
        *instruction = NOOP;
    }
    else if (strcmp("set", input) == 0)
    {
        *instruction = SET;
    }
    else if (strcmp("copy", input) == 0)
    {
        *instruction = COPY;
    }
    else if (strcmp("load", input) == 0)
    {
        *instruction = LOAD;
    }
    else if (strcmp("store", input) == 0)
    {
        *instruction = STORE;
    }
    else if (strcmp("add", input) == 0)
    {
        *instruction = ADD;
    }
    else if (strcmp("sub", input) == 0)
    {
        *instruction = SUB;
    }
    else if (strcmp("mul", input) == 0)
    {
        *instruction = MUL;
    }
    else if (strcmp("div", input) == 0)
    {
        *instruction = DIV;
    }
    else if (strcmp("not", input) == 0)
    {
        *instruction = NOT;
    }
    else if (strcmp("and", input) == 0)
    {
        *instruction = AND;
    }
    else if (strcmp("or", input) == 0)
    {
        *instruction = OR;
    }
    else if (strcmp("xor", input) == 0)
    {
        *instruction = XOR;
    }
    else if (strcmp("cmpeq", input) == 0)
    {
        *instruction = CMPEQ;
    }
    else if (strcmp("cmpge", input) == 0)
    {
        *instruction = CMPGE;
    }
    else if (strcmp("jtrue", input) == 0)
    {
        *instruction = JTRUE;
    }
    else if (strcmp("jfalse", input) == 0)
    {
        *instruction = JFALSE;
    }
    else if (strcmp("jump", input) == 0)
    {
        *instruction = JUMP;
    }
    else if (strcmp("call", input) == 0)
    {
        *instruction = CALL;
    }
    else if (strcmp("ret", input) == 0)
    {
        *instruction = RET;
    }
    else if (strcmp("halt", input) == 0)
    {
        *instruction = HALT;
    }
    else if (strcmp("int", input) == 0)
    {
        *instruction = INT;
    }
    else
    {
        return GENERIC_ERROR;
    }
    return SUCCESS;
};

// ************************** END TRANSLATION OPCODE - INSTRUCTION CODE DEFINITIONS **************************
#endif