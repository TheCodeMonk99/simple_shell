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
	size_t len;
	int bytes;


	(void)ac;
	(void)av;

	while (1)
	{
		printf("$ \n");
		bytes = getline(&buffer, &len, stdin);
		printf("%s\n%d\n", buffer, bytes);
	}

	free(buffer);
	return (0);
}
