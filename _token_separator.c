#include "main.h"

/***/

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
