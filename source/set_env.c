/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-baptiste.barbotin
** File description:
** set_env
*/

#include "minishell.h"

void new_full_var(char *var_name, char *var_info, linked_list_t *first)
{
    int name_len = my_strlen(var_name);
    int info_len = my_strlen(var_info);

    first->next->info = malloc(sizeof(char) * (name_len + info_len + 2));
    my_strcpy(first->next->info, var_name);
    my_strcat(first->next->info, "=");
    my_strcat(first->next->info, var_info);
    return;
}

void new_env_var(linked_list_t *env_list, char *var_name, char *var_info)
{
    linked_list_t *first = env_list;
    int name_len = my_strlen(var_name);

    while (first->next != NULL) {
        first = first->next;
    }
    first->next = malloc(sizeof(linked_list_t));
    first->next->prev = first;
    first->next->next = NULL;
    if (var_info == NULL) {
        first->next->info = malloc(sizeof(char) * (name_len + 2));
        my_strcpy(first->next->info, var_name);
        my_strcat(first->next->info, "=");
        return;
    }
    new_full_var(var_name, var_info, first);
    return;
}

int var_len_check(linked_list_t *var)
{
    int len = 0;

    while (var->info[len] != '\0') {
        if (var->info[len] == '=')
            return (len + 1);
        len++;
    }
    return (len);
}

void modif_env_var(linked_list_t *var, char *var_info)
{
    int len = var_len_check(var);
    int info_len;
    char *tmp = NULL;

    var->info[len] = '\0';
    if (var_info == NULL)
        return;
    info_len = my_strlen(var_info);
    len = my_strlen(var->info);
    tmp = malloc(sizeof(char) * (len + info_len + 1));
    my_strcpy(tmp, var->info);
    my_strcat(tmp, var_info);
    free(var->info);
    var->info = tmp;
    return;
}

void set_env(linked_list_t *env_list, char **op_arg)
{
    linked_list_t *var;

    if (op_arg[1] == NULL && op_arg[2] == NULL)
        put_env(env_list);
    if (op_arg[1] != NULL && op_arg[2] == NULL) {
        var = search_var(env_list, op_arg[1]);
        if (var == NULL)
            new_env_var(env_list, op_arg[1], NULL);
        else
            modif_env_var(var, NULL);
        return;
    }
    if (op_arg[1] != NULL && op_arg[2] != NULL) {
        var = search_var(env_list, op_arg[1]);
        if (var == NULL)
            new_env_var(env_list, op_arg[1], op_arg[2]);
        else
            modif_env_var(var, op_arg[2]);
    }
    return;
}