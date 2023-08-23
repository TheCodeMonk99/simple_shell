#include "main.h"
/**
 * _getenv - find the env vari
 * @name: variable name
 * Return: NULL if fails or pointer to value of env.var.
 */
char *_getenv(const char *name)
{
	int m;
	int k;
	char *a;
	char *copy;

	for (m = 0 ; environ[m] != NULL ; m++)
	{
		for (k = 0 ; name[k] == environ[m][k] && name[k] != '\0' ; k++)
		{
			if (name[k + 1] == '\0')
			{
				a = &environ[m][k + 2];
				copy = malloc(sizeof(char) * _strlen(a) + 1);

				if (!copy)
					return (NULL);

				copy = _strcpy(copy, a);
				return (copy);
			}
		}
	}
	return (NULL);
}
/**
 * _getline - get line from cmd
 * @bufline: buffer line string.
 * @size: size of cmd buf line.
 * @std: stream file in.
 * Return: no of bytes copied.
 **/
ssize_t _getline(char **bufline, size_t *size, FILE *std)
{
	size_t count = 0;
	size_t alloc = 1024;
	char c;

	if (!bufline || !size || !std)
		return (-1);
	if (*bufline == NULL)
	{
		*bufline = malloc(alloc);
		if (!(*bufline))
			return (-1);
	}
	while ((c = _getchar()) != EOF)
	{
		if (c == '\n')
		{
			count++;
			break;
		}
		count++;
		(*bufline)[count - 1] = c;
	}
	if (c == EOF)
	{
		return (-1);
	}
	(*bufline)[count] = '\0';
	return (count);
}
/**
* splitline - splits cmd
* @command_line: cmd string.
* Return: a pointer to cmd strings.
**/
char **splitline(char *command_line)
{
	char **ptrstr;
	int size = 100;
	int position = 0;
	char *word;

	ptrstr = malloc(sizeof(char *) * size);
	if (ptrstr == NULL)
		exit(EXIT_FAILURE);
	word = _strtok(command_line, " ");
	while (word != NULL)
	{
		ptrstr[position++] = word;
		word = _strtok(NULL, " ");
	}
	ptrstr[position] = NULL;
	return (ptrstr);
}
/**
 * execute_process - process func
 * @argm: args from cmd_line
 * @argv: args
 * @counter: number of processes running
 * Return: 0 (Suc) -1 (Fail)
 **/
int execute_process(char **argm, char **argv, int counter)
{
	pid_t child_process;
	int status, status_output = 0;
	char *buffer = NULL, *command_path = NULL;

	command_path = check_path(argm[0]);
	if (command_path == NULL)
	{
		buffer = execute_command(argm[0]);
		if (buffer == NULL)
		{
			_printf("%s: %d: %s: not found\n", argv[0], counter, argm[0]);
			free(buffer);
			return (1);
		}
	}
	child_process = fork();
	if (child_process < 0)
		exit(errno);
	else if (child_process == 0)
	{
		if (command_path != NULL)
		{
			if (execve(command_path, argm, environ) == -1)
				exit(errno);
		}
		if (execve(buffer, argm, environ) == -1)
			exit(errno);
	}

	wait(&status);
	if (WIFEXITED(status))
		status_output = WEXITSTATUS(status);
	free(buffer);

	return (status_output);
}
/**
 * _which - searches for command in dir
 * @head: head
 * @av: args
 * Return: cmd path or null
 **/
char *_which(link_t **head, char *av)
{
	link_t *pus = *head;
	char *buffer;

	if (av[0] == '.' || av[0] == '/')
	{
		if (access(av, X_OK) == 0)
			return (av);
	}

	while (pus)
	{
		buffer = _strcat(pus->dir, "/", av);
		if (access(buffer, X_OK) == 0)
		{
			return (buffer);
		}
		free(buffer);
		pus = pus->next;
	}
	return (NULL);
}
