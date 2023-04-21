#include "main.h"

/***/

char **_list_to_array(token_t *head)
{
    char **array = NULL;
    int count = 0;
    token_t *temp = NULL;

    temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    array = malloc(count * sizeof(char *) + 1);
    temp = head;
    count = 0;
    while (temp)
    {
        array[count] = malloc(sizeof(char) * strlen(temp->token) + 1);
        count++;
        temp = temp->next;
    }
    count = 0;
    temp = head;
    while (temp)
    {
        array[count] = strdup(temp->token);
        array[count][strlen(temp->token) + 1] = '\0';
        count++;
        temp = temp->next;
    }
    free_list(head);
    array[count] = NULL;
    return (array);
}