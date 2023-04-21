#include "main.h"

/***/

token_t *_stat_checker(token_t *head, token_t *path)
{
    token_t *temp;
    struct stat *buff;

    buff = malloc(sizeof(struct stat));

    while(path)
    {
        temp = path;
        strcat(path->token, "/");
        strcat(path->token, strdup(head->token));
        if (stat(path->token, buff) == 0)
        {
            head->token = strdup(path->token);
        }
        path = path->next;
        free(temp);
    }
    return (head);
}