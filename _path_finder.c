#include "main.h"

/**
 * _getenv - takes environ var search and extract path as a string
 * @str: string to search into environ var, "PATH" int this case
 * Return: a string with the path
*/

char *_getenv(char *str)
{
	char *string = NULL, *string_r = NULL;
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

	string_r = malloc(sizeof(char) * strlen(string) - 5);

	count = 5;
	if (string)
	{
		while (string[count])
		{
			string_r[fix] = string[count];
			fix++;
			count++;
		}
		string = strdup(string_r);
	}
	free(string_r);
	return (string);
}
