#include "shell.h"

/**
 * tokenizator - built-in command handler for the shell.
 * @tokens: array of tokenized strings from the startsh file.
 * @environment: array of strings for environment values.
 * @input: input buffer from the main function.
 * @stat: exit status value.
 */
void tokenizator(char **tokens, char **environment, char **input, int stat)
{
	int i = 0;
	(void)input;

	if (_strcmp(tokens[0], "exit") == 0)
	{
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(*input);
	free(tokens);
	exit(stat);
	}
	if (_strcmp(tokens[0], "env") == 0)
	{
	if (!tokens[1])
		built_in(environment);
	}
}

