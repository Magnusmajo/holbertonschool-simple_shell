#include "shell.h"

/**
 * print_env - prints environment
 */

extern char **environ;
void print_env(void)
{
	char **env = environ;

	if (*env == NULL)
	{
		fprintf(stderr, "Error: environ is NULL\n");
		return;
	}
	while (*env != NULL)
	{
		if (*env != NULL)
			printf("%s\n", *env);
		env++;
	}
}
