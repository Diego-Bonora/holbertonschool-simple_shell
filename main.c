#include "main.h"

/**
 *
 */

int main(int argc, char *argv[])
{
	char *algo, **args;
	size_t size = 64;
	int status = 1;

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

#define DELIMIT " \t\r\n\a"
char **split(char *line)
{
	char *list;
	token_t *args;
	int count = 0;

	args = malloc(sizeof(token_t));
	if (!args)
		return (NULL);
	args = NULL;
	list = strtok(line, DELIMIT);
	while (list != NULL)
	{
		add_node_end(&args, list);
		count++;
		list = strtok(NULL, DELIMIT);
	}
	return (convert(&args));
}

char **convert(token_t **args)
{
	char **list;
	token_t *temp;
	int count = 0, sum = 0;
	
	temp = *args;
	while (temp)
	{
		sum += temp->len;
		temp = temp->next;
	}
	list = malloc(sum * sizeof(char) + 1);
	temp = *args;
	while (*args)
	{
		*args = (*args)->next;
		list[count] = strdup(temp->token);
		free(temp->token);
		free(temp);
		temp = temp->next;
		count++;
	}
	list[count] = NULL;
	return (list);
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
