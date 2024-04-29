#include "shell.h"

/**
 * print_env - prints environment
 *
 * @env: Entry pointer to pointer
 */
extern char **environ;
void print_env(void)
{
	char **env_ptr = environ;

	if (*env_ptr == NULL)
	{
		fprintf(stderr, "Error\n");
		return;
	}
	while (*env_ptr != NULL)
	{
		printf("%s\n", *env_ptr);
		env_ptr++;
	}
}
