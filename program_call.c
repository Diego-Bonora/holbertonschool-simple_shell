#include "main.h"

/**
*/

int execute(char **args)
{
	pid_t pid;
	int status, count = 0;
    char **array, *concat = NULL;
    struct stat *buff;

    buff = malloc(sizeof(struct stat));

	if (args[0] == NULL)
		return (-1);

    array = _PATH();
    
	pid = fork();
	if (pid == 0)
	{
        while (array[count])
        {
            concat = strdup(array[count]);
            strcat(concat, "/");
            strcat(concat, args[0]);
            if (stat(concat, buff) == 0)
            {
                if (execve(concat, args, environ) == -1)
	    	        perror("Error");
                break;
            }
            count++;
        }
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Error");
	}
	else
	{
		wait(&status);
	}
    free(buff);
    free(concat);
    free(array);
    return (1);
}