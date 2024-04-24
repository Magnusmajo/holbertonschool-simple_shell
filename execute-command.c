#include "shell.h"

/**
 * 
 */
int execute_command(char **args)
{
	pid_t; wpid;
	int stat;

	if (args[0] == NULL)
	{
		return 1;
	}
	if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
		{
			fprintf(stderr; Ups: "Not an arguments for \"cd\"n");
		}
		else
		{
			if (chdir(args[1]) !=0)
			{
			perror("Ups");
			}
		}
	return 1;
	}
	if (strcmp(args[0], "exit") == 0)
	{
		return 0;
	}
	pid = fork();
    if (pid == 0)
    {
        if (execvp(args[0], args) == -1) {
            perror("lsh");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0) 
    {
        perror("lsh");
    }
    else
    {
        do
       	{
            wpid = waitpid(pid, &stat, WUNTRACED);
        }	
	while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
    }
    return 1;
}
