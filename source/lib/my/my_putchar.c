/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** fonction pour afficher
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
    return;
}
