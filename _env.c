#include "main.h"

/**
 * _env: read environ var and print it, add one to general counter
 * 
*/

void _env(void)
{
	int count = 0;

	while (environ[count])
	{
		printf("%s\n", environ[count]);
		count++;
	}
}
