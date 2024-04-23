#include "shell.h"
/**
 * handle_commands - Drive the internal commands
 * Return: -1 if non internal command,
 * 0 to exit shellinator
 */
int handle_commands(char **args) {
    if (args[0] == NULL) {
        return 1; // No se ingresó ningún comando
    }
    if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "lsh: Missing argument \"cd\"\n");
        } else {
            if (chdir(args[1]) != 0) {
                perror("lsh");
            }
        }
        return 1;
    }
    if (strcmp(args[0], "exit") == 0) {
        return 0; // Salir de la shell
    }
    return -1; // Comando no interno
}
