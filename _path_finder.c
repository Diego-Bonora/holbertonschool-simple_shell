#include "main.h"

/***/

char *_getenv(char *str)
{
    char *string = NULL, *returnable = NULL;
    int count = 0, fix = 0;

    while (environ[count])
    {
        if (strstr(environ[count], str))
        {
            string = strdup(environ[count]);
            break;
        }
        count++;
    }
    
    returnable = malloc(sizeof(char) * strlen(string) - 5);

    count = 5;
    if (string)
    {
        while (string[count])
        {
            returnable[fix] = string[count];
            fix++;
            count++;
        }
        string = returnable;
    }
    return (string);
}