#ifndef INTERPRETER_H
#define INTERPRETER_H

int find_register(char *inString, uint8_t *registerIndex)
{
    if (inString == NULL || strlen(inString) != 2)
    {
        return INVALID_DATA;
    }

    if (inString[0] != 'R' && inString[0] != 'r')
    {
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

#endif