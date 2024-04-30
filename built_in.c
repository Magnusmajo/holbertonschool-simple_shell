#include "shell.h"

/**
 * internal_command - Handles built-in shell commands.
 * @tokens: Array of tokens obtained from the input buffer in the startsh file.
 * @env_vars: Array of strings containing environment variables.
 * @input_buffer: Input buffer from the main program.
 * @exit_status: Exit status value.
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
