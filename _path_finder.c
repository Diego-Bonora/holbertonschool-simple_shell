#include "main.h"

/**
 * _getenv - takes environ var search and extract path as a string
 * @str: string to search into environ var, "PATH" int this case
 * Return: a string with the path
*/

char *_getenv(char *str)
{
	char *string = NULL;
	int count = 0;

	while (environ[count])
	{
		if (strstr(environ[count], str))
		{
			string = malloc(strlen(environ[count]));
			strcpy(string, environ[count]);
			break;
		}
		count++;
	}
	string = strtok(string, "PATH=");
	return (string);
}
