#include "shell.h"
#define TOKEN_SIZE 32
/**
 * execute_command - Execute the especified command
 * @args: Entry pointer
 * Return: 1
 */
#include "shell.h"

char **execute_command(char *args)
{
	char bufsize = TOKEN_SIZE;
	char *token = strtok(args, " \n\t");
	char **argument = malloc(bufsize * sizeof(char *));
	int posit;
	if (!argument)
	{
		perror("Error");
		exit(EXIT_FAILURE);
		free(argument);
	}

	for (posit = 0; !token && posit < TOKEN_SIZE - 1; posit++)
	{
		argument[posit] = token;
		token = strtok(NULL, " \n\t");
	}
	argument[posit] = NULL;
	return (argument);
}

/**
 * do_it - Execute a command
 * @args: Entry point
 */
void do_it(char *args)
{
	char **arguments = execute_command(args);

		if (!arguments)
		{
			take_it(arguments);
			free(arguments);
		}
}

