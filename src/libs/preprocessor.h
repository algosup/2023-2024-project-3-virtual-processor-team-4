#ifndef PREPROCESS_H
#define PREPROCESS_H
#include "utils.h"
#include "runtime.h"
#include <string.h>
#include <stdlib.h>

// ************************** FUNCTION DECLARATIONS **************************

int preprocess_line(char *lineContent, line_t *line, uint64_t *lineNumber);
int fill_line_struct(line_t *line, InstructionType_t *instructionType, char *dest, char *param1, char *param2, uint64_t *lineNumber);
int get_file_size(char *filename, uint64_t *size);
int read_file(char *filename, char *output, uint64_t size, uint64_t *numberOfLines);
int line_content_from_file_content(char *content, int lineNumber, char *lineContent);
int check_label_declaration(char *label);
int are_operation_params_valid(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber);
int is_first_operand_null(InstructionType_t *instructionId, char *param1, uint64_t *lineNumber);
int is_second_operand_null(InstructionType_t *instructionId, char *param2, uint64_t *lineNumber);
int is_third_operand_null(InstructionType_t *instructionId, char *param3, uint64_t *lineNumber);
int is_first_operand_not_null(InstructionType_t *instructionId, char *param1, uint64_t *lineNumber);
int is_second_operand_not_null(InstructionType_t *instructionId, char *param2, uint64_t *lineNumber);
int is_third_operand_not_null(InstructionType_t *instructionId, char *param3, uint64_t *lineNumber);
int is_first_operand_register(InstructionType_t *instructionId, char *param1, uint64_t *lineNumber);
int is_second_operand_register(InstructionType_t *instructionId, char *param2, uint64_t *lineNumber);
int is_third_operand_register(InstructionType_t *instructionId, char *param3, uint64_t *lineNumber);
int is_first_operand_immediate(InstructionType_t *instructionId, char *param1, uint64_t *lineNumber);
int is_second_operand_immediate(InstructionType_t *instructionId, char *param2, uint64_t *lineNumber);
int is_third_operand_immediate(InstructionType_t *instructionId, char *param3, uint64_t *lineNumber);
int is_first_operand_label(InstructionType_t *instructionId, char *param1, uint64_t *lineNumber);
int is_second_operand_label(InstructionType_t *instructionId, char *param2, uint64_t *lineNumber);
int is_first_operand_immediate_or_register(InstructionType_t *instructionId, char *param1, uint64_t *lineNumber);
int is_second_operand_immediate_or_register(InstructionType_t *instructionId, char *param2, uint64_t *lineNumber);
int is_third_operand_immediate_or_register(InstructionType_t *instructionId, char *param3, uint64_t *lineNumber);
int are_all_operand_registers(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber);
int are_all_operand_null(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber);
int is_first_two_operands_register_and_third_register_or_immediate(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber);
int is_first_operand_register_and_second_operand_register_or_immediate(InstructionType_t *instructionId, char *param1, char *param2, uint64_t *lineNumber);
int is_first_operand_register_and_second_operand_label(InstructionType_t *instructionId, char *param1, char *param2, uint64_t *lineNumber);
int get_operand_name(InstructionType_t instruction, char *output);
int find_operand(char *input, InstructionType_t *instruction);

// ************************** END FUNCTION DECLARATIONS **************************

// ************************** PREPROCESS AND DATA STRUCTURE FUNCTIONS **************************

