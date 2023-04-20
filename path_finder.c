#include "main.h"

/**
*/

char **_PATH(void)
{
    char *path, *path_c, *separador, **array;
    int count = 0;

    array = malloc(sizeof(char) * 1024);
    if (!array)
        return(NULL);

    path = getenv("PATH");
    path_c = path;

    separador = strtok(path_c, ":");
    while (separador != NULL)
    {
        array[count] = separador;
        count++;
        separador = strtok(NULL, ":");
    }
    array[count] = NULL;
    return (array);
}