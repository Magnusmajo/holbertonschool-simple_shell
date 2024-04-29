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
		free(line);
		exit(EXIT_FAILURE);
	}
	if (strcmp(line, "exit") == 0)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	if (strcmp(line, "env") == 0)
	{
		print_env();
	}
	return (line);
}
