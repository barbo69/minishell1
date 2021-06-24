/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-baptiste.barbotin
** File description:
** shell_signal
*/

#include "minishell.h"

void sigint_control(int sig)
{
    sig = sig;
    my_putchar('\n');
    my_putchar('\0');
    my_putstr("\e[95m->\e[0m");
    return;
}

void shell_signal_control(void)
{
    signal(SIGINT, sigint_control);
    return;
}