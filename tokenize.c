#include "shell.h"
/**
 * custom_tokenizer - Tokenizes an input buffer into an array of strings.
 * @input_buffer: Entry input.
 * Return: array of strings.
 */
char **custom_tokenizer(char *input_buffer)
{
        char *current_token, **token_array;
        int index = 0, num_tokens = 1, non_space_flag = 0, token_index = 0;

        while (input_buffer[index] && input_buffer[index + 1])
        {
        if (input_buffer[index] != ' ')
                non_space_flag = 1;
        if (input_buffer[index] == ' ')
                non_space_flag = 0;
        if (non_space_flag == 0 && input_buffer[index] == ' ' && input_buffer[index + 1] != ' ')
                num_tokens++;
        index++;
        }

        token_array = malloc(sizeof(char *) * (num_tokens + 1));
        if (!token_array)
                return NULL;

        current_token = strtok(input_buffer, " \t\n");
        if (!current_token)
        {
                free(token_array);
                return NULL;
        }

        while (current_token)
        {
        token_array[token_index] = dup_string(current_token);
        current_token = strtok(NULL, " \t\n");
        token_index++;
        }
        token_array[token_index] = NULL;

        return token_array;
}
           
