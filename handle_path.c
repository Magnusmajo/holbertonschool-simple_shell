#include "shell.h"

/**
 * get_path_value - Retrieves the value of
 * the "PATH" environment variable.
 * @env: Array of strings representing environment variables.
 * Return: Pointer to the value of "PATH" or NULL if not found.
 */
char *get_path_value(char **env)
{
	char *token, *c;
	int posit = 0;

	for (; env[posit]; posit++)
	{
		c = env[posit];
		token = strtok(c, "=");
		if (strcmp(token, "PATH") == 0)
	       {
		token = strtok(NULL, "=");
		return token;
		}
	}
	return NULL;
}

/**
 * locate_sub - Locates a substring..
 * @input: Entry string.
 * @c: Substring
 * Return: Returns a pointer to substring.
 */
char *locate_sub(char *input, char *c)
{
	int index;
	int index_2 = 0;

	if (c[index_2] == '\0')
		return (input);
	
	for (index = 0; input[index] != '\0'; index++)	
	{
		if (input[index] == c[0])
		{
		for (index_2 = 0; c[index_2] != '\0' && input[index + index_2]
		&& c[index_2] == input[index + index_2]; index_2++)
			;
		if (c[index_2] == 0)
			return (input + index);
		}
	}
	return (0);
}
