#include "shell.h"

#define TOKEN_BUFSIZE 64
#define TOKEN_DELIMIT " \t\r\n\a"

/**
 * split_line - Divide a line into tokens
 *
 * @line: Entry char
 * Return: The complete array
 */
char **split_line(char *line)
{
	int bufsize = TOKEN_BUFSIZE;
	int posit;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token = strtok(line, TOKEN_DELIMIT);

	if (!tokens)
	{
		perror("malloc_error");
		exit(EXIT_FAILURE);
		free(tokens);
	}

	for (posit = 0; posit < bufsize - 1; posit++)
	{
		tokens[posit] = token;
		token = strtok(NULL, TOKEN_DELIMIT);
	}

	tokens[posit] = NULL;
	return (tokens);
}
