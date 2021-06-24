/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-baptiste.barbotin
** File description:
** shell_loop
*/

#include "minishell.h"

linked_list_t *shell_init(char **env)
{
    linked_list_t *env_list = env_in_linked_list(env);

    shell_signal_control();
    return (env_list);
}

int shell_operating_pt2(char **op_arg, linked_list_t **env_list, char **old_pwd)
{
    if (my_strcompare(op_arg[0], "unsetenv")) {
        unset_env(env_list, op_arg);
        return (0);
    }
    if (my_strcompare(op_arg[0], "cd")) {
        cd_command(op_arg, *env_list, old_pwd);
        return (0);
    }
    execution_control(op_arg, *env_list);
    return (0);
}

int shell_operating(char **op_arg, int *end, linked_list_t **env_list,
                    char **old_pwd)
{
    if (my_strcompare(op_arg[0], "exit")) {
        *end = 1;
        return (0);
    }
    if (my_strcompare(op_arg[0], "env")) {
        put_env(*env_list);
        return (0);
    }
    if (my_strcompare(op_arg[0], "setenv")) {
        set_env(*env_list, op_arg);
        return (0);
    }
    shell_operating_pt2(op_arg, env_list, old_pwd);
    return (0);
}

int shell_loop_control(char **env)
{
    char **op_arg = NULL;
    char *old_pwd = NULL;
    int end = 0;
    int error = 0;
    linked_list_t *env_list;

    env_list = shell_init(env);
    while (end == 0) {
        op_arg = prompt_control(&error);
        if (op_arg != NULL)
            shell_operating(op_arg, &end, &env_list, &old_pwd);
        if (error == -1)
            end = 1;
    }
    return (0);
}