/*
** EPITECH PROJECT, 2020
** my_printf_v1.c
** File description:
** my_printf_v1.c
*/

#include <stdarg.h>
#include <unistd.h>
#include "my.h"

int my_printf_space(char *s, int i, va_list list)
{
    int nbr = 0;
    int nbr2 = 0;
    va_list templist;

    va_copy(templist, list);
    if (s[i + 1] == 'd' || s[i + 1] == 'i') {
        if (va_arg(templist, int) > 0)
            write(1, " ", 1);
    }
    va_end(templist);
    return (i + 1);
}

int my_printf_add(char *s, int i, va_list list)
{
    int nbr = 0;
    int nbr2 = 0;
    va_list templist;

    va_copy(templist, list);
    if (s[i + 1] == 'd') {
        if (va_arg(templist, int) > 0)
            write(1, "+", 1);
    }
    va_end(templist);
    return (i + 1);
}

int my_printf_hashtag(char *s, int i, va_list list)
{
    int nbr = 0;
    int nbr2 = 0;
    va_list templist;

    va_copy(templist, list);
    if (va_arg(templist, int) == 0) {
        va_end(templist);
        return (i + 1);
    }
    if (s[i + 1] == 'x')
        my_putstr("0x");
    if (s[i + 1] == 'X')
        my_putstr("0X");
    if (s[i + 1] == 'o')
        write(1, "0", 1);
    va_end(templist);
    return (i + 1);
}

int my_printf_indicator(char *s, int i, va_list list)
{
    if (s[i] == '+') {
        i = my_printf_add(s, i, list);
    }
    if (s[i] == ' ') {
        i = my_printf_space(s, i, list);
    }
    if (s[i] == '#') {
        i = my_printf_hashtag(s, i, list);
    }
    return (i);
}

int my_printf_width(char *s, int i, va_list list)
{
    int len = 0;
    int dec = 1;
    int width = 0;
    int prec = 0;
    int arglen;

    if ((s[i] < '0' || s[i] > '9') && s[i] != '.')
        return (i);
    arglen = my_printf_arglen(list, s, i);
    my_printf_get_width(s, &width, &i);
    prec = prec - arglen;
    width = my_printf_prec(s, &i, &prec, width);
    my_printf_putwidth(width, 1);
    my_printf_putwidth(prec, 2);
    return (i);
}
