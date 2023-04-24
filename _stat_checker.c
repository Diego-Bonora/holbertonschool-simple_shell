#include "main.h"

/**
 * _stat_chequer - pruves a command on differents folders of path till it could execute
 * @head: linked list with command and arguments
 * @path: a tring with the path route
 * 
 * Return - a valid string with the full path to execute
*/

token_t *_stat_checker(token_t *head, token_t *path)
{
	token_t *temp;
	struct stat *buff;

	buff = malloc(sizeof(struct stat));

	temp = path;
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
