/*
** EPITECH PROJECT, 2020
** my_showstr.c
** File description:
** my_showstr.c
*/

#include <unistd.h>
#include "my.h"

int my_showstr(char const *str)
{
    char *strtemp;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 32 || str[i] >= 127) {
            write(1, "\\", 1);
            my_nbr_base(str[i], 8);
        }
        else {
            write(1, &str[i], 1);
        }
    return (0);
}
