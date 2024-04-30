#include "shell.h"

/**
 * dup_string - create a copy of a string.
 * @str: input string.
 * Return: pointer to the duplicated string,
 * or NULL if memory allocation fails.
 */
char *dup_string(char *str)
{

	unsigned int posit = 0;
	char *duplicate;

	if (str == NULL)
		return (NULL);

	while (str[posit] != '\0')
		posit++;

	duplicate = malloc(sizeof(char) * (posit + 1));
	if (duplicate == NULL)
		return (NULL);

	posit = 0;
	while (str[posit] != '\0')
	{
	duplicate[posit] = str[posit];
	posit++;
	}

	duplicate[posit] = '\0';

	return (duplicate);
}
