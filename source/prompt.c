/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-baptiste.barbotin
** File description:
** prompt
*/

#include "minishell.h"

int compt_words(char *buffer)
{
    int compt = 0;
    int words = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] != ' ' && buffer[i] != '\t') {
            words++;
        }
        else
            words = 0;
        if (words == 1) {
            compt++;
        }
    }
    return (compt);
}

char **get_op_arg(char *buffer)
{
    int word_nb = compt_words(buffer);
    char **op_arg = malloc(sizeof(char *) * word_nb + 1);

    op_arg[word_nb] = NULL;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\t')
            buffer[i] = ' ';
    }
    for (int i = 0; i < word_nb; i++) {
        if (i == 0)
            op_arg[i] = strtok(buffer, " ");
        else
            op_arg[i] = strtok(NULL, " ");
    }
    return (op_arg);
}

char **get_prompt(int *error)
{
    size_t size = 0;
    char **op_arg;
    char *buffer = NULL;

    my_putstr("\e[95m-> \e[0m");
    *error = getline(&buffer, &size, stdin);
    buffer[my_strlen(buffer) - 1] = '\0';
    if (*error > 1) {
        op_arg = get_op_arg(buffer);
        return (op_arg);
    }
    else
        return (NULL);
}

char **prompt_control(int *error)
{
    char **op_arg = NULL;

    op_arg = get_prompt(error);
    return (op_arg);
}