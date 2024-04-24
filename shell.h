#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char *read_line(void);
void handle_sigint(int sign);
int execute_command(char **args);
void setup_signals(void);
void main_loop(void);

#endif
