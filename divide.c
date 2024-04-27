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
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr,"\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOKEN_DELIMIT);

	while (token != NULL)
       	{
	tokens[position] = token;
	position++;

	if (position >= bufsize)
       {
		bufsize += TOKEN_BUFSIZE;
		tokens = realloc(tokens, bufsize * sizeof(char *));
		if (!tokens)
		{
			fprintf(stderr, "lsh: error de asignación\n");
			exit(EXIT_FAILURE);
		}
	for (posit = 0; posit < bufsize - 1; posit++)
	{
		tokens[posit] = token;
		token = strtok(NULL, TOKEN_DELIMIT);
	}

	token = strtok(NULL, TOKEN_DELIMIT);
	}
	tokens[position] = NULL;
	return tokens;
}
