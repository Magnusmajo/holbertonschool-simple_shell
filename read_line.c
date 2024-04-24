#include "shell.h"

/**
 * read_line - Read the command's lines
 * entered by the keyboard
 * Return: the line
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		perror("I'll be back: user");
		exit(EXIT_FAILURE);
	}
	return (line);
}
