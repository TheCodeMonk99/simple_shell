#include "main.h"
/**
* p_char - print char to stdout.
* @arguments: char to print
* Return: no of chars printed.
*/
int p_char(va_list arguments)
{
	_putchar(va_arg(arguments, int));
	return (1);
}
/**
* p_int - prints integer.
* @arguments: args
* Return: integers printed.
*/
int p_int(va_list arguments)
{
	long int p, p_aux, e = 1, l_aux;
	int count = 0;

	p = va_arg(arguments, int);

	if (p < 0)
	{
		p_aux = -p;
		_putchar('-');
		count++;
	}
	else
		p_aux = p;
	l_aux = p_aux;
	while (p_aux > 9)
	{
		p_aux = p_aux / 10;
		e *= 10;
	}
	while (e > 0)
	{
		_putchar(((l_aux / e) % 10) + '0');
		count++;
		e /= 10;
	}
	return (count);
}
/**
* p_str - print string.
* @arguments: nuts.
* Return: string chars.
*/
int p_str(va_list arguments)
{
	char *p;
	int i;

	p = va_arg(arguments, char *);
	if (p == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	for (i = 0 ; p[i] != '\0' ; i++)
	{
	_putchar(p[i]);
	}
	return (i);
}

/**
* _printf - print c,s,f,u,i,d
* @format: arguments
* Return: length of chars
*/
int _printf(const char *format, ...)
{
form types[] = {
	{"c", p_char}, {"s", p_str}, {"d", p_int}, {"i", p_int}, {NULL, NULL}};
	va_list arguments;
	int pos = 0, length = 0, pos_form;

	va_start(arguments, format);
	if (!format || !format[pos])
		return (-1);
	for (; format[pos]; pos++)
	{
		if (format[pos] == '%')
		{
			if (format[pos + 1] == '\0')
				return (-1);
			if (format[pos + 1] == '%')
				_putchar(37), length++;
			else
			{
				for (pos_form = 0; types[pos_form].ch != NULL; pos_form++)
				{
					if (types[pos_form].ch[0] == format[pos + 1])
					{
						length += types[pos_form].func(arguments);
						break;
					}
				}
				if (types[pos_form].ch == NULL)
				{
					_putchar(format[pos]);
					_putchar(format[pos + 1]), length += 2;
				}
			}
			pos++;
		}
		else
			_putchar(format[pos]), length++;
	}
	va_end(arguments);
	return  (length);
}
