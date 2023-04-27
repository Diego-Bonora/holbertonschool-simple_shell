#include "main.h"

/**
 * _getenv - takes environ var search and extract path as a string
 * @str: string to search into environ var, "PATH" int this case
 * Return: a string with the path
*/

token_t *_getenv(char *str)
{
	char *string = NULL, *string_r = NULL;
	int count = 0, count2 = 0;
	unsigned long int flag = 0;
	token_t *path;

	while (environ[count])
	{
		flag = 0;
		count2 = 0;
		while (str[count2])
		{
			if (environ[count][count2] != str[count2])
				break;
			flag++;
			count2++;
			if (flag == strlen(str))
			{
				string = strdup(environ[count]);
				break;
			}
		}
		count++;
	}
	string_r = strtok(string, "PATH=");
	if (!string_r)
	{
		free(string);
		return (NULL);
	}
	path = tokenicer(string_r, ":");
	free(string);
	return (path);
}
