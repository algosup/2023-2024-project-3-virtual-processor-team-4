#include <stdio.h>
#include <stdlib.h>

int ReadFile(char* filename, char* output, int size){
    FILE* ptr;
    char ch;
 
    ptr = fopen(filename, "r");
 
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
    
    int count = 0;

    do {
        ch = fgetc(ptr);
        output[count] = ch;
        count++;
    } while (ch != EOF);

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

int main(){
    int i = 0;
    get_file_size("example.asm", &i);

    char *content;
    content = (char *)malloc(i * sizeof(char));

    ReadFile("example.asm", content, i);

    printf("%s", content);


    return 0;
}