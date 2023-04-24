#include "main.h"

/**
 * tokeniicer - separate strings with a given delimiter and stores it in a linked list
 * @line: string to tokeniz
 * @delim: string used like a delimitter
 * 
 * Return - a linked list with values of string tokenized
 */

token_t *tokenicer(char *line, char *delimit)
{
	char *list = NULL;
	token_t *tokens;

	tokens = malloc(sizeof(token_t));
	if (!tokens)
		return (NULL);

	tokens = NULL;
	list = strtok(line, delimit);
	while (list != NULL)
	{
		add_node_end(&tokens, list);
		list = strtok(NULL, delimit);
	}
	return (tokens);
}
