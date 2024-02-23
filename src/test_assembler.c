#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "./libs/utils.h"
#include "./libs/preprocessor.h"
#include "./libs/assembler.h"

void test_iterate_through_all_line();
void test_get_file_size();
void test_read_file();

int main(){
    test_iterate_through_all_line();
    test_get_file_size();
    test_read_file();

    return 0;
}

void test_iterate_through_all_line(){
    line_t l1 = {
        .lineNumber = 0,
        .dest_t = REGISTER,
        .dest = 4,
        .mnemonic = ADD,
        .param1_t = REGISTER,
        .register1 = 5,
        .param2_t = NULL_,
        .register2 = 31,
    };
    line_t l2 = {
        .lineNumber = 1,
        .dest_t = REGISTER,
        .dest = 4,
        .mnemonic = ADDI,
        .param1_t = REGISTER,
        .register1 = 12,
        .param2_t = IMMEDIATE,
        .immediate2 = 233,

    };
    line_t l3 = {
        .lineNumber = 2,
        .mnemonic = LABEL_,
        .labelDef = "test",
    };
    line_t l4 = {
        .lineNumber = 3,
        .dest_t = REGISTER,
        .dest = 4,
        .mnemonic = DIV,
        .param1_t = REGISTER,
        .register1 = 12,
        .param2_t = REGISTER,
        .register2 = 2,

    };
    line_t l5 = {
        .lineNumber = 4,
        .mnemonic = JMP,
        .dest_t = IMMEDIATE,
        .immediateDest = 2,
        .param1_t = NULL_,
        .param2_t = NULL_,
    };
    line_t l6 = {
        .lineNumber = 5,
        .dest_t = LABEL,
        .labelCall = "test",
        .mnemonic = BI,
        .param1_t = NULL_,
        .param2_t = NULL_,
    };

    line_t arrOfLine[] = {l1, l2, l3, l4, l5, l6}; 

    bool error = false;

    if(iterate_through_all_line(arrOfLine, 6, "test.bin") != SUCCESS){
        error = true;
        printf("test_iterate_through_all_line: Error in assembling\n");
        return;
    }

    uint8_t byteArr[] = {
        0x00, 0x00, 0x14, 0x84,
        0x40, 0x03, 0xa5, 0x84,
        0x06, 0x00, 0x09, 0x84,
        0xf0, 0x00, 0x00, 0xa0,
        0x9f, 0xff, 0xff, 0xc0,};

    FILE* file = fopen("test.bin", "rb");
    if (file == NULL) {
        perror("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    unsigned char byte;
    int i = 0;
    while (fread(&byte, sizeof(byte), 1, file) == 1) {
        if(byteArr[i] != byte){
            error = true;
            printf("test_iterate_through_all_line: expected %d got %d\n", byteArr[i], byte);
        }
        i++;
    }

    if (!feof(file)) {
        perror("Error reading file\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    fclose(file);

    if(!error){
        printf("test_iterate_through_all_line: Succesful\n");
    };
}

void test_get_file_size(){

    FILE *file = fopen("test.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    char* text = "ailuzgbabviulbagoaugeriipabuegergpaiuhgbuiavrbavuoabv";
    fprintf(file, "%s", text);
    int expected = strlen(text);
    fclose(file);

    uint64_t charCount;
    get_file_size("test.txt", &charCount);

    if(charCount != expected){
        printf("test_get_file_size: expected %d got %d\n", expected, charCount);
    }else{
        printf("test_get_file_size: Succesful\n");
    }
    return;
}

void test_read_file(){
    bool error = false;

    FILE *file = fopen("test.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    char* text = "ailuzgbabviulbagoaugeri\nipabuegergpaiu\nhgbuiavrbavuoabv\n\0";
    fprintf(file, "%s", text);
    int expected = 3;
    fclose(file);

    uint64_t charCount = strlen(text);
    char *content = malloc((charCount + 1) * sizeof(char));

    uint64_t lineCount = 0;
    read_file("test.txt", content, charCount, &lineCount);

    if(lineCount != expected){
        printf("test_read_file: expected %d got %u\n", expected, lineCount);
        error = true;
    }

    if(strcmp(content, text) != 0){
        printf("test_read_file: expected %s got %s\n", text, content);
        error = true;
    }
    
    if(!error){
        printf("test_read_file: Succesful\n");
    }
    return;
};