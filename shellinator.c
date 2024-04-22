#include "shell.h"
/**
 * main - Entry point
 * Return: Always 0.
 */
int main(void)
{
	char command[100];

	while (1)
	{
		printf("shellinator$ ");
		fflush(stdout);

	if (read(STDIN_FILENO, command, sizeof(command)) == -1)
	{
		perror("Error reading input");
		exit(EXIT_FAILURE);
	}
		command[strcspn(command, "\n")] = '\0';

	if (strcmp(command, "exit") == 0)
	{
		printf("See you later, baby!...\n");
		break;
	}

	create_child(command);
	}

	return (0);
}
