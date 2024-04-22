#include "shell.h"

int main()
{
    char command[100];

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
            printf("See you, baby!...\n");
            break;
        }

        // Crear un nuevo proceso hijo

    create_child(command);
    }

    return 0;
}
