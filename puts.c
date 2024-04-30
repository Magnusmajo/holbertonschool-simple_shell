#include "shell.h"
#include <unistd.h>
/**
 * write_char - Writes a single character to stdout.
 * @ch: The character to print.
 * Return: On success, returns 1.
 * On error, returns -1 and sets errno appropriately.
 */
int write_char(char ch)
{
        return (write(1, &ch, 1));
}
/**
 * print_string - puts function strings
 * @str: character value.
 */
void print_string(char *str)
{
        int posit;

	for (posit = 0; str[posit] != 0; posit++)
		write_char(str[posit]);
}
