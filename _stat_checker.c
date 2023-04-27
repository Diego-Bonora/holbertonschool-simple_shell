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
		strcat(temp->token, "/");
		strcat(temp->token, head->token);
		if (stat(temp->token, buff) == 0)
		{
			free(head->token);
			head->token = strdup(temp->token);
			free_list(path);
			free(buff);
			return (head);
		}
		temp = temp->next;
	}
	fprintf(stderr, "%s: %d: %s: not Found\n", head->token, count, line);
	free(line);
	free(buff);
	free_list(head);
	free_list(path);
	return (NULL);
}
