#include "main.h"

/**
 * _strdup - duplicates a string and returns a pointer
 * to duplicated string
 * @str: string to duplicate
 * Return: pointer to duplicated string
 */
char *_strdup(char *str)
{
	char *str2;
	int i;

	if (str == NULL)
		return (NULL);
	i = _strlen(str);

	str2 = malloc((i + 1) * sizeof(char));
	if (str2 == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}
