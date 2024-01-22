#include <stdio.h>
#include <stdlib.h>

int parse_content(const char *content)
{
    char str1[5], str2[10], str3[10];
    int offset = 0, read;
    while (sscanf(content + offset, "%s %s %s%n", str1, str2, str3, &read) == 3)
    {
        printf("%s\n%s\n%s\n", str1, str2, str3);
        offset += read;
    }
    return 0;
}

int read_file(char *filename, char *output, int size)
{
    FILE *ptr;
    char ch;
    ptr = fopen(filename, "r");

    if (NULL == ptr)
    {
        printf("file can't be opened \n");
        return 1;
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
    return 0;
}

int get_file_size(char *filename, int *size)
{
    FILE *fp;

    *size = 0;
    char c;

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Could not open file %s",
               filename);
        return 0;
    }

    for (c = getc(fp); c != EOF; c = getc(fp))
        *size += 1;

    fclose(fp);

    return 0;
}

int main()
{
    int i = 0;
    get_file_size("example.asm", &i);

    char *content;
    content = (char *)malloc(i * sizeof(char));

    read_file("example.asm", content, i);

    // printf("%s", content);

    parse_content(content);

    return 0;
}