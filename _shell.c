#include "main.h"

/**
 * main - execute a simple shell
 * @argc: a count of argumentos on argv
 * @argv: vector of arguments given to shell
 * 
 * Return - 0 on success and stat on exit
*/

int main(__attribute__((unused)) int argc, char *argv[])
{	int count = 1, status = 1, free_;
	ssize_t _exit_ = 0;
	token_t *args_token, *path_token, *command = NULL;
	char *line = NULL, *path = NULL, **array = NULL;

	while (status)
	{	free_ = 0;
		line = Read_line(&_exit_);
		args_token = tokenicer(line, " \t\r\n\a");
		if (!args_token)
		{	free(line);
			continue; }
		if (strcmp(args_token->token, "exit") == 0 && args_token->next == NULL)
		{	free_list(args_token);
			free(line);
			if (_exit_ == 0)
				exit(0);
			exit(127); }
		path = _getenv("PATH");
		path_token = tokenicer(path, ":");
		if (!path_token)
		{	free_list(args_token);
			free(line);
			continue; }
		command = _stat_checker(args_token, path_token);
		array = _list_to_array(args_token);
		if (!command)
		{	fprintf(stderr, "%s: %d: %s: not Found\n", argv[0], count, line);
			free(line);
			_exit_ = 1;
			count++;
			continue; }
		else
			_exit_ = 0;
		status = _exeCute(array);
		while (array[free_])
		{	free(array[free_]);
			free_++; }
		count++;
		free(path);
		free(line); }
	return (0); }

char *Read_line(ssize_t *_exit_)
{
	int num = 0;
	char *str = NULL, *line = NULL;
	size_t size = 0;

	printf("DEPS -> ");
	num = getline(&str, &size, stdin);
	if (num != -1)
	{
		line = malloc(sizeof(char) * num);
		strcpy(line, str);
		free(str);
	}
	else
	{
		free(str);
		if (*_exit_ == 0)
			exit(0);
		exit(127);
	}
	return (line);
}
