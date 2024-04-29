#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;
char **execute_command(char *args);
void do_it(char *args);
char *read_line(void);
void take_it(char *args[]);
void create_child(char *args, char *arguments[]);
void loop(void);
int main_loop(void);
char *get_env(const char *env);
char **split_line(char *line);
void print_env(void);

#endif
