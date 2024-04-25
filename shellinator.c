#include "shell.h"
/**
 * loop  - Creating the Principal bucle
 * Return: Always 0
 */
void loop(void)
{
	char *line;
	char **args;
	int arnold;

	do {
		printf("<Shellinator$> ");
                fflush(stdout);
		line = read_line();
		/*line[strcspn(line, "\n")] = '\0';*/

		int len = strlen(line);

		while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == ' ' || line[len - 1] == '\t')) {
			line[len - 1] = '\0';
			len--;
		}

		args = split_line(line);
		arnold = execute_command(args);
		free(line);
		free(args);
	} while (arnold);
}
