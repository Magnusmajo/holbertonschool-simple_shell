#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    char command[100];
    pid_t child;
    int stat;

    while (1)
    {
        // Imprime el prompt
        printf("shellinator$ ");
        fflush(stdout);

        // Lee el comando ingresado por el usuario
	if (read(STDIN_FILENO, command, sizeof(command)) == -1)
	{
		perror("Error reading input");
			exit(EXIT_FAILURE);
	}
	command[strcspn(command, "\n")] = '\0';
        
	// Si el usuario escribe "exit", finaliza el programa
        if (strcmp(command, "exit") == 0)
        {
            printf("Bye bye...\n");
            break;
        }

        // Crear un nuevo proceso hijo
        child = fork();

        if (child == 0) // Proceso hijo
        {
            char *args[] = {command, NULL}; // Lista de argumentos para el comando
            execv(command, args); // Ejecuta el nuevo programa

            // Si llegamos aquí, hubo un error en execv
            perror("Sorry, an error occurred");
            exit(EXIT_FAILURE);
        }
        else if (child > 0) // Proceso padre
        {
            waitpid(child, &stat, 0); // Espera al hijo
        }
        else
        {
            perror("Error creating new process");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

