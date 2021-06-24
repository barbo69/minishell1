/*
** EPITECH PROJECT, 2020
**  my_put_unsigned_int.c
** File description:
**  my_put_unsigned_int
*/

#include <stdlib.h>
#include "my.h"

void my_put_unsigned_int(unsigned int nbr)
{
    char *str = my_unsigned_int_to_char(nbr);

    my_putstr(str);
    free(str);
}
