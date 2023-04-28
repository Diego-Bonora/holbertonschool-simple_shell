#include "main.h"

/**
 * _stat_checker - pruves a command on different paths
 * @head: linked list with command and arguments
 * @path: a tring with the path route
 * Return: a valid string with the full path to execute
*/

token_t *_stat_checker(token_t *head, token_t *path)
{
	token_t *temp;
	struct stat *buff;
	char *new_str = NULL, *compare_str = NULL, *test = NULL, *test2 = NULL;

	test = strdup(head->token);
	test2 = simplify(test);
	free(test);
	buff = malloc(sizeof(struct stat));
	temp = path;

	if (stat(head->token, buff) == 0 && stat(test2, buff) == 0)
	{
		free_list(path);
		free(test2);
		free(buff);
		return (head);
	}
	free(test2);
	while (temp)
	{
		new_str = _concat(temp->token, "/");
		compare_str = _concat(new_str, head->token);
		if (stat(compare_str, buff) == 0)
		{
			free(head->token);
			head->token = strdup(compare_str);
			free_list(path);
			free(compare_str);
			free(new_str);
			free(buff);
			return (head);
		}
		free(compare_str);
		free(new_str);
		temp = temp->next;
	}
	free(buff);
	free_list(head);
	free_list(path);
	return (NULL);
}

/**
 * _concat - concatenates two string
 * @str: the first part of the string
 * @add: the last part of the string
 * Return: Returns a new string with the necesary ammount of memory
*/

char *_concat(char *str, char *add)
{
	char *new = NULL;
	int count = 0, counter = 0;

	new = malloc(strlen(str) + strlen(add) * sizeof(char) + 1);
	if (!new)
		return (NULL);

	while (str[count])
	{
		new[count] = str[count];
		count++;
	}
	while (add[counter])
	{
		new[count] = add[counter];
		count++;
		counter++;
	}
	new[count] = '\0';
	return (new);
}

/**
 * simplify - simplyfies the input into only the command
 * @str: the command given by the usr
 * Return: Returns a new string with only the command in it
*/

char *simplify(char *str)
{
	token_t *simple, *temp, *delete;
	char *no_path = NULL, *no_path_helper = NULL;

	simple = tokenicer(str, "/");
	temp = simple;
	delete = temp;
	while (temp->next)
	{
		delete = temp;
		temp = temp->next;
	}
	if (temp)
	{
		delete->next = NULL;
		free(temp->token);
		free(temp);
	}
	temp = simple;
	if (temp->token)
		no_path = _concat("/", temp->token);
	while (temp->next)
	{
		temp = temp->next;
		no_path_helper = _concat(strdup(no_path), "/");
		free(no_path);
		no_path = _concat(strdup(no_path_helper), temp->token);
		free(no_path_helper);
	}
	if (simple)
		free_list(simple);
	return (no_path);
}
