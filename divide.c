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
	int posit = 0;
	char **tokens = malloc(bufsize* sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOKEN_DELIMIT);
	while (token != NULL)
	{
		tokens[posit] = token;
		posit++;

		if (posit >= bufsize)
		{
			bufsize += TOKEN_BUFSIZE;
			tokens = realloc(tokens, bufsize* sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "Ups: Assignment error\n");
				exit(EXIT_FAILURE);
		}

	}

	token = strtok(NULL, TOKEN_DELIMIT);
}
	tokens[posit] = NULL;
	return (tokens);
}