int preprocess_line(char *lineContent, line_t *line, uint64_t *lineNumber) // Function to handle the whole preprocessing of a line
{
    if (lineContent[0] == '/' && lineContent[1] == '/') // Check if the line is a comment
    {
        line->mnemonic = SKIP;
        line->label = "\0";
        line->dest_t = NULL_;
        line->lineNumber = *lineNumber; // Returns skip instruciton with all params nullified
        return SUCCESS;
    }

    char *saveptr; // Position in the line
    char *token = strtok_r(lineContent, " ", &saveptr);
    char *opcode, *dest = NULL, *param1 = NULL, *param2 = NULL; // Size of 8 bytes will be changed because of labels in the future

    opcode = (token != NULL) ? token : "skip";

    // Extract the second word
    if ((token = strtok_r(NULL, " ", &saveptr)) != NULL)
        dest = token;

    // Extract the third word
    if ((token = strtok_r(NULL, " ", &saveptr)) != NULL)
        param1 = token;

    // Extract the fourth word
    if ((token = strtok_r(NULL, " ", &saveptr)) != NULL)
        param2 = token;

    if(check_label_declaration(opcode) == SUCCESS) // Checking if the line only contains a label declaration
    {
        printf("Label found on line %d\n", *lineNumber);
        line->label = opcode;
        line->mnemonic = LABEL_;
        line->lineNumber = *lineNumber;
        line->param1 = NULL_;
        return SUCCESS;
    }

    InstructionType_t *instructionType = (InstructionType_t *)malloc(sizeof(InstructionType_t)); // check for free afterwhile
    if (find_operand(opcode, instructionType) != SUCCESS)
    {
        printf("Error: Could not find a matching opcode on line %ld\n", *lineNumber);
        line->mnemonic = SKIP;
        line->lineNumber = *lineNumber;
        line->param1 = NULL_;
        line->label = NULL;
        return GENERIC_ERROR;
    }

    if (are_operation_params_valid(instructionType, dest, param1, param2, lineNumber) != SUCCESS)
    {
        line->mnemonic = SKIP;
        line->lineNumber = *lineNumber;
        line->param1 = NULL_;
        line->label = NULL;
        return GENERIC_ERROR;
    }
    if (fill_line_struct(line, instructionType, dest, param1, param2, lineNumber) != SUCCESS)
    {
        return GENERIC_ERROR;
    }
    return SUCCESS;
}

int fill_line_struct(line_t *line, InstructionType_t *instructionType, char *dest, char *param1, char *param2, uint64_t *lineNumber) // Create the final
{
    line->mnemonic = *instructionType;
    line->lineNumber = *lineNumber;
    line->label = NULL;

    if (dest != NULL)
    {
        if (find_register(param1, &line->dest) == SUCCESS)
        {
            line->dest_t = REGISTER;
        }
        //Label should be checked before I believe
    }
    else
    {
        line->param1 = NULL_;
    }

    if (param1 != NULL)
    {
        if (find_register(param1, &line->register2) == SUCCESS)
        {
            line->param1 = REGISTER;
        }
        else if (check_is_number(param1) == SUCCESS)
        {
            line->param1 = IMMEDIATE;
        }
        else if(check_is_label(param1) == SUCCESS)
        {
            line->label = param1;
        }
        else
        {
            printf("Error: Invalid operation (unhandled second param) on line %ld\n", *lineNumber);
            return GENERIC_ERROR;
        }
    }
    else
    {
        line->param1 = NULL_;
    }

    if(param2 != NULL)
    {
        if (find_register(param2, &line->register2) == SUCCESS)
        {
            line->param2_t = REGISTER;
        }
        else if (check_is_number(param2) == SUCCESS)
        {
            line->param2_t = IMMEDIATE;
            line->immediate2 = atoi(param2);
        }
        else
        {
            printf("Error: Invalid operation (unhandled third param) on line %ld\n", *lineNumber);
            return GENERIC_ERROR;
        }
    }
    else
    {
        line->param2_t = NULL_;
    }
    return SUCCESS;
}

// ************************** END PREPROCESS AND DATA STRUCTURE FUNCTIONS **************************

// ************************** FILE READING AND DATA EXTRACTION FUNCTIONS **************************

int get_file_size(char *filename, uint64_t *size) // Get the number of characters in the file to malloc the correct number of bytes
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

int read_file(char *filename, char *output, uint64_t size, uint64_t *numberOfLines) // Read content of specified file and store it in output
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

int line_content_from_file_content(char *content, int lineNumber, char *lineContent) // Extract the content of a specified line from a file content
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

