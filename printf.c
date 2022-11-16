#include "main.h"
#include <stdarg.h>
/**
 * _printf - prints a formatted string to standard output
 * @format: string to print with formatted output
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0;
	va_list list;

	va_start(list, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{
		return (-1);
	}
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	i = formatchecker(list, format);
	va_end(list);
	return (i);
}
