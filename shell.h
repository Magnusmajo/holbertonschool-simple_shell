#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <stddef.h>

extern char **environ;
int write_char(char ch);
void print_string(char *str);
char *dup_string(char *str);
char **custom_tokenizer(char *input_buffer);
char *get_path_value(char **env);
char *tokenize_path(char *token, char **env);
char *locate_sub(char *input, char *c);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcat(char *dest, char *src);
int _strlen(char *str);
char *_memset(char *s, char b, unsigned int n);
void cmd(char **tokens, char **vars, char **input, int exit_stat);
char *read_line(void);
void free_memory(char *ptr);
void free_string(char **ptr);
void env_builtin(char **env);
void free_resources(char **token_list, char *buffer);
void free_var(char **token, char *input);
int exit_status(int stat);

#endif