int check_label_declaration(char *label)
{
    if (label[strlen(label) - 1] != ':')
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int are_operation_params_valid(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber)
{
    switch (*instructionId)
    {
    case SKIP:
        // return are_all_operand_null(instructionId, param1, param2, lineNumber);
        break;
    case MUL:
    case DIV:
        // return are_all_operand_null(instructionId, param1, param2, lineNumber);
        break;
    case ADD:
    case SUB:
    case AND:
    case OR:
    case XOR:
        // return is_first_operand_register_and_second_operand_register_or_immediate(instructionId, param1, param2, lineNumber);
        break;
    default:
        printf("Instruction not found");
        return GENERIC_ERROR;
        break;
        // Following instructions are not implemented yet
    }
}

int is_first_operand_null(InstructionType_t *instructionId, char *param1, uint64_t *lineNumber)
{
    // Check if first operand is null
    if (param1 != NULL)
    {
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction does not accept first operand on line: %ld\n", opcode, *lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_second_operand_null(InstructionType_t *instructionId, char *param2, uint64_t *lineNumber)
{
    // Check if second operand is null
    if (param2 != NULL)
    {
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction does not accept second operand on line: %ld\n", opcode, *lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_third_operand_null(InstructionType_t *instructionId, char *param3, uint64_t *lineNumber)
{
    // Check if third operand is null
    if (param3 != NULL)
    {
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction does not accept third operand on line: %d\n", opcode, *lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_not_null(InstructionType_t *instructionId, char *param1, uint64_t *lineNumber)
{
    // Check if first operand is not null
    if (param1 == NULL)
    {
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction requires first operand on line: %ld\n", opcode, *lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_second_operand_not_null(InstructionType_t *instructionId, char *param2, uint64_t *lineNumber)
{
    // Check if second operand is not null
    if (param2 == NULL)
    {
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction requires second operand on line: %ld\n", opcode, *lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_third_operand_not_null(InstructionType_t *instructionId, char *param3, uint64_t *lineNumber)
{
    // Check if third operand is not null
    if (param3 == NULL)
    {
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction requires third operand on line: %d\n", opcode, *lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_register(InstructionType_t *instructionId, char *param1, uint64_t *lineNumber)
{
    uint8_t paramVerificationReturn;
    char opcode[4];

    if (is_first_operand_not_null(instructionId, param1, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    if (find_register(param1, &paramVerificationReturn) != SUCCESS)
    {

        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction first parameter is not an existing register on line: %ld\n", opcode, *lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_second_operand_register(InstructionType_t *instructionId, char *param2, uint64_t *lineNumber)
{
    uint8_t paramVerificationReturn;
    char opcode[4];

    if (is_second_operand_not_null(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    if (find_register(param2, &paramVerificationReturn) != SUCCESS)
    {

        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction second parameter is not an existing register on line: %ld\n", opcode, *lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_third_operand_register(InstructionType_t *instructionId, char *param3, uint64_t *lineNumber)
{
    uint8_t paramVerificationReturn;
    char opcode[4];

    if (is_third_operand_not_null(instructionId, param3, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    if (find_register(param3, &paramVerificationReturn) != SUCCESS)
    {

        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction third parameter is not an existing register on line: %ld\n", opcode, *lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_immediate(InstructionType_t *instructionId, char *param1, uint64_t *lineNumber)
{
    char opcode[4];

    if (is_first_operand_not_null(instructionId, param1, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    if (check_is_number(param1) != SUCCESS)
    {
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction first parameter is not an immediate on line: %ld\n", opcode, *lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_second_operand_immediate(InstructionType_t *instructionId, char *param2, uint64_t *lineNumber)
{
    char opcode[4];

    if (is_second_operand_not_null(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    if (check_is_number(param2) != SUCCESS)
    {
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction second parameter is not an immediate on line: %ld\n", opcode, *lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_third_operand_immediate(InstructionType_t *instructionId, char *param3, uint64_t *lineNumber)
{
    char opcode[4];

    if (is_third_operand_not_null(instructionId, param3, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    if (check_is_number(param3) != SUCCESS)
    {
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction third parameter is not an immediate on line: %ld\n", opcode, *lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_label(InstructionType_t *instructionId, char *param1, uint64_t *lineNumber)
{
    char opcode[4];

    if (is_first_operand_not_null(instructionId, param1, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    if (check_is_label(param1) != SUCCESS)
    {
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction first parameter is not a label on line: %ld\n", opcode, *lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_second_operand_label(InstructionType_t *instructionId, char *param2, uint64_t *lineNumber)
{
    char opcode[4];

    if (is_second_operand_not_null(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    if (check_is_label(param2) != SUCCESS)
    {
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction second parameter is not a label on line: %ld\n", opcode, *lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_immediate_or_register(InstructionType_t *instructionId, char *param1, uint64_t *lineNumber)
{
    uint8_t paramVerificationReturn;
    char opcode[4];

    if (is_first_operand_not_null(instructionId, param1, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    if (check_is_number(param1) != SUCCESS && find_register(param1, &paramVerificationReturn) != SUCCESS)
    {
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction first parameter is nor an immediate or register on line: %ld\n", opcode, *lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_second_operand_immediate_or_register(InstructionType_t *instructionId, char *param2, uint64_t *lineNumber)
{
    uint8_t paramVerificationReturn;
    char opcode[4];

    if (is_second_operand_not_null(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    if (check_is_number(param2) != SUCCESS && find_register(param2, &paramVerificationReturn) != SUCCESS)
    {
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction second parameter is nor an immediate or register on line: %ld\n", opcode, *lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_third_operand_immediate_or_register(InstructionType_t *instructionId, char *param3, uint64_t *lineNumber)
{
    uint8_t paramVerificationReturn;
    char opcode[4];

    if (is_third_operand_not_null(instructionId, param3, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    if (check_is_number(param3) != SUCCESS && find_register(param3, &paramVerificationReturn) != SUCCESS)
    {
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction third parameter is nor an immediate or register on line: %ld\n", opcode, *lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int are_all_operand_registers(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber)
{
    if (is_first_operand_register(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_register(instructionId, param2, lineNumber) != SUCCESS || is_third_operand_register(instructionId, param3, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int are_all_operand_null(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber)
{
    if (is_first_operand_null(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_null(instructionId, param2, lineNumber) != SUCCESS || is_third_operand_null(instructionId, param3, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_two_operands_register_and_third_register_or_immediate(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber)
{
    if (is_first_operand_register(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_register(instructionId, param2, lineNumber) != SUCCESS || is_third_operand_immediate_or_register(instructionId, param3, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_register_and_second_operand_register_or_immediate(InstructionType_t *instructionId, char *param1, char *param2, uint64_t *lineNumber)
{
    if (is_first_operand_register(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_immediate_or_register(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_register_and_second_operand_label(InstructionType_t *instructionId, char *param1, char *param2, uint64_t *lineNumber)
{
    if (is_first_operand_register(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_label(instructionId, param2, lineNumber) != SUCCESS)
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
    case ADD:
        strcpy(output, "noop");
        break;
    case SUB:
        strcpy(output, "set");
        break;
    case MUL:
        strcpy(output, "copy");
        break;
    case DIV:
        strcpy(output, "load");
        break;
    case OR:
        strcpy(output, "store");
        break;
    case AND:
        strcpy(output, "add");
        break;
    case XOR:
        strcpy(output, "sub");
        break;
    case TEQ:
        strcpy(output, "mul");
        break;
    case TNE:
        strcpy(output, "div");
        break;
    case TLT:
        strcpy(output, "not");
        break;
    case TLE:
        strcpy(output, "and");
        break;
    case TGT:
        strcpy(output, "or");
        break;
    case TGE:
        strcpy(output, "xor");
        break;
    case PUSH:
        strcpy(output, "cmpeq");
        break;
    case POP:
        strcpy(output, "cmpge");
        break;
    case STR:
        strcpy(output, "jtrue");
        break;
    case LD:
        strcpy(output, "jfalse");
        break;
    case STRP:
        strcpy(output, "jump");
        break;
    case LDP:
        strcpy(output, "call");
        break;
    case XCHG:
        strcpy(output, "ret");
        break;
    case ADDI:
        strcpy(output, "halt");
        break;
    case SUBI:
        strcpy(output, "int");
        break;
    case ORI:
        strcpy(output, "int");
        break;
    case ANDI:
        strcpy(output, "int");
        break;
    case XORI:
        strcpy(output, "int");
        break;
    case TEQI:
        strcpy(output, "int");
        break;
    case TNEI:
        strcpy(output, "int");
        break;
    case TLTI:
        strcpy(output, "int");
        break;
    case TLEI:
        strcpy(output, "int");
        break;
    case TGTI:
        strcpy(output, "int");
        break;
    case TGEI:
        strcpy(output, "int");
        break;
    case STRI:
        strcpy(output, "int");
        break;
    case LDI:
        strcpy(output, "int");
        break;
    case JZ:
        strcpy(output, "int");
        break;
    case JNZ:
        strcpy(output, "int");
        break;
    case CALL:
        strcpy(output, "int");
        break;
    case RET:
        strcpy(output, "int");
        break;
    case JABS:
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
    else if (strcmp("or", input) == 0)
    {
        *instruction = OR;
    }
    else if (strcmp("and", input) == 0)
    {
        *instruction = AND;
    }
    else if (strcmp("xor", input) == 0)
    {
        *instruction = XOR;
    }
    else if (strcmp("teq", input) == 0)
    {
        *instruction = TEQ;
    }
    else if (strcmp("tne", input) == 0)
    {
        *instruction = TNE;
    }
    else if (strcmp("tlt", input) == 0)
    {
        *instruction = TLT;
    }
    else if (strcmp("tle", input) == 0)
    {
        *instruction = TLE;
    }
    else if (strcmp("tgt", input) == 0)
    {
        *instruction = TGT;
    }
    else if (strcmp("tge", input) == 0)
    {
        *instruction = TGE;
    }
    else if (strcmp("push", input) == 0)
    {
        *instruction = PUSH;
    }
    else if (strcmp("pop", input) == 0)
    {
        *instruction = POP;
    }
    else if (strcmp("str", input) == 0)
    {
        *instruction = STR;
    }
    else if (strcmp("ld", input) == 0)
    {
        *instruction = LD;
    }
    else if (strcmp("strp", input) == 0)
    {
        *instruction = STRP;
    }
    else if (strcmp("ldp", input) == 0)
    {
        *instruction = LDP;
    }
    else if (strcmp("xchg", input) == 0)
    {
        *instruction = XCHG;
    }
    else if (strcmp("addi", input) == 0)
    {
        *instruction = ADDI;
    }
    else if (strcmp("subi", input) == 0)
    {
        *instruction = SUBI;
    }
    else if (strcmp("ori", input) == 0)
    {
        *instruction = ORI;
    }
    else if (strcmp("andi", input) == 0)
    {
        *instruction = ANDI;
    }
    else if (strcmp("xori", input) == 0)
    {
        *instruction = XORI;
    }
    else if (strcmp("teqi", input) == 0)
    {
        *instruction = TEQI;
    }
    else if (strcmp("tnei", input) == 0)
    {
        *instruction = TNEI;
    }
    else if (strcmp("tlti", input) == 0)
    {
        *instruction = TLTI;
    }
    else if (strcmp("tlei", input) == 0)
    {
        *instruction = TLEI;
    }
    else if (strcmp("tgti", input) == 0)
    {
        *instruction = TGTI;
    }
    else if (strcmp("tgei", input) == 0)
    {
        *instruction = TGEI;
    }
    else if (strcmp("stri", input) == 0)
    {
        *instruction = STRI;
    }
    else if (strcmp("ldi", input) == 0)
    {
        *instruction = LDI;
    }
    else if (strcmp("jz", input) == 0)
    {
        *instruction = JZ;
    }
    else if (strcmp("jnz", input) == 0)
    {
        *instruction = JNZ;
    }
    else if (strcmp("call", input) == 0)
    {
        *instruction = CALL;
    }
    else if (strcmp("ret", input) == 0)
    {
        *instruction = RET;
    }
    else if (strcmp("jabs", input) == 0)
    {
        *instruction = JABS;
    }
    else
    {
        return GENERIC_ERROR;
    }
    return SUCCESS;
};

// ************************** END TRANSLATION OPCODE - INSTRUCTION CODE DEFINITIONS **************************
#endif