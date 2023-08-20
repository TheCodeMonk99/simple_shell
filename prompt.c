#include "main.h"
/**
  * prompt - prompts user with $
  *
  * Return: void
  */

void prompt(void)
{
	char *prompt = "$ ";
	char *lineptr;
	size_t bytes = 0;

	while (1)
	{
		printf("%s\n", prompt);
		getline(&lineptr, &bytes, stdin);
		printf("%s\n", lineptr);
	}

	free(lineptr);
	return (0);
}
