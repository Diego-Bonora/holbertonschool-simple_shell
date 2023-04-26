#include "main.h"

/**
 * _stat_checker - pruves a command on different paths
 * @head: linked list with command and arguments
 * @path: a tring with the path route
 * Return: a valid string with the full path to execute
*/

token_t *_stat_checker(token_t *head, token_t *path)
{
	token_t *temp, *arguments;	
	struct stat *buff;
	char *temp_str;

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
		arguments = head;
		strcat(temp->token, "/");
		strcat(temp->token, strdup(head->token));
		temp_str = temp->token;
		if (arguments->next)
		{
			arguments = arguments->next;
			while (arguments)
			{
				strcat(temp_str, " ");
				strcat(temp_str, strdup(arguments->token));
				arguments = arguments->next;
			}
		}
		if (stat(temp_str, buff) == 0)
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
