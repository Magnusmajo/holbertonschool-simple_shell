#include "shell.h"
/**
 * _getenv - Gets the desired environment
 *
 * @envy: name in mayus of the environment you want
 *
 * Return: Pointer to environment string, NULL on failure.
 */
char *get_env(const char *env)
{
	int i = 0;

	while (environ[i++])
		if (strcmp(environ[i], env) == '=')
			break;
		else if (environ[i] == NULL)
		{
			fprintf(stderr, "bash: %s: ", env);
			perror("");
		}

	return (environ[i]);
}
