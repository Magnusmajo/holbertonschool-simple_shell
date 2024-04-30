#include "shell.h"
/**
 * pathch - Tokenize path.
 * @token: Entry string.
 * @env: array of string to environ.
 * Return: the buffer.
 */
char *tokenize_path(char *token, char **env)
{
        static char buff[1024] = {0};
        char *path, *a, *b, *tok;
        struct stat st;

        path = get_path_value(env);
        if (!path)
                path = "";
        a = locate_sub(path, "::");
        b = locate_sub(path, ":/bin");
        if (path[0] == ':' || (a && (a < b)))
        {
                if (stat(token, &st) == 0)
                return (token);
        }
	tok = strtok(path, ":");
	while (tok)
        {
                _strcat(buff, tok);
                _strcat(buff, "/");
                _strcat(buff, token);
                if (stat(buff, &st) == 0)
                        return (buff);
                tok = strtok(NULL, ":");
                _memset(buff, 0, 1024);
        }
        return (token);
}
