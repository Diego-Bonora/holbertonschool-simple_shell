#include "main.h"

/**
*/

char **convert(token_t **args)
{
	char **list;
	token_t *temp;
	int count = 0, sum = 0;
	
	temp = *args;
	while (temp)
	{
		sum += temp->len;
		temp = temp->next;
	}
	list = malloc(sum * sizeof(char) + 1);
	temp = *args;
	while (*args)
	{
		*args = (*args)->next;
		list[count] = strdup(temp->token);
		free(temp->token);
		free(temp);
		temp = temp->next;
		count++;
	}
	list[count] = '\0';
	return (list);
}