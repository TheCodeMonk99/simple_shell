#include "main.h"
/**
  * _mexit - check if cmd is exit
  * @line: input to be checked
  * Return: 0 if exit 1 if otherwise
  **/
int _mexit(char *line)
{
	char *exitsl = "exit";
	int m = 0;
	int len = _strlen(line);

	if (len == 4)
	{
		while (exitsl[m])
		{
			if (exitsl[m] != line[m])
				return (1);
			m++;
		}
		free(line);
		return (0);
	}
	return (1);
}
/**
 * signal_c - input signal Ctrl + C
 * @sign: signal
 **/
void signal_c(int sign)
{
	signal(sign, SIG_IGN);
	write(STDOUT_FILENO, "\n$ ", 4);
	signal(SIGINT, signal_c);
}
/**
 * _env - print env variables
 * @cmd: cmd line.
 * @counter: no of entry args
 * @argv: args from main
 * @env: env variables
 * Return: 0 succes, 1 if fails.
 * 127 if env not found
 **/
int _env(char *cmd, int counter, char **argv, char **env)
{
	char *env_line = "env";
	int a = 0;
	int en = _strlen(cmd);

	if (en == 3)
	{
		while (env_line[a])
		{
			if (env_line[a] != cmd[a])
				return (1);
			a++;
		}
		if (env)
		{
			for (a = 0; env[a] != NULL; a++)
				_printf("%s\n", env[a]);
			free(cmd);
			return (0);
		}
		else
		{
			_printf("%s: %d: env: not found\n", argv[0], counter);
			return (127);
		}
	}
	return (1);
}
