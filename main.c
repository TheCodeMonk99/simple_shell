#include "main.h"
/**
  * main - entry point
  * @ac: argument count
  * @argv: pointer to array of strings
  * @env: environment
  * Return: Always 0
  */
int main(int ac, char **argv, char **env)
{
	int s_o = 0, rd = 1, count = 0;

	(void)ac;
	while (rd)
	{
		char *cmdl = NULL, **am = NULL;
		size_t linesz = 0;

		prompt();
		signal(SIGINT, signal_c);
		rd = getline(&cmdl, &linesz, stdin);
		if (rd < 0)
		{
			free(cmdl);
			exit(s_o);
		}
		if (rd == 1)
		{
			free(cmdl);
			continue;
		}
		if (rd != EOF)
		{
			count++;
			strtok(cmdl, "\n");
			if (_mexit(cmdl) == 0)
				return (0);
			if (_env(cmdl, count, argv, env) == 0)
				continue;
			am = splitline(cmdl);
			if (am[0] == NULL)
			{
				free(cmdl), free(am);
				continue;
			}
			s_o = execute_process(am, argv, count);
		}
		free(cmdl), free(am);
	}
	return (0);
}
