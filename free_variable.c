#include "shell.h"
/**
 * free_resources - Frees resources for the main function.
 * @token_list: Array of strings from the main function.
 * @buffer: Input buffer from the main function.
 */
void free_resources(char **token_list, char *buffer)
{
	int i;

	while (token_list[i])
	{
		free(token_list[i]);
		i++;
	}
	free_string(token_list);
	free_memory(buffer);
}
/**
 * free_var - Frees variables for the main function.
 * @tokenize: Array of strings from the main function.
 * @buff: Input buffer from the main function.
 */
void free_var(char **token, char *input)
{
	free_string(token);
	free_memory(input);
}

/**
 * exit_status - Returns the exit value from the child process.
 * @status: Exit value.
 * Return: Exit value.
 */
int exit_status(int stat)
{
        int i;

        if (WIFEXITED(stat))
                i = WEXITSTATUS(stat);
        return (i);
}
