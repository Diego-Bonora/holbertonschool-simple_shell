#include "main.h"

/***/

int main(void)
{
    int count = 0, status = 1;
    token_t *test, *path_token;
    char *line = NULL, *path = NULL, **array = NULL;

    while (status)
    {
        line = Read_line();
        test = tokenicer(line, " \t\r\n\a");
        path = _getenv("PATH");
        path_token = tokenicer(path, ":");
        test = _stat_checker(test, path_token);
        free(path_token);
        array = convert(test);
        while (array[count])
        {
            printf("%s\n", array[count]);
            count++;
        }
    }
}

char *Read_line(void)
{
    char *str = NULL;
    size_t size;
    
    str = malloc(sizeof(char) * 64);
    getline(&str, &size, stdin);
    return(str);
}