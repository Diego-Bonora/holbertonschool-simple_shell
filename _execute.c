#include "main.h"

/***/

int _exeCute(char **args)
{
    pid_t pid = 0;
    int status = 0;
    struct stat *buff;

    buff = malloc(sizeof(struct stat));
    pid = fork();
    if (pid == 0)
    {
        if (stat(args[0], buff) == 0)
        {
            if (execve(args[0], args, environ) == -1)
            {
                perror("Command invalid");
                exit(EXIT_FAILURE);
            }
        }
        else if(strcmp(args[0], "env") == 0 && args[1] == NULL)
        {
            _env();
        }
        else
        {
            perror("ERROR");
            exit(EXIT_FAILURE);
        }
    }
    else if (pid < 0)
    {
        perror("Failed to fork");
    } 
    else
    {
        wait(&status);
    }
    free(buff);
    return (1);
}