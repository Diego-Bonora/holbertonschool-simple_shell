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
	token_t *recorer;
	unsigned int len;

	recorer = malloc(sizeof(token_t));
	if (!recorer)
		return (NULL);

	temp = malloc(sizeof(token_t));
	if (!temp)
	{
		free(recorer);
		return (NULL);
	}

	len = strlen(str);
	temp->token = strdup(str);
	temp->len = len;
	temp->next = NULL;
	if (*head == NULL)
	{
		*head = temp;
	}
	else
	{
		recorer = *head;
		while (recorer != NULL)
		{
			if (recorer->next == NULL)
			{
				recorer->next = temp;
				break;
			}
			recorer = recorer->next;
		}
	}
	return (*head);
}
