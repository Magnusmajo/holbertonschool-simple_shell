#include "shell.h"
#include <unistd.h>

/**
 * write_character - Writes a character to standard output
 * @ch: The character to print
 * Return: On success, returns 1.
 * On error, returns -1 and sets errno appropriately.
 */
int write_character(char ch)
{
	return (write(1, &ch, 1));
}

/**
 * write_string - Prints a string
 * @str: String value.
 */
void write_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		write_character(str[i]);
		i++;
	}
}

