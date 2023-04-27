#include "main.h"

/**
 * _getenv - takes environ var search and extract path as a string
 * @str: string to search into environ var, "PATH" int this case
 * Return: a string with the path
*/

token_t *_getenv(char *str)
{
	char *string = NULL, *string_r = NULL;
	int count = 0;
	token_t *path;

	while (environ[count])
	{
		if (strstr(environ[count], str))
		{
			string = strdup(environ[count]);
			break;
		}
		count++;
	}
	string_r = strtok(string, "PATH=");
	path = tokenicer(string_r, ":");
	free(string);
	return (path);
}
