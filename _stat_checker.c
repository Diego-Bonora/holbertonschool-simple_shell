#include "main.h"

/**
 * _stat_checker - pruves a command on different paths
 * @head: linked list with command and arguments
 * @path: a tring with the path route
 * @line: input line for sending an error
 * @count: count for printing an error
 * Return: a valid string with the full path to execute
*/

token_t *_stat_checker(token_t *head, token_t *path, char *line, int count)
{
	token_t *temp;
	struct stat *buff;
	char *new_str = NULL, *compare_str = NULL;

	buff = malloc(sizeof(struct stat));
	temp = path;
	if (stat(head->token, buff) == 0)
	{
		free_list(path);
		free(buff);
		return (head);
	}
	while (temp)
	{
		new_str = _concat(temp->token, "/");
		compare_str = _concat(new_str, head->token);
		if (stat(compare_str, buff) == 0)
		{
			free(head->token);
			head->token = strdup(compare_str);
			free_list(path);
			free(compare_str);
			free(new_str);
			free(buff);
			return (head);
		}
		temp = temp->next;
	}
	fprintf(stderr, "%s: %d: %s: not Found\n", head->token, count, line);
	free(line);
	free(buff);
	if (new_str)
	{
		free(new_str);
		free(compare_str);
	}
	free_list(head);
	free_list(path);
	return (NULL);
}

char *_concat(char *str, char *add)
{
	char *new = NULL;
	int count = 0, counter = 0;

	new = malloc(strlen(str) + strlen(add) * sizeof(char) + 1);
	if (!new)
		return (NULL);

	while(str[count])
	{
		new[count] = str[count];
		count++;
	}
	while(add[counter])
	{
		new[count] = add[counter];
		count++;
		counter++;
	}
	new[count] = '\0';
	return (new);
}