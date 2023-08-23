#include "main.h"
/**
 * _getchar - get chars of cmd
 * Return: command line or EOF.
 **/
int _getchar(void)
{
	static unsigned char buff[BUFF_SIZE];
	static int i;
	static int count;

	i = 0;
	count = 0;
	if (i >= count)
	{
		i = 0;
		count = read(STDIN_FILENO, buff, BUFF_SIZE);
		printf("%i\n", count);
		if (count == 0)
			return (EOF);
		if (count < 0)
			return (EOF);
	}
	return (buff[i++]);
}
