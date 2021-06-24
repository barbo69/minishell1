/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** affiche une chaine de caractère
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    int len = my_strlen(str);

    write(1, str, len);
}
