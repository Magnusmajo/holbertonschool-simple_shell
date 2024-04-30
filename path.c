#include "shell.h"

/**
 * get_path_value - Retrieves the value of the PATH environment variable.
 * @env: An array of strings representing the environment variables.
 * Return: A pointer to the PATH value or NULL if not found.
 */
char *get_path_value(char **env)
{
	char *path_token, *env_entry;
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		env_entry = env[i];
		path_token = strtok(env_entry, "=");
		if (_strcmp(path_token, "PATH") == 0)
		{
			path_token = strtok(NULL, "=");
			return (path_token);
		}
	}
	return (NULL);
}
/**
 * find_substring - a function that locates a substring.
 * @str: string character value.
 * @substr: substring character value.
 * Return: Returns a pointer to the substring.
 */
char *find_substring(char *str, char *substr)
{
	int i, i_sub = 0;

	if (substr[i_sub] == '\0')
		return (str);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == substr[0])
		{
			for (i_sub = 0; substr[i_sub] != '\0' && str[i + i_sub] && substr[i_sub] == str[i + i_sub]; i_sub++)
				;
			if (substr[i_sub] == '\0')
				return (str + i);
		}
	}
	return (NULL);
}
/**
 * find_executable_path - Finds the executable path for
 * a given command in the specified environment.
 *
 * @command: The name of the executable command.
 * @environment: An array of strings representing the environment.
 * @return The full path to the executable or NULL if not found.
 */
char *find_executable_path(char *command, char **environment)
{
	static char buffer[1024] = {0};
	char *path, *first_colon, *next_colon, *token;
	struct stat st;

	path = get_path_value(environment);
	if (!path)
		path = "";

	first_colon = find_substring(path, "::");
	next_colon = find_substring(path, ":/bin");

	if (path[0] == ':' || (first_colon && (first_colon < next_colon)))
	{
		if (stat(command, &st) == 0)
			return (command);
	}

	token = strtok(path, ":");
	for (; token; token = strtok(NULL, ":"))
	{
	_strcat(buffer, token);
	_strcat(buffer, "/");
	_strcat(buffer, command);
	if (stat(buffer, &st) == 0)
		return (buffer);

	_memset(buffer, 0, 1024);
	}

	return (command);
}

