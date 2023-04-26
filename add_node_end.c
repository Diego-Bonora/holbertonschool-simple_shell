#include "main.h"

/**
 * add_node_end - adds a node to the end of the linkedlist
 * @head: the first node
 * @str: string to put in the new node
 * Return: returns pointer to the first node
 */

token_t *add_node_end(token_t **head, const char *str)
{
	token_t *temp;
	token_t *loop;
	unsigned int len;

	loop = malloc(sizeof(token_t));
	if (!loop)
		return (NULL);

	temp = malloc(sizeof(token_t));
	if (!temp)
	{
		free(loop);
		return (NULL);
	}

	len = strlen(str);
	temp->token = strdup(str);
	temp->len = len;
	temp->next = NULL;
	if (*head == NULL)
	{
		*head = temp;
		free(loop);
	}
	else
	{
		loop = *head;
		while (loop != NULL)
		{
			if (loop->next == NULL)
			{
				loop->next = temp;
				break;
			}
			loop = loop->next;
		}
	}
	return (*head);
}
