#include "main.h"
/**
  * prompt - prompts user with $
  *
  * Return: void
  */

int main(int ac, char **av)
{
	char *prompt = "$ ";
	char *lineptr;
	size_t bytes = 0;

	(void)ac;
	(void)av;

	while (1)
	{
		printf("%s\n", prompt);
		getline(&lineptr, &bytes, stdin);
		printf("%s\n", lineptr);
	}

	free(lineptr);
	return (0);
}
