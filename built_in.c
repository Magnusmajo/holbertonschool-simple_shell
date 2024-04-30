#include "shell.h"

/**
 * cmd - Handles built-in shell commands.
 * @tokens: Array of tokens obtained from the input buffer in the startsh file.
 * @vars: Array of strings containing environment variables.
 * @input: Input buffer from the main program.
 * @exit_stat: Exit status value.
 */
void cmd(char **tokens, char **vars, char **input, int exit_stat)
{
	int posit = 0;
	(void)input;

	if (_strcmp(tokens[posit], "exit") == 0)
	{
		while (tokens[posit])
			posit++;
		free(tokens[posit]);
		free(*input);
		free(tokens);
		exit(exit_stat);
	}
	else if (_strcmp(tokens[posit], "env") == 0)
	{
		if (!tokens[posit + 1])
		env_builtin(vars);
	}
	posit++;
}
