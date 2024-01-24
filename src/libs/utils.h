#ifndef UTILS_H
#define UTILS_H

typedef enum ErrorType //Define all the errors which could happen and their codes
{
    SUCCESS,
    GENERIC_ERROR,
    FILE_NOT_FOUND,
    CANNOT_ACCESS_FILE,
    INVALID_DATA,
    OUT_OF_MEMORY,
} errorType_t;

typedef enum ParameterType //Define type of parameters in a function
{
    IMMEDIAT,
    REGISTER,
    LABEL,
    NULL_,
} ParameterType_t;

int checkIsNumber(char* str){
    int i = 0;
    while (str[i] != '\0')
    {
        if(!(str[i] >= '0' && str[i] <= '9'))
        {
            return INVALID_DATA;
        }
        i++;
    }
    return SUCCESS;
}

int checkIsLabel(char* str){
    if(!(str[0] >= 'A' && str[0] <= 'F') || !(str[0] >= 'a' && str[0] <= 'f'))
    {
        return INVALID_DATA;
    }
    int i = 1;
    while (str[i] != '\0')
    {
        if(!(str[i] >= '0' && str[i] <= '9') || !(str[i] >= 'A' && str[i] <= 'F') || !(str[i] >= 'a' && str[i] <= 'f'))
        {
            return INVALID_DATA;
        }
        i++;
    } 
    return SUCCESS;
}


#endif