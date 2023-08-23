#include "main.h"
/**
 * check_path - is argument in path?
 * @am: argument
 * Return: am  NULL otherwise
 */
char *check_path(char *am)
{
	if (access(am, X_OK) == 0)
		return (am);
	return (NULL);
}

/**
 * execute_command -is arg in path
 * @am: entry argument
 * Return: am (Success) NULL if absent
 */
char *execute_command(char *am)
{
	char *path = NULL;
	link_t *head = NULL;
	char *buffer = NULL;

	path = _getenv("PATH");
	head = _link(path);
	buffer = _which(&head, am);
	if (buffer != NULL)
	{
		free(path),
		free_list(head);
		return (buffer);
	}
	free(path);
	free_list(head);
	return (NULL);
}
