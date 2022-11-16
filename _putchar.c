#include <unistd.h>
#include <stdio.h>

int _putchar(char i)
{
	write(1, &i, 1);
	return (1);
}
