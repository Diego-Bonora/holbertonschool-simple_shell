#include "main.h"

/**
 *
 */

int main(int argc, char *argv[])
{
	char *algo, **args;
	size_t size = 64;
	int status = 1;

	(void)argv;
	(void)argc;
	algo = malloc(sizeof(char) * size);
	if (!algo)
		return (-1);
	while (status)
	{
		printf("$ ");
		if (getline(&algo, &size, stdin) == -1)
			return (0);
		args = split(algo);
		status = execute(args);

		free(algo);
		free(args);
		memset(algo, 0, size);
	}
	return (0);
}