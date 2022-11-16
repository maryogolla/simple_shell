#include "main.h"
#include <stdio.h>
int secondcheck(va_list, const char *, int *);
/**
 * formatchecker - checks the fomat string and prints to standard output
 * @list: a va_list type for getting argiments in argument list
 * @format: string to print to standard output
 * Return: number of characters printed to standard output
 */
int formatchecker(va_list list, const char *format)
{
	int i = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				i += _putchar(va_arg(list, int));
				format++;
			}
			else if (*format == 's')
			{
				i += printstring(va_arg(list, char *));
				format++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				i += printint(va_arg(list, int));
				format++;
			}
			else if (*format == '%')
			{
				i += _putchar(*format);
				format++;
			}
			else
			{
				format--;
				_putchar(*format);
				format++;
			}
		}
		if (*format == '%' && format)
			continue;
		if (*format)
		{
		_putchar(*format);
		i++;
		format++;
		}
	}
	return (i);
}
