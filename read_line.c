#include "shell.h"
/**
 *read_line - Read the input line writed by the user.
 *Return: buffer.
 */
char *read_line(void)
{
	char *input = NULL;
	ssize_t line = 0;
	size_t size = 0;

	if (isatty(STDIN_FILENO))
		print_string("Shellinator>$ ");
	line = getline(&input, &size, stdin);
	if (line == -1)
	{
		free(input);
		if (isatty(0))
		{
			print_string("\n");
			exit(0);
		}
	}
	if (input[line - 1] == '\n')
		input[line - 1] = '\0';
	return (input);
}
