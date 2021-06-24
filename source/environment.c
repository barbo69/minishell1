/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-baptiste.barbotin
** File description:
** environment
*/

#include "minishell.h"

linked_list_t *env_in_linked_list(char **env)
{
    linked_list_t *first = NULL;
    linked_list_t *new = NULL;
    linked_list_t *last = NULL;
    int len = 0;

    for (int i = 0; env[i] != NULL; i++) {
        new = malloc(sizeof(linked_list_t));
        if (last != NULL)
            last->next = new;
        else
            first = new;
        len = my_strlen(env[i]);
        new->info = malloc(sizeof(char) * (len + 1));
        my_strcpy(new->info, env[i]);
        new->prev = last;
        new->next = NULL;
        last = new;
    }
    return (first);
}

void put_env(linked_list_t *env_list)
{
    linked_list_t *first = env_list;

    while (first != NULL) {
        my_putstr(first->info);
        my_putchar('\n');
        first = first->next;
    }
    return;
}