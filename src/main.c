#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum ErrorType
{
    SUCCESS,
    GENERIC_ERROR,
    FILE_NOT_FOUND,
    CANNOT_ACCESS_FILE,
    INVALID_DATA,
    OUT_OF_MEMORY,
} errorType_t;

enum instructionType
{
    mov,
    jmp,
    call
}; // etc...

typedef struct operation
{
    enum instructionType instT;
    int reg1;
    int reg2;
    int line;
} operation_t;

int parse_content(const char *content)
{
    char str1[5], str2[10], str3[10];
    int offset = 0, read;
    while (sscanf(content + offset, "%s %s %s%n", str1, str2, str3, &read) == 3)
    {
        printf("%s\n%s\n%s\n", str1, str2, str3);
        offset += read;
    }
    return SUCCESS;
}

int read_file(char *filename, char *output, int size)
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
        output[count] = ch;
        count++;
    }

    output[count - 1] = '\0';

    fclose(ptr);
    return SUCCESS;
}

int get_file_size(char *filename, int *size)
{
    FILE *fp;

    *size = 0;
    char c;

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Could not open file: %s\n\n",
               filename);
        return FILE_NOT_FOUND;;
    }

    for (c = getc(fp); c != EOF; c = getc(fp))
        *size += 1;

    fclose(fp);

    return SUCCESS;
}

int main()
{
    while (true)
    {
        char filename[100]; // File name in input
        scanf("%s", filename);
        strlwr(filename); // convert to lowercase
        if (strcmp(&filename[strlen(filename) - 4], ".asm") != 0)
        {
            strcat(filename, ".asm");
        }
        int i = 0;
        if (get_file_size(filename, &i) != 0)
        {
            continue; // Go back to the beginning of the loop
        }
        else
        {
            char *content;
            content = (char *)malloc(i * sizeof(char));
            read_file(filename, content, i);
            parse_content(content);
            free(content);
        }
    }
    return SUCCESS;
}