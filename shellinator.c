#include "shell.h"
/**
 * main - Creating the Principal bucle
 * Return: Always 0
 */
int main_loop(void)
{
	char *line;
	char **args;
	int arnold;

	do {
		printf("<Shellinator$> ");
		line = read_line();
		args = split_line(line);
		arnold = execute_command(args);
		free(line);
		free(args);
	} while (arnold);
}
