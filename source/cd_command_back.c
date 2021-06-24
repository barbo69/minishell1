/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-baptiste.barbotin
** File description:
** cd_command_back
*/

#include "minishell.h"

void go_back(linked_list_t *pwd, char **old_pwd)
{
    int len = 0;
    char *tmp = NULL;

    if (*old_pwd == NULL) {
        my_putstr_error(": No such file or directory.\n");
        return;
    }
    len = my_strlen(*old_pwd);
    tmp = malloc(sizeof(char) * (len + 1));
    my_strcpy(tmp, (*old_pwd) + 4);
    if (check_folder(tmp) == 1) {
        chdir(tmp);
        pwd->info = refresh_pwd(tmp, pwd, old_pwd);
    }
}