#include <unistd.h>
#include "main.h"

/**
 * printunsigned - prints an unsigned integer to standard output
 * @i: unsigned integer to print
 * Return: number of digits in i
 */
int printunsigned(unsigned int i)
{
	unsigned int k;
	int v = 0;

	k = i;
	if (k == 0)
		v = 1;
	else
		v = calculate_numbers(k);
	writeunsigned(k, v);
	return (v);
}
/**
 * writeunsigned - recursive function to write all digits
 * of an integer
 * @x: integer to write
 * @l: number of digits in x
 */
void writeunsigned(unsigned int x, int l)
{
	int y;
	char j;

	if (l == 0)
		return;
	l--;
	y = x % 10;
	j = y + '0';
	writeunsigned(x / 10, l);
	write(1, &j, 1);
}
/**
 * calculate_numbers - returns number of digits in a number
 * @i: interger to find number of digits
 * Return: number of digits in i
 */
int calculate_numbers(unsigned int i)
{
	int v = 0;

	while (i > 0)
	{
		v++;
		i /= 10;
	}
	return (v);
}
