#include "main.h"
/**
 * _strlen - len of a string
 * @src: string
 * Return: byte-length
 **/
int _strlen(char *src)
{
	int u;

	for (u = 0; src[u]; u++)
	{
	}
	return (u);
}

/**
 * _strtok - tokenize string
 * @str: string
 * @delim: character break
 * Return: NULL (fail)
 * or pointer to token.
 */
char *_strtok(char *str, char *delim)
{
	int m = 0, k = 0, b = 0;
	static char *tra;

	if (!delim || (!str && !tra))
		return (NULL);
	str == NULL ? str = tra : str;
	for (; str[k] == ' ' ; k++)
	{
		if (str[k + 1] == '\0')
			return (NULL);
	}
	for (m = k ; str[m] != '\0' ; m++)
	{
		if (str[m] == *delim)
		{
			b = 1;
			break;
		}
	}
	for (; str[m] != '\0' ; m++)
		if (str[m] != delim[0])
			break;
		else if (str[m + 1] == '\0')
		{
			b = 0, str[m] = '\0';
			break;
		}
		else
			str[m] = '\0';
	if (b == 0)
	{
		tra = NULL;
		return (str + k);
	}
	if (str + m)
		tra = str + m;
	else
		tra = NULL;
	return (str + k);
}
