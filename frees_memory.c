#include "shell.h"
/**
 * free_memory - Frees memory if the pointer is not NULL.
 * @ptr: Pointer to the memory to be freed.
 */
void free_memory(char *ptr)
{
	if (ptr != NULL)
	free(ptr);
}
/**
 * free_string - Free The str.
 * @ptr: String pointer from main function.
 */
void free_string(char **ptr)
{
	if (ptr)
	free(ptr);
}
