#include "main.h"
/**
  * main - entry point
  * @ac: argument count
  * @av: pointer to array of strings
  * Return: Always 0
  */
int main(int ac, char **av)
{

	char *buffer = NULL;
	ssize_t len = 0;

	(void)ac;
	(void)av;
	(void)len;



	prompt();
	/*getline(&buffer, &len, 0);*/
	/*printf("%s", buffer);*/


	free(buffer);
	return (0);
}
