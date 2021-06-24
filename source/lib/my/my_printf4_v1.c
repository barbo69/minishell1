/*
** EPITECH PROJECT, 2020
** my_printf4_v1.c
** File description:
** my_printf4_v1
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

int my_printf_arglencalc(va_list list, char car)
{
    va_list templist;
    int len = 0;
    char *tempstr;

    va_copy(templist, list);
    if (car == 's') {
        len = my_strlen(va_arg(templist, char *));
    }
    if (car == 'd') {
        tempstr = my_str_int_to_char(va_arg(templist, int));
        len = my_strlen(tempstr);
        free(tempstr);
    }
    if (car == 'x' || car == 'X') {
        tempstr = my_printf_decimal_to_base(templist, 16);
        len = my_strlen(tempstr);
        free(tempstr);
    }
    va_end(templist);
    return (len);
}

int my_printf_arglen(va_list list, char *s, int i)
{
    int itemp = i;
    char car = 0;
    int arglen;

    while (s[itemp] != '\0') {
        if ((s[itemp] >= 'a' && s[itemp] <= 'z') || (s[itemp] == 'S')) {
            car = s[itemp];
            break;
        }
        itemp++;
    }
    arglen = my_printf_arglencalc(list, car);
    return (arglen);
}

void my_printf_putwidth(int width, int e)
{
    while (width > 0) {
        if (e == 1)
            write(1, " ", 1);
        if (e == 2)
            write(1, "0", 1);
        width--;
    }
}

int my_printf_pourcent(char *s, int i, int *printemp)
{
    if (s[i] == '%') {
        i++;
        s = s + *printemp;
        write (1, s, i - *printemp);
        *printemp = i + 1;
    }
    return (i);
}

int my_printf_prec(char *s, int *i, int *prec, int width)
{
    int len = 0;
    int dec = 1;
    int e = 0;
    int arglen = *prec * (-1);

    if (s[*i + 1] == '.') {
        *i = *i + 2;
        e = my_printf_lenwidth(s, i);
        while (s[e] >= '0' && s[e] <= '9') {
            *prec = dec * (s[e] - 48);
            dec = dec * 10;
            e--;
        }
        width = width - *prec;
        *prec = *prec - arglen;
    }
    else
        width = width - arglen;
    *i = *i + 1;
    return (width);
}
