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
#endif