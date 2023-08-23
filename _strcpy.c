#include "main.h"
/**
 * _strcpy - copies string to another pointer
 * @src: source pointer
 * @dest: destination pointer
 * Return: returns destination pointer
 */
char *_strcpy(char *dest, char *src)
{
	int y, z;

	for (y = 0; src[y] != '\0' ; y++)
	{
	}
	for (z = 0; z < y ; z++)
	{
		dest[z] = src[z];
	}
	for (; z <= y ; z++)
	{
		dest[z] = '\0';
	}
	return (dest);
}
