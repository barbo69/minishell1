/*
** EPITECH PROJECT, 2020
** my_str_int_to_char.c
** File description:
** my_str_int_to_char
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void int_negcheck(int *nb, int *e, int *c, char *str)
{
    if (*nb < 0) {
        *nb = *nb * (-1);
        str[*c] = '-';
        *e = *e - 1;
        *c = *c + 1;
    }
}

int my_int_to_char_len(int nb)
{
    int i = 0;

    if (nb < 0) {
        nb = nb * (-1);
        i = 1;
    }
    if (nb == 0)
        return (1);
    while (nb > 0) {
        nb = nb /10;
        i++;
    }
    return (i);
}

char *my_int_to_char_convert(int nb)
{
    int e = my_int_to_char_len(nb);
    char *str = malloc(sizeof(int) * (e + 1));
    int p = 0;
    int c = 0;
    int temp = nb;

    int_negcheck(&nb, &e, &c, str);
    for (int i = e; i > 0; i--) {
        temp = nb;
        if (temp > 0) {
            p = my_compute_power_rec(10, i - 1);
            temp = temp / p;
            nb = nb - (p * temp);
        }
        str[c] = temp + 48;
        c++;
    }
    str[e] = '\0';
    return (str);
}

char *my_str_int_to_char(int nb)
{
    char *strd;

    if (nb <= -2147483648) {
        strd = malloc(sizeof(char) * 2);
        strd[0] = '0';
        strd[1] = '\0';
        return (strd);
    }
    else {
        return (my_int_to_char_convert(nb));
    }
}
