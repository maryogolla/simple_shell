#include "main.h"
/**
 * printstring - prints a string to standard output
 * @s: string to print
 * Return: number of characters in the string excluding
 * null terminating byte
 */
int printstring(const char *s)
{
	int i = 0;
	const char *p;

	if (s == NULL)
		p = "(null)";
	else
		p = s;
	while (p[i] != '\0')
	{
		_putchar(p[i]);
		i++;
	}
	return (i);
}
