#include "shell.h"

/**
 * create_child - Crea un nuevo proceso
 *
 * @args: A entry pointer
 * @arguments: Entry command
 * Return: El ID del hijo creado
 */
void create_child(char *args, char *arguments[])
{
	pid_t child = fork();
	int stat;

	if (child == 0)
	{
		if (execve(args, arguments, NULL) == -1)
		{
			perror("ERROR");
			exit(EXIT_FAILURE);
		}
	}
	if (child < 0)
	{
		perror("ERROR");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (waitpid(child, &stat, 0) == 1)
		{
			perror("ERROR");
			exit(EXIT_FAILURE);
	}
	}
}
