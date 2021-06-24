/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-baptiste.barbotin
** File description:
** cd_command
*/

#include "minishell.h"

int check_folder(char *path)
{
    struct stat *buf = malloc(sizeof(struct stat));

    stat(path, buf);
    if (access(path, F_OK) == 0) {
        if (S_ISDIR(buf->st_mode)) {
            free(buf);
            return (1);
        }
        free(buf);
        my_putstr_error(path);
        my_putstr_error(": Not a directory.\n");
        return (0);
    }
    free(buf);
    my_putstr_error(path);
    my_putstr_error(": No such file or directory.\n");
    return (0);
}

char *refresh_pwd(char *op_arg, linked_list_t *pwd, char **old_pwd)
{
    int pwd_len = 0;
    int len = 0;
    char *tmp = NULL;

    len = my_strlen(op_arg);
    pwd_len = my_strlen(pwd->info);
    if (*old_pwd != NULL)
        free(*old_pwd);
    *old_pwd = pwd->info;
    pwd->info = NULL;
    pwd->info = getcwd(op_arg, (pwd_len + len + 1));
    pwd_len = my_strlen(pwd->info);
    tmp = malloc(sizeof(char) * (pwd_len + 4));
    my_strcat(tmp, "PWD=");
    my_strcat(tmp, pwd->info);
    pwd->info = tmp;
    return (pwd->info);
}

char *home_path_copy(linked_list_t *env_list)
{
    linked_list_t *home = search_var(env_list, "HOME");
    int len;
    char *home_path;

    if (home == NULL)
        return (NULL);
    len = my_strlen(home->info);
    home_path = malloc(sizeof(char) * len - 4);
    my_strcpy(home_path, home->info + 5);
    if (check_folder(home_path) == 1)
        return (home_path);
    else {
        free(home_path);
        return (NULL);
    }
}

void return_home(linked_list_t *env_list, linked_list_t *pwd, char **old_pwd)
{
    char *home_path = NULL;

    home_path = home_path_copy(env_list);
    if (home_path != NULL) {
        chdir(home_path);
        pwd->info = refresh_pwd(home_path, pwd, old_pwd);
        free(home_path);
    }
    return;
}

int cd_command(char **op_arg, linked_list_t *env_list, char **old_pwd)
{
    linked_list_t *pwd = search_var(env_list, "PWD");

    if (op_arg[1] != NULL && pwd != NULL) {
        if (my_strcompare(op_arg[1], "~") == 1) {
            return_home(env_list, pwd, old_pwd);
            return (0);
        }
        if (my_strcompare(op_arg[1], "-") == 1) {
            go_back(pwd, old_pwd);
            return (0);
        }
        if (check_folder(op_arg[1]) == 1) {
            chdir(op_arg[1]);
            pwd->info = refresh_pwd(op_arg[1], pwd, old_pwd);
        }
    }
    if (op_arg[1] == NULL && pwd != NULL)
        return_home(env_list, pwd, old_pwd);
    return (0);
}