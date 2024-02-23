#ifndef PREPROCESS_H
#define PREPROCESS_H
#include "utils.h"
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

// ************************** FUNCTION DECLARATIONS **************************

int preprocess_line(char *lineContent, line_t *line, uint64_t *lineNumber);
int fill_line_struct(line_t *line, InstructionType_t *instructionType, char *dest, char *param1, char *param2, uint64_t *lineNumber);
int get_file_size(char *filename, uint64_t *size);
int read_file(char *filename, char *output, uint64_t size, uint64_t *numberOfLines);
int line_content_from_file_content(char *content, int lineNumber, char *lineContent);
int check_label_declaration(InstructionType_t *instructionId, char *label);
int are_operation_params_valid(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber);
uint8_t count_non_null_params(char *param1, char *param2, char *param3);
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
int is_second_operand_label(InstructionType_t *instructionId, char *param2, uint64_t *lineNumber);
int is_first_operand_immediate_or_label(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber);
int is_first_operand_immediate_or_register(InstructionType_t *instructionId, char *param1, uint64_t *lineNumber);
int is_second_operand_immediate_or_register(InstructionType_t *instructionId, char *param2, uint64_t *lineNumber);
int is_third_operand_immediate_or_register(InstructionType_t *instructionId, char *param3, uint64_t *lineNumber);
int are_all_operand_registers(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber);
int are_all_operand_null(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber);
int is_first_operand_register_or_first_and_second_operand_registers(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber);
int is_first_operand_register_and_second_operand_immediate(InstructionType_t *instructionId, char *param1, char *param2, uint64_t *lineNumber);
int is_first_operand_register_and_second_operand_immediate_or_are_two_first_operands_registers_and_third_immediate(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber, uint8_t paramsNumber);
int is_first_operand_register_and_second_operand_immediate_or_label(InstructionType_t *instructionId, char *param1, char *param2, uint64_t *lineNumber);
int are_two_first_operand_registers(InstructionType_t *instructionId, char *param1, char *param2, uint64_t *lineNumber);
int are_two_first_operand_registers_and_third_immediate(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber);
int are_first_two_operands_register_and_third_register_or_immediate(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber);
int are_two_first_operand_registers_or_are_all_operands_registers(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber, uint8_t paramsNumber);
int is_first_operand_register_and_second_operand_register_or_immediate(InstructionType_t *instructionId, char *param1, char *param2, uint64_t *lineNumber);
int is_first_operand_register_or_is_first_operand_register_and_second_operand_immediate_or_label(InstructionType_t *instructionId, char *param1, char *param2, uint64_t *lineNumber, uint8_t paramsNumber);
int are_first_two_operands_register_and_third_register_or_immediate_or_is_first_operand_register_and_second_operand_register_or_immediate(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber, uint8_t paramsNumber);
int get_operand_name(InstructionType_t instruction, char *output);
int find_operand(char *opcode, InstructionType_t *instructionType);

// ************************** END FUNCTION DECLARATIONS **************************

// ************************** PREPROCESS AND DATA STRUCTURE FUNCTIONS **************************

