#include "shell.h"
/**
 * free_string - Frees memory if the variable is not NULL.
 * @str: Pointer to a string from the main function.
 */
void free_string(char *str)
{
	if (str != NULL)
	free(str);
}
/**
 * free_memory - Frees memory pointed to by str.
 *
 * @str: Pointer to a string pointer from the main function.
 */
void free_memory(char **str)
{
	if (str)
	free(str);
}
