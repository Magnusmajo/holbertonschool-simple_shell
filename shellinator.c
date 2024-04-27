#include "shell.h"
/**
 * loop  - Creating the Principal bucle
 * Return: Always 0
 */
int main(void)
{
	char *line;
	
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			printf("<Shellinator$> ");
			fflush(stdout);
		}
		else
		{
			;
		}

		printf("<Shellinator$> ");
		fflush(stdout);
		line = read_line();
		execute_command(line);
		free(line);
	}
	free(line);
	return (EXIT_SUCCESS);
}
