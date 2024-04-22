#include "shell.h"

/**
 * create_child - Crea un nuevo proceso
 * Return: El ID del hijo creado
 */
void create_child(char command[])
{
pid_t child = fork();
	int stat;

	if (child == 0) /*Proceso hijo*/
	{
		char *args[] = {command, NULL}; /*Lista de argumentos para el comando*/

		execv(command, args); /*Ejecuta el nuevo programa*/

		/*Si llegamos aqui, hubo un error en execv*/
		perror("Sorry, an error occurred");
		exit(EXIT_FAILURE);
	}

	else if (child > 0) /*Proceso padre*/
	{
		waitpid(child, &stat, 0); /*Espera al hijo*/
	}

	else
	{
		perror("Error creating new process");
		exit(EXIT_FAILURE);
	}

}
