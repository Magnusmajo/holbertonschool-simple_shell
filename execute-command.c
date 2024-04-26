#include "shell.h"

/**
 * execute_command - Execute the especified command
 * @args: Entry pointer
 * Return: 1
 */
int execute_command(char **args)
{
	pid_t pid;
	int stat;

	if (args[0] == NULL)
		{
			return (1);
		}
	if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
		{
			fprintf(stderr, "Ups: Not an arguments for \"cd\n");
		}
		else
		{
			if (chdir(args[1]) != 0)
			{
			perror("Ups, an error ocurred\n");
			}
		}
		return (1);
	}
	if (strcmp(args[0], "exit") == 0)
	{
		return (0);
	}

	pid = fork();
	if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
		{
			perror("Ups");
			exit(EXIT_FAILURE);
		}
		}
	else if (pid < 0)
		{
			perror("Ups");
		}
	else
		{
			waitpid(pid, &stat, WUNTRACED);

		}
	return (1);
}
