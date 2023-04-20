#include "main.h"

/**

*/

char **split(char *line)
{
	char *list;
	token_t *args;
	int count = 0;

	args = malloc(sizeof(token_t));
	if (!args)
		return (NULL);
	args = NULL;
	list = strtok(line, DELIMIT);
	while (list != NULL)
	{
		add_node_end(&args, list);
		count++;
		list = strtok(NULL, DELIMIT);
	}
	return (convert(&args));
}