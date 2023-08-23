#include "main.h"
/**
  * prompt - prompts user with $
  *
  * Return: void
  */

void prompt(void)
{
	int i = 0;

	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		i = 1;
	if (i)
		write(STDERR_FILENO, "$ ", 2);
}
