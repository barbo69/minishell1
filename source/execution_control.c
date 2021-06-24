/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-baptiste.barbotin
** File description:
** execution_control
*/

#include "minishell.h"

int exit_process_check(int status)
{
    if (WIFSIGNALED(status)) {
        my_putstr_error(strsignal(WTERMSIG(status)));
        if (WCOREDUMP(status) > 0) {
            my_putstr_error(" (core dumped)");
            my_putstr_error("\n");
        }
        else
            my_putstr_error("\n");
    }
    return (0);
}

int execution(char **op_arg, char **env, char *path)
{
    pid_t processus = fork();
    int status = 0;

    if (processus == 0) {
        execve(path, op_arg, env);
        exit(0);
    }
    waitpid(processus, &status, WCONTINUED);
    exit_process_check(status);
    return (0);
}

char *path_access(char **op_arg, char *path)
{
    char *tmp = NULL;
    int len1 = my_strlen(op_arg[0]);
    int len2 = 0;
    int end = 0;
    char *final_path;

    while (end == 0) {
        (tmp == NULL) ? (tmp = strtok(path, ":")) : (tmp = strtok(NULL, ":"));
        if (tmp == NULL)
            break;
        len2 = my_strlen(tmp);
        final_path = malloc(sizeof(char) * (len1 + len2 + 10));
        my_strcpy(final_path, tmp);
        my_strcat(final_path, "/");
        my_strcat(final_path, op_arg[0]);
        if (access(final_path, F_OK) == 0)
            return (final_path);
        free(final_path);
    }
    return (NULL);
}

void path_handling(linked_list_t *path, char **op_arg, char **env)
{
    char *tmp_path = NULL;
    char *path_exec = NULL;

    tmp_path = malloc(sizeof(char) * (my_strlen(path->info)));
    my_strcpy(tmp_path, path->info);
    path_exec = path_access(op_arg, tmp_path + 5);
    if (path_exec != NULL) {
        execution(op_arg, env, path_exec);
        free(path_exec);
    } else {
        my_putstr_error(op_arg[0]);
        my_putstr_error(": Command not found.\n");
    }
    free(tmp_path);
}

void execution_control(char **op_arg, linked_list_t *env_list)
{
    linked_list_t *path = search_var(env_list, "PATH");
    char **env = env_list_to_env(env_list);
    struct stat buff;
    int s = stat(op_arg[0], &buff);

    if (path == NULL)
        return;
    if (access(op_arg[0], F_OK) == 0) {
         if (S_ISDIR(buff.st_mode) == 1) {
            my_putstr_error(op_arg[0]);
            my_putstr_error(": Permission denied.\n");
            return;
        }
            execution(op_arg, env, op_arg[0]);
    }
    if (access(op_arg[0], F_OK) != 0)
        path_handling(path, op_arg, env);
    return;
}