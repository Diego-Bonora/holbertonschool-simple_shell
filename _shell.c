#include "main.h"

/***/

int main(void)
{
    int status = 1, free_ = 0;
    ssize_t _exit_ = 0;
    token_t *args_token, *path_token;
    char *line = NULL, *path = NULL, **array = NULL;

    while (status)
    {
        line = Read_line(&_exit_);
        if (_exit_ == -1)
            return (0);
        args_token = tokenicer(line, " \t\r\n\a");
        path = _getenv("PATH");
        path_token = tokenicer(path, ":");
        args_token = _stat_checker(args_token, path_token);
        array = _list_to_array(args_token);
        if (strcmp(array[0], "exit") == 0 && array[1] == NULL)
        {
            free(array[0]);
            free(array);
            free(path);
            free(line);
            return (0);
        }
        status = _exeCute(array);
        while(array[free_])
        {
            free(array[free_]);
            free_++;
        }
        free(array);
        free(path);
        free(line);
    }
    return (0);
}

char *Read_line(ssize_t *_exit_)
{
    char *str = NULL;
    size_t size;

    printf("DEPS -> ");
    str = malloc(sizeof(char) * 64);
    *_exit_ = getline(&str, &size, stdin);
    return(str);
}