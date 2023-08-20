#include "main.h"
/**
  * _putchar - prints char to stdoutput
  * @c: char to be printed
  * Return: no of bytes printed
  */
int _putchar (char c)
{
	return (write(1, &c, 1));
}

/**
  * _printstring - prints string
  * @str: pointer to string
  *
  * Return: num of chars printed
  */
int _printstring(char *str)
{
	int num;

	while (*str)
	{

		_putchar(*str);
		num++;
		str++;
	}
	_putchar(10);
	return (num);
}
