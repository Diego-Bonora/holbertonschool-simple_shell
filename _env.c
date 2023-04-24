#include "main.h"

/***/

void _env(void)
{
	int count = 0;

	while (environ[count])
	{
		printf("%s\n", environ[count]);
		count++;
	}
}
