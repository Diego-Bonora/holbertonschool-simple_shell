#include "main.h"

/***/

token_t *_stat_checker(token_t *head, token_t *path)
{
    token_t *temp;
    struct stat *buff;

    buff = malloc(sizeof(struct stat));

    temp = path;
    while(temp)
    {
        strcat(temp->token, "/");
        strcat(temp->token, strdup(head->token));
        if (stat(temp->token, buff) == 0)
        {
            head->token = strdup(temp->token);
        }
        temp = temp->next;
    }
    free_list(path);
    free(buff);
    return (head);
}