int preprocess_line(char *lineContent, line_t *line, uint64_t *lineNumber)
{
    if (lineContent[0] == '/' && lineContent[1] == '/')
    {
        line->mnemonic = SKIP;
        line->labelDef = NULL;
        line->lineNumber = *lineNumber;
        return SUCCESS;
    }

    char *token = strtok(lineContent, " ");
    char *opcode = (token != NULL) ? token : "skip";

    char *dest = NULL;
    char *param1 = NULL;
    char *param2 = NULL;

    bool areNextArgsComments = false;

    while ((token = strtok(NULL, " ")) != NULL)
    {
        if (token[0] == '/' && token[1] == '/')
        {
            break; // Ignore comments
        }
        if (dest == NULL)
        {
            dest = malloc(sizeof(char) * strlen(token));
            strcpy(dest, token);
        }
        else if (param1 == NULL)
        {
            param1 = malloc(sizeof(char) * strlen(token));
            strcpy(param1, token);
        }
        else if (param2 == NULL)
        {
            param2 = malloc(sizeof(char) * strlen(token));
            strcpy(param2, token);
        }
        else
        {
            printf("Error: Too many arguments passed in operation on line: %" PRIu64 "\n", *lineNumber);
            free(dest);
            free(param1);
            free(param2);
            return GENERIC_ERROR;
        }
    }

    InstructionType_t *instructionType = malloc(sizeof(InstructionType_t));
    if (instructionType == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        free(dest);
        free(param1);
        free(param2);
        return GENERIC_ERROR;
    }

    int labelDeclarationCode = check_label_declaration(instructionType, opcode);
    switch (labelDeclarationCode)
    {
    case SUCCESS:
        if (*instructionType == LABEL_)
        {
            if (strlen(opcode) > 0 && opcode[strlen(opcode) - 1] == ':')
            {
                line->labelDef = malloc(sizeof(char) * strlen(opcode));
                strcpy(line->labelDef, opcode);
                if (line->labelDef == NULL)
                {
                    fprintf(stderr, "Memory allocation failed!\n");
                    free(dest);
                    free(param1);
                    free(param2);
                    free(instructionType);
                    return GENERIC_ERROR;
                }
                line->dest_t = LABEL;
                line->mnemonic = LABEL_;
                opcode[strlen(opcode) - 1] = '\0';
                strcpy(line->labelDef, opcode);
                line->lineNumber = *lineNumber;
                return SUCCESS;
            }
            else
            {
                printf("Error: Improper label declaration on line: %" PRIu64 "\n", *lineNumber);
                free(dest);
                free(param1);
                free(param2);
                free(instructionType);
                return GENERIC_ERROR;
            }
        }
        break;
    case REGISTER_INSTEAD_OF_LABEL:
        printf("Error: Register instead of label on line: %" PRIu64 "\n", *lineNumber);
        free(dest);
        free(param1);
        free(param2);
        free(instructionType);
        return GENERIC_ERROR;
    }

    if (find_operand(opcode, instructionType) != SUCCESS)
    {
        printf("Error: Could not find a matching opcode on line: %" PRIu64 "\n", *lineNumber);
        free(dest);
        free(param1);
        free(param2);
        free(instructionType);
        return GENERIC_ERROR;
    }

    if (are_operation_params_valid(instructionType, dest, param1, param2, lineNumber) != SUCCESS)
    {
        free(dest);
        free(param1);
        free(param2);
        free(instructionType);
        return GENERIC_ERROR;
    }

    if (fill_line_struct(line, instructionType, dest, param1, param2, lineNumber) != SUCCESS)
    {
        free(dest);
        free(param1);
        free(param2);
        free(instructionType);
        return GENERIC_ERROR;
    }

    free(instructionType);
    return SUCCESS;
}

int fill_line_struct(line_t *line, InstructionType_t *instructionType, char *dest, char *param1, char *param2, uint64_t *lineNumber) // Create the final
{
    line->mnemonic = *instructionType;
    line->lineNumber = *lineNumber;

    if (dest != NULL)
    {
        if (find_register(dest, &line->dest) == SUCCESS)
        {
            line->dest_t = REGISTER;
        }
        else if (check_is_label(dest) == SUCCESS)
        {
            line->dest_t = LABEL;
            line->labelCall = dest;
        }
    }
    else
    {
        line->dest = NULL_;
    }

    if (param1 != NULL)
    {
        if (find_register(param1, &line->register1) == SUCCESS)
        {
            line->param1_t = REGISTER;
        }
        else if (check_is_number(param1) == SUCCESS)
        {
            if (param1[0] == 'x' || param1[0] == 'X')
            {
                if (hex_to_decimal(param1 + 1, &line->immediate1) != SUCCESS)
                {
                    printf("Error: Invalid hexadecimal value on line: %" PRIu64 "\n", *lineNumber);
                    return GENERIC_ERROR;
                }
                printf("immediate1: %d\n", line->immediate1);
                line->param1_t = IMMEDIATE;
            }
            else
            {
                line->immediate1 = atoi(param1);
                line->param1_t = IMMEDIATE;
            }
        }
        else if (check_is_label(param1) == SUCCESS)
        {
            line->param1_t = LABEL;
            line->labelCall1 = param1;
        }
        else
        {
            printf("Error: Invalid operation (unhandled second param) on line: %" PRIu64 "\n", *lineNumber);
            return GENERIC_ERROR;
        }
    }
    else
    {
        line->param1_t = NULL_;
    }

    if (param2 != NULL)
    {
        if (find_register(param2, &line->register2) == SUCCESS)
        {
            // line->register2 = atoi(param2);
            line->param2_t = REGISTER;
        }
        else if (check_is_number(param2) == SUCCESS)
        {
            if (param2[0] == 'x' || param2[0] == 'X')
            {
                if (hex_to_decimal(param2 + 1, &line->immediate2) != SUCCESS)
                {
                    printf("Error: Invalid hexadecimal value on line: %" PRIu64 "\n", *lineNumber);
                    return GENERIC_ERROR;
                }
                printf("immediate2: %d\n", line->immediate2);
                line->param2_t = IMMEDIATE;
            }
            else
            {
                line->immediate1 = atoi(param2);
                line->param2_t = IMMEDIATE;
            }
        }
        else
        {
            printf("Error: Invalid operation (unhandled third param) on line: %" PRIu64 "\n", *lineNumber);
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

int check_label_declaration(InstructionType_t *instructionId, char *label)
{
    if (label[strlen(label) - 1] == ':')
    {
        // Remove the last character from label
        char *newLabel = (char *)malloc((strlen(label) - 1) * sizeof(char));
        strcpy(newLabel, label);
        newLabel[strlen(newLabel) - 1] = '\0';
        int returnedCode = check_is_label(newLabel);
        switch (returnedCode)
        {
        case SUCCESS:
            *instructionId = LABEL_;
            return SUCCESS;
            break;
        case REGISTER_INSTEAD_OF_LABEL:
            *instructionId = SKIP;
            return REGISTER_INSTEAD_OF_LABEL;
            break;
        default:
            return GENERIC_ERROR;
            break;
        }
    }
    else
    {
        *instructionId = SKIP;
        return GENERIC_ERROR;
    }
    *instructionId = SKIP;
    return GENERIC_ERROR;
}

int are_operation_params_valid(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber)
{ // Check if the parameters of an operation are valid (WIP: Waiting for all the instructions in functional appendix)
    switch (*instructionId)
    {
    case SKIP:
    case RET:
        return are_all_operand_null(instructionId, param1, param2, param3, lineNumber);
        break;
    case ABS:
        return is_first_operand_register_or_first_and_second_operand_registers(instructionId, param1, param2, param3, lineNumber);
        break;
    case ADD:
    case AND:
    case DIV:
    case MUL:
    case OR:
    case SUB:
    case XOR:
        return are_two_first_operand_registers_or_are_all_operands_registers(instructionId, param1, param2, param3, lineNumber, count_non_null_params(param1, param2, param3));
        break;
    case ADDI:
    case ANDI:
    case ORI:
    case SUBI:
    case XORI:
        return is_first_operand_register_and_second_operand_immediate_or_are_two_first_operands_registers_and_third_immediate(instructionId, param1, param2, param3, lineNumber, count_non_null_params(param1, param2, param3));
        break;
    case B:
    case CALL:
        return is_first_operand_register_or_is_first_operand_register_and_second_operand_immediate_or_label(instructionId, param1, param2, lineNumber, count_non_null_params(param1, param2, param3));
        break;
    case BI:
    case CALLI:
    case JMP:
        return is_first_operand_immediate_or_label(instructionId, param1, param2, param3, lineNumber);
        break;
    case BNZ:
    case BZ:
        return is_first_operand_register_and_second_operand_immediate_or_label(instructionId, param1, param2, lineNumber);
        break;
    case LDI:
    case SET:
    case STRI:
        return is_first_operand_register_and_second_operand_immediate(instructionId, param1, param2, lineNumber);
        break;
    case POP:
    case PUSH:
        return is_first_operand_register(instructionId, param1, lineNumber);
        break;
    case XCHG:
    case LD:
    case LDP:
    case STR:
    case STRP:
        return are_two_first_operand_registers(instructionId, param1, param2, lineNumber);
        break;
    case TEQ:
    case TGE:
    case TGT:
    case TLE:
    case TLT:
    case TNE:
        return are_all_operand_registers(instructionId, param1, param2, param3, lineNumber);
        break;
    case TEQI:
    case TGEI:
    case TGTI:
    case TLEI:
    case TLTI:
    case TNEI:
        return are_two_first_operand_registers_and_third_immediate(instructionId, param1, param2, param3, lineNumber);
        break;
    default:
        printf("Instruction not found");
        return GENERIC_ERROR;
        break;
    }
}

uint8_t count_non_null_params(char *param1, char *param2, char *param3)
{
    uint8_t paramCount = 0;
    char *params[] = {param1, param2, param3};
    for (int i = 0; i < 3; i++)
    {
        if (params[i] != NULL)
        {
            paramCount++;
        }
    }
    return paramCount;
}

int is_first_operand_null(InstructionType_t *instructionId, char *param1, uint64_t *lineNumber)
{
    // Check if first operand is null
    if (param1 != NULL)
    {
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction does not accept first operand on line: %" PRIu64 "\n", opcode, *lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_second_operand_null(InstructionType_t *instructionId, char *param2, uint64_t *lineNumber)
{
    // Check if second operand is null
    if (param2 == NULL)
    {
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction is missing second parameter on line: %" PRIu64 "\n", opcode, *lineNumber);
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
        printf("Error: %s instruction does not accept third operand on line: %" PRIu64 "\n", opcode, *lineNumber);
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
        printf("Error: %s instruction requires first operand on line: %" PRIu64 "\n", opcode, *lineNumber);
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
        printf("Error: %s instruction requires second operand on line: %" PRIu64 "\n", opcode, *lineNumber);
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
        printf("Error: %s instruction requires third operand on line: %" PRIu64 "\n", opcode, *lineNumber);
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

    if (strcmp(param1, "sp") == 0 || strcmp(param1, "ip") == 0)
    {
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction first parameter is a read-only register (ip/sp) on line: %" PRIu64 "\n", opcode, *lineNumber);
        return INVALID_DATA;
    }

    if (find_register(param1, &paramVerificationReturn) != SUCCESS)
    {

        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction first parameter is not an existing register on line: %" PRIu64 "\n", opcode, *lineNumber);
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
        printf("Error: %s instruction second parameter is not an existing register on line: %" PRIu64 "\n", opcode, *lineNumber);
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
        printf("Error: %s instruction third parameter is not an existing register on line: %" PRIu64 "RIu64\n", opcode, *lineNumber);
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
        printf("Error: %s instruction first parameter is not an immediate on line: %" PRIu64 "\n", opcode, *lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_immediate_or_label(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber)
{
    char opcode[4];

    if (is_first_operand_not_null(instructionId, param1, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    uint8_t *paramVerificationReturn;
    if(find_register(param1, paramVerificationReturn) == SUCCESS){
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction first parameter is nor an immediate or label on line: %" PRIu64 "\n", opcode, *lineNumber);
        return INVALID_DATA;
    }

    if (check_is_number(param1) != SUCCESS && check_is_label(param1) != SUCCESS)
    {
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction first parameter is nor an immediate or label on line: %" PRIu64 "\n", opcode, *lineNumber);
        return INVALID_DATA;
    }

    if (param2 != NULL)
    {
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction has been provided too much arguments on line: %" PRIu64 "\n", opcode, *lineNumber);
        return INVALID_DATA;
    }

    if (param3 != NULL)
    {
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction has been provided too much arguments on line: %" PRIu64 "\n", opcode, *lineNumber);
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
        printf("Error: %s instruction second parameter is not an immediate on line: %" PRIu64 "\n", opcode, *lineNumber);
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
        printf("Error: %s instruction third parameter is not an immediate on line: %" PRIu64 "\n", opcode, *lineNumber);
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
        printf("Error: %s instruction second parameter is not a label on line: %" PRIu64 "\n", opcode, *lineNumber);
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
        printf("Error: %s instruction first parameter is nor an immediate or register on line: %" PRIu64 "\n", opcode, *lineNumber);
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
        printf("Error: %s instruction second parameter is nor an immediate or register on line: %" PRIu64 "\n", opcode, *lineNumber);
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
        printf("Error: %s instruction third parameter is nor an immediate or register on line: %" PRIu64 "\n", opcode, *lineNumber);
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

int is_first_operand_register_or_first_and_second_operand_registers(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber)
{

    if (is_third_operand_null(instructionId, param3, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    if (is_first_operand_register(instructionId, param1, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    uint8_t registerPlaceholder;
    if (param2 != NULL)
    {
        if (find_register(param2, &registerPlaceholder) != SUCCESS)
        {
            return INVALID_DATA;
        }
    }

    return SUCCESS;
}

int is_first_operand_register_and_second_operand_immediate(InstructionType_t *instructionId, char *param1, char *param2, uint64_t *lineNumber)
{
    if (is_first_operand_register(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_immediate(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_register_and_second_operand_immediate_or_are_two_first_operands_registers_and_third_immediate(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber, uint8_t paramsNumber)
{
    if (paramsNumber == 2)
    {
        if (is_first_operand_register_and_second_operand_immediate(instructionId, param1, param2, lineNumber) != SUCCESS)
        {
            return INVALID_DATA;
        }
        return SUCCESS;
    }
    else if (paramsNumber == 3)
    {
        if (are_two_first_operand_registers(instructionId, param1, param2, lineNumber) != SUCCESS || is_third_operand_immediate(instructionId, param3, lineNumber) != SUCCESS)
        {
            return INVALID_DATA;
        }
        return SUCCESS;
    }
    else
    {
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        if (paramsNumber < 2)
        {
            printf("Error: %s instruction is missing at least one parameter on line: %" PRIu64 "\n", opcode, *lineNumber);
        }
        else if (paramsNumber > 3)
        {
            printf("Error: %s instruction has been provided too much arguments on line: %" PRIu64 "\n", opcode, *lineNumber);
        }
        return GENERIC_ERROR;
    }
}

int are_two_first_operand_registers(InstructionType_t *instructionId, char *param1, char *param2, uint64_t *lineNumber)
{
    if (is_first_operand_register(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_register(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int are_two_first_operand_registers_and_third_immediate(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber)
{
    if (are_two_first_operand_registers(instructionId, param1, param2, lineNumber) != SUCCESS || is_third_operand_immediate(instructionId, param3, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int are_first_two_operands_register_and_third_register_or_immediate(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber)
{
    if (is_first_operand_register(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_register(instructionId, param2, lineNumber) != SUCCESS || is_third_operand_immediate_or_register(instructionId, param3, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int are_two_first_operand_registers_or_are_all_operands_registers(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber, uint8_t paramsNumber)
{
    if (paramsNumber == 2)
    {
        if (are_two_first_operand_registers(instructionId, param1, param2, lineNumber) != SUCCESS)
        {
            return GENERIC_ERROR;
        }
        return SUCCESS;
    }
    else if (paramsNumber == 3)
    {
        if (are_all_operand_registers(instructionId, param1, param2, param3, lineNumber) != SUCCESS)
        {
            return GENERIC_ERROR;
        }
        return SUCCESS;
    }
    else
    {
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        if (paramsNumber < 2)
        {
            printf("Error: %s instruction is missing at least one parameter on line: %" PRIu64 "\n", opcode, *lineNumber);
        }
        else if (paramsNumber > 3)
        {
            printf("Error: %s instruction has been provided too much arguments on line: %" PRIu64 "\n", opcode, *lineNumber);
        }
        return GENERIC_ERROR;
    }
}

int is_first_operand_register_and_second_operand_register_or_immediate(InstructionType_t *instructionId, char *param1, char *param2, uint64_t *lineNumber)
{
    if (is_first_operand_register(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_immediate_or_register(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_second_operand_immediate_or_label(InstructionType_t *instructionId, char *param2, uint64_t *lineNumber)
{
    if (check_is_label(param2) != SUCCESS && check_is_number(param2) != SUCCESS)
    {
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction second parameter is not an immediate or label on line: %" PRIu64 "\n", opcode, *lineNumber);
        return INVALID_DATA;
    }
    return SUCCESS;
}

int is_first_operand_register_and_second_operand_immediate_or_label(InstructionType_t *instructionId, char *param1, char *param2, uint64_t *lineNumber)
{
    if (is_first_operand_not_null(instructionId, param1, lineNumber) != SUCCESS || is_second_operand_null(instructionId, param2, lineNumber) != SUCCESS)
    {
        return INVALID_DATA;
    }

    if (is_first_operand_register(instructionId, param1, lineNumber) != SUCCESS)
    {
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction first parameter is not a register on line: %" PRIu64 "\n", opcode, *lineNumber);
        return INVALID_DATA;
    }

    if (is_second_operand_immediate_or_label(instructionId, param2, lineNumber) != SUCCESS)
    {
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        printf("Error: %s instruction second parameter is not an immediate or label on line: %" PRIu64 "\n", opcode, *lineNumber);
        return INVALID_DATA;
    }

    return SUCCESS;
}

int is_first_operand_register_or_is_first_operand_register_and_second_operand_immediate_or_label(InstructionType_t *instructionId, char *param1, char *param2, uint64_t *lineNumber, uint8_t paramsNumber)
{
    if (paramsNumber == 1)
    {
        if (is_first_operand_register(instructionId, param1, lineNumber) != SUCCESS)
        {
            return GENERIC_ERROR;
        }
        return SUCCESS;
    }
    else if (paramsNumber == 2)
    {
        if (is_first_operand_register_and_second_operand_immediate_or_label(instructionId, param1, param2, lineNumber) != SUCCESS)
        {
            return GENERIC_ERROR;
        }
        return SUCCESS;
    }
    else
    {
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        if (paramsNumber < 1)
        {
            printf("Error: %s instruction is missing at least one parameter on line: %" PRIu64 "\n", opcode, *lineNumber);
        }
        else if (paramsNumber > 2)
        {
            printf("Error: %s instruction has been provided too much arguments on line: %" PRIu64 "\n", opcode, *lineNumber);
        }
        return GENERIC_ERROR;
    }
}

int are_first_two_operands_register_and_third_register_or_immediate_or_is_first_operand_register_and_second_operand_register_or_immediate(InstructionType_t *instructionId, char *param1, char *param2, char *param3, uint64_t *lineNumber, uint8_t paramsNumber) // Add number of params
{
    if (paramsNumber == 2)
    {
        if (is_first_operand_register_and_second_operand_register_or_immediate(instructionId, param1, param2, lineNumber) != SUCCESS)
        {
            return GENERIC_ERROR;
        }
        return SUCCESS;
    }
    else if (paramsNumber == 3)
    {
        if (are_first_two_operands_register_and_third_register_or_immediate(instructionId, param1, param2, param3, lineNumber) != SUCCESS)
        {
            return GENERIC_ERROR;
        }
        return SUCCESS;
    }
    else
    {
        char opcode[4];
        get_operand_name(*instructionId, opcode);
        if (paramsNumber < 2)
        {
            printf("Error: %s instruction is missing at least one parameter on line: %" PRIu64 "\n", opcode, *lineNumber);
        }
        else if (paramsNumber > 3)
        {
            printf("Error: %s instruction has been provided too much arguments on line: %" PRIu64 "\n", opcode, *lineNumber);
        }
        return GENERIC_ERROR;
    }
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
    case ABS:
        strcpy(output, "abs");
        break;
    case ADD:
        strcpy(output, "add");
        break;
    case ADDI:
        strcpy(output, "addi");
        break;
    case AND:
        strcpy(output, "and");
        break;
    case ANDI:
        strcpy(output, "andi");
        break;
    case B:
        strcpy(output, "b");
        break;
    case BI:
        strcpy(output, "bi");
        break;
    case BNZ:
        strcpy(output, "bnz");
        break;
    case BZ:
        strcpy(output, "bz");
        break;
    case CALL:
        strcpy(output, "call");
        break;
    case CALLI:
        strcpy(output, "calli");
        break;
    case DIV:
        strcpy(output, "div");
        break;
    case JMP:
        strcpy(output, "jmp");
        break;
    case LD:
        strcpy(output, "ld");
        break;
    case LDI:
        strcpy(output, "ldi");
        break;
    case LDP:
        strcpy(output, "ldp");
        break;
    case MUL:
        strcpy(output, "mul");
        break;
    case OR:
        strcpy(output, "or");
        break;
    case ORI:
        strcpy(output, "ori");
        break;
    case POP:
        strcpy(output, "pop");
        break;
    case PUSH:
        strcpy(output, "push");
        break;
    case RET:
        strcpy(output, "ret");
        break;
    case SET:
        strcpy(output, "set");
        break;
    case STR:
        strcpy(output, "str");
        break;
    case STRI:
        strcpy(output, "stri");
        break;
    case STRP:
        strcpy(output, "strp");
        break;
    case SUB:
        strcpy(output, "sub");
        break;
    case SUBI:
        strcpy(output, "subi");
        break;
    case TEQ:
        strcpy(output, "teq");
        break;
    case TEQI:
        strcpy(output, "teqi");
        break;
    case TGE:
        strcpy(output, "tge");
        break;
    case TGEI:
        strcpy(output, "tgei");
        break;
    case TGT:
        strcpy(output, "tgt");
        break;
    case TGTI:
        strcpy(output, "tgti");
        break;
    case TLE:
        strcpy(output, "tle");
        break;
    case TLEI:
        strcpy(output, "tlei");
        break;
    case TLT:
        strcpy(output, "tlt");
        break;
    case TLTI:
        strcpy(output, "tlti");
        break;
    case TNE:
        strcpy(output, "tne");
        break;
    case TNEI:
        strcpy(output, "tnei");
        break;
    case XCHG:
        strcpy(output, "xchg");
        break;
    case XOR:
        strcpy(output, "xor");
        break;
    case XORI:
        strcpy(output, "xori");
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
    else if (strcmp("abs", input) == 0)
    {
        *instruction = ABS;
    }
    else if (strcmp("add", input) == 0)
    {
        *instruction = ADD;
    }
    else if (strcmp("addi", input) == 0)
    {
        *instruction = ADDI;
    }
    else if (strcmp("and", input) == 0)
    {
        *instruction = AND;
    }
    else if (strcmp("andi", input) == 0)
    {
        *instruction = ANDI;
    }
    else if (strcmp("b", input) == 0)
    {
        *instruction = B;
    }
    else if (strcmp("bi", input) == 0)
    {
        *instruction = BI;
    }
    else if (strcmp("bnz", input) == 0)
    {
        *instruction = BNZ;
    }
    else if (strcmp("bz", input) == 0)
    {
        *instruction = BZ;
    }
    else if (strcmp("call", input) == 0)
    {
        *instruction = CALL;
    }
    else if (strcmp("calli", input) == 0)
    {
        *instruction = CALLI;
    }
    else if (strcmp("div", input) == 0)
    {
        *instruction = DIV;
    }
    else if (strcmp("jmp", input) == 0)
    {
        *instruction = JMP;
    }
    else if (strcmp("ld", input) == 0)
    {
        *instruction = LD;
    }
    else if (strcmp("ldi", input) == 0)
    {
        *instruction = LDI;
    }
    else if (strcmp("ldp", input) == 0)
    {
        *instruction = LDP;
    }
    else if (strcmp("mul", input) == 0)
    {
        *instruction = MUL;
    }
    else if (strcmp("or", input) == 0)
    {
        *instruction = OR;
    }
    else if (strcmp("ori", input) == 0)
    {
        *instruction = ORI;
    }
    else if (strcmp("pop", input) == 0)
    {
        *instruction = POP;
    }
    else if (strcmp("push", input) == 0)
    {
        *instruction = PUSH;
    }
    else if (strcmp("ret", input) == 0)
    {
        *instruction = RET;
    }
    else if (strcmp("set", input) == 0)
    {
        *instruction = SET;
    }
    else if (strcmp("str", input) == 0)
    {
        *instruction = STR;
    }
    else if (strcmp("stri", input) == 0)
    {
        *instruction = STRI;
    }
    else if (strcmp("strp", input) == 0)
    {
        *instruction = STRP;
    }
    else if (strcmp("sub", input) == 0)
    {
        *instruction = SUB;
    }
    else if (strcmp("subi", input) == 0)
    {
        *instruction = SUBI;
    }
    else if (strcmp("teq", input) == 0)
    {
        *instruction = TEQ;
    }
    else if (strcmp("teqi", input) == 0)
    {
        *instruction = TEQI;
    }
    else if (strcmp("tge", input) == 0)
    {
        *instruction = TGE;
    }
    else if (strcmp("tgei", input) == 0)
    {
        *instruction = TGEI;
    }
    else if (strcmp("tgt", input) == 0)
    {
        *instruction = TGT;
    }
    else if (strcmp("tgti", input) == 0)
    {
        *instruction = TGTI;
    }
    else if (strcmp("tle", input) == 0)
    {
        *instruction = TLE;
    }
    else if (strcmp("tlei", input) == 0)
    {
        *instruction = TLEI;
    }
    else if (strcmp("tlt", input) == 0)
    {
        *instruction = TLT;
    }
    else if (strcmp("tlti", input) == 0)
    {
        *instruction = TLTI;
    }
    else if (strcmp("tne", input) == 0)
    {
        *instruction = TNE;
    }
    else if (strcmp("tnei", input) == 0)
    {
        *instruction = TNEI;
    }
    else if (strcmp("xchg", input) == 0)
    {
        *instruction = XCHG;
    }
    else if (strcmp("xor", input) == 0)
    {
        *instruction = XOR;
    }
    else if (strcmp("xori", input) == 0)
    {
        *instruction = XORI;
    }
    else
    {
        return GENERIC_ERROR;
    }
    return SUCCESS;
};

// ************************** END TRANSLATION OPCODE - INSTRUCTION CODE DEFINITIONS **************************
#endif