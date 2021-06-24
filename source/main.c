/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-baptiste.barbotin
** File description:
** main
*/

#include "minishell.h"

int main (int ac, char **av, char **env)
{
    ac = ac;
    av = av;
    shell_loop_control(env);
    return (0);
}