#include "shell.h"
/**
 * get_env - Get the environment
 *
 * @env: Entry pointer
 *
 * Return: Pointer to environment string, NULL on failure.
 */
char *get_env(const char *env)
{
	int i = 0;
	char *env_entry_dup;
	char *env_name;
	char *env_value;

	for (i = 0; environ[i] != NULL; i++)
	{
		env_entry_dup = strdup(environ[i]);
		if (!env_entry_dup)
	{
		return (NULL);
	}

	env_name = strtok(env_entry_dup, "=");
	env_value = strdup(strtok(NULL, "="));

	if (env_name != NULL && strcmp(env_name, env) == 0)
	{

		free(env_entry_dup);
		return (env_value);
	}

	free(env_entry_dup);
	}

	return (NULL);
}
