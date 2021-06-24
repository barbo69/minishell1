/*
** EPITECH PROJECT, 2020
** my_putstr_error.c
** File description:
** put str for error handling
*/

#include <unistd.h>
#include "my.h"

int my_putstr_error(char const *str)
{
    int len = my_strlen(str);

    write(2, str, len);
}
