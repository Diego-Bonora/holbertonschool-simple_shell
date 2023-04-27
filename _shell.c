#include "main.h"

/**
 * main - execute a simple shell
 * @argc: a count of argumentos on argv
 * @argv: vector of arguments given to shell
 * Return: 0 on success and stat on exit
*/

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{	int count = 1, status = 1, free_;
	ssize_t _exit_ = 0;
	token_t *args_token = NULL, *path_token = NULL, *command = NULL;
	char *line = NULL, *path = NULL, **array = NULL;

	(void)free_;
	while (status)
	{	free_ = 0;
		line = Read_line(&_exit_);
		args_token = tokenicer(line, " \t\r\n\a");
		if (!args_token)
		{	free(line);
			continue; }
		path = _getenv("PATH");
		path_token = tokenicer(path, ":");
		if (!path_token)
		{	free_list(args_token);
			free(line);
			continue; }
		command = _stat_checker(args_token, path_token, line, count);
		if (!command)
		{	_exit_ = 1;
			count++;
			puts("aa");
			continue; }
		else
			_exit_ = 0;
		puts("a");
		array = _list_to_array(args_token);
		status = _exeCute(array);
		count++;
		free(line); }
	return (0); }

/**
 * Read_line - prints a prompt and read user input
 * @_exit_: a count of argumentos on argv
 * Return: 0 on success and stat on exit
*/

char *Read_line(ssize_t *_exit_)
{
	int num = 0;
	char *str = NULL;
	size_t size = 0;
	int fd = isatty(num);

	if (fd == 1)
		printf("DEPS -> ");
	
	if (getline(&str, &size, stdin) == -1)
	{
		free(str);
		if (*_exit_ == 0)
			exit(0);
		exit(127);
	}
	else if (strcmp(str, "exit\n") == 0)
	{
		free(str);
		if (*_exit_ == 0)
			exit(0);
		exit(127);
	}
	return (str);
}
