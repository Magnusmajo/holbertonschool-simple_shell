#include "shell.h"
/**
 * env_builtin - enviroment built-in.
 * @env: the array of string of environment values.
 */
void env_builtin(char **env)
{
	int i;

	if (env)
	{
		for (i = 0; env[i]; i++)
		{
			print_string(env[i]);
			write_char('\n');
		}
	}
}
/**
 * main - Execute the shell.
  @argc: argumenthellcount.
 * @arv: Entry argument.
 * @env: array of string.
 * Return: Always 0.
 */
int main(int arg, __attribute__((unused))char **argv, char **env)
{
	char *input = NULL, *path, **tokenize;
	int status = 0, number = 0;
	pid_t pid;
	(void)arg;

	while (1)
	{
		input = read_line();
		tokenize = NULL;
		tokenize = custom_tokenizer(input);
		if (!tokenize)
			continue;
		cmd(tokenize, env, &input, number);
		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
			free_var(tokenize, input);
			return (1);
		}
		if (pid == 0)
		{
			path = tokenize_path(tokenize[0], env);
			if (execve(path, tokenize, NULL) == -1)
			{
				perror(tokenize[0]);
				free_resources(tokenize, input);
				exit(0);
			}
		}
		else
		{
			free_resources(tokenize, input);
			wait(&status);
			number = exit_status(status);
		}
	}
	free_var(tokenize, input);
	return (0);
}
