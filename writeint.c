#include <unistd.h>
#include "main.h"

/**
 * printint - prints an integer to the standatd output
 * @x: integer to print
 * Return: number of digits in the integer
 */
int printint(int x)
{
	int v;
	char minus = '-';
	unsigned int j;

	if (x < 0)
		j = (unsigned int)x * -1;
	else
		j = (unsigned int)x;
	if (j == 0)
		v = 1;
	else
		v = calculate_numbers(j);
	if (x < 0)
	{
		write(1, &minus, 1);
		writeint(j, v);
	}
	else
	{
		writeint(j, v);
	}
	return (v);
}
/**
 * writeint - recursive function to print every digit of an
 * integer to standard output
 * @x: integer to print
 * @l: number of digits in x
 */
void writeint(unsigned int x, int l)
{
	unsigned int y;
	char j;

	if (l == 0)
		return;
	l--;
	y = x % 10;
	j = y + '0';
	writeint(x / 10, l);
	write(1, &j, 1);
}
