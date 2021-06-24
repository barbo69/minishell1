/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** my_put_nbr
*/

#include <stdlib.h>
#include "my.h"

int my_put_nbr(int nb)
{
    char *str = my_str_int_to_char(nb);

    my_putstr(str);
    free(str);
}