#include "main.h"

/**
 * _strcmp - compares two strings lexicographically
 * @s1: first string
 * @s2: second string
 * Return: 0 if strings compare 1 otherwise
 */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	if (s1 == NULL || s2 == NULL)
		return (1);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (1);
	}
	return (0);
}
