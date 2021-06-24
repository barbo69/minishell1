/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-baptiste.barbotin
** File description:
** linked_list
*/

#include "minishell.h"

int listlen(linked_list_t *env_list)
{
    linked_list_t *first = env_list;
    int compt = 0;

    while (first != NULL) {
        compt++;
        first = first->next;
    }
    return (compt);
}

char **env_list_to_env(linked_list_t *env_list)
{
    int len = listlen(env_list);
    char **env = malloc(sizeof(char *) * (len + 1));
    linked_list_t *first = env_list;

    for (int i = 0; i < len; i++) {
        env[i] = first->info;
        first = first->next;
    }
    env[len] = NULL;
    return (env);
}

linked_list_t *search_var(linked_list_t *env_list, char *env)
{
    int len = my_strlen(env);
    linked_list_t *first = env_list;

    while (first != NULL) {
        if (my_strncompare(env, first->info, len) == 1
            && first->info[len] == '=')
            return (first);
        first = first->next;
    }
    return (NULL);
}