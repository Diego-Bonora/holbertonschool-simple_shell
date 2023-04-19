#include "main.h"

/**
 *
 */

int main(int argc, char *argv[])
{
	char *algo, **args;
	size_t size = 64;
	int status;

	(void)argv;
	(void)argc;
	algo = malloc(sizeof(char) * size);
	if (!algo)
		return (-1);
	while (status)
	{
		printf("$ ");
		if (getline(&algo, &size, stdin) == -1)
			return (0);
		args = split(algo);
		status = execute(args);

		free(algo);
		free(args);
		memset(algo, 0, size);
	}
	return (0);
}

#define BUFF_TOKEN 64
#define DELIMIT " \t\r\n\a"
char **split(char *line)
{
	char *list;
	char **args;
	int count = 0, buff = BUFF_TOKEN;

	args = malloc(sizeof(char) * buff);
	if (!args)
		return (NULL);
	list = strtok(line, DELIMIT);
	while (list != NULL)
	{
		args[count] = list;
		count++;
		list = strtok(NULL, DELIMIT);
	}
	args[count] = NULL;
	return (args);
}

int execute(char **args)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
		return (-1);

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
			perror("Error");
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
	return (1);
}
