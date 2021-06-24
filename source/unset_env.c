/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-baptiste.barbotin
** File description:
** unset_env
*/

#include "minishell.h"

void delet_env_var(linked_list_t *var, linked_list_t **env_list)
{
    linked_list_t *prev = var->prev;
    linked_list_t *next = var->next;

    if (prev != NULL && next != NULL) {
        prev->next = next;
        next->prev = prev;
        free(var);
    } else if (prev == NULL && next != NULL) {
        *env_list = (*env_list)->next;
        next->prev = prev;
        free(var);
    }
    if (next == NULL && prev != NULL) {
        prev->next = NULL;
        free(var);
    }
    return;
}

void unset_env(linked_list_t **env_list, char **op_arg)
{
    linked_list_t *var;

    if (op_arg[1] == NULL && op_arg[2] == NULL) {
        my_putstr_error("unsetenv: Too few arguments.\n");
        return;
    }
    for (int i = 1; op_arg[i] != NULL; i++) {
        var = search_var(*env_list, op_arg[i]);
        if (var != NULL) {
            delet_env_var(var, env_list);
        }
    }
    return;
}