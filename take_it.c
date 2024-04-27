#include "shell.h"
#define MAX_PATH_LENGTH 69

/**
 * search - busca la ruta correcta para un comando
 * @argv: argumentos del programa
 */
void take_it(char *args[])
{
	char *route = get_env("PATH");
	char buffer_route[MAX_PATH_LENGTH];
	char *copy_route = strdup(route);
	char *token_route = strtok(copy_route, ":");

	if (route == NULL)
	{
		fprintf(stderr, "Error al obtener la variable PATH.\n");
		return;
	}

	if (copy_route == NULL)
	{
		free(route);
		fprintf(stderr, "Error al duplicar la variable PATH.\n");
		return;
	}

	if (args[0] != NULL)
	{
		if (strchr(args[0], '/') != NULL)
		{
			create_child(args[0], args);
		}
		else
		{
			while (token_route != NULL)
			{
				sprintf(buffer_route, "%s/%s", token_route, args[0]);
				if (access(buffer_route, X_OK) != -1)
				{
					create_child(buffer_route, args);
					break;
				}
				token_route = strtok(NULL, ":");
			}
			if (token_route == NULL)
				fprintf(stderr, "Comando no encontrado: %s\n", args[0]);
		}
	}

	free(copy_route);
	free(route);
}

