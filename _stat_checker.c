#include "main.h"

/**
 * _stat_checker - pruves a command on different paths
 * @head: linked list with command and arguments
 * @path: a tring with the path route
 * Return: a valid string with the full path to execute
*/

token_t *_stat_checker(token_t *head, token_t *path)
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
		strcat(temp->token, strdup(head->token));
		if (stat(temp->token, buff) == 0)
		{
			head->token = strdup(temp->token);
			free_list(path);
			free(buff);
			return (head);
		}
		temp = temp->next;
	}
	free_list(path);
	free(buff);
	return (NULL);
}
