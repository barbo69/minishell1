/*
** EPITECH PROJECT, 2020
** my_printf_v1.c
** File description:
** my_printf_v1
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int my_printf_string_check(char *s, int i, int printtemp)
{
    if (i > 0) {
        s = s + printtemp;
        write(1, s, (i - printtemp));
    }
    return (i + 1);
}

void my_printf_type_variable_check_sp(char *s, int i, va_list list)
{
    if (s[i] == 'c')
        my_putchar(va_arg(list, int));
    if (s[i] == 's')
        my_putstr(va_arg(list, char *));
    if (s[i] == 'p')
        my_printf_base_control(list, 2, 16);
    if (s[i] == 'x')
        my_printf_base_control(list, 1, 16);
    if (s[i] == 'X')
        my_printf_base_control(list, 3, 16);
    if (s[i] == 'b')
        my_printf_base_control(list, 1, 2);
    return;
}

void my_printf_type_variable_check_fp(char *s, int i, va_list list)
{
    if (s[i] == 'd')
        my_put_nbr(va_arg(list, int));
    if (s[i] == 'i')
        my_put_nbr(va_arg(list, int));
    if (s[i] == 'u')
        my_put_unsigned_int(va_arg(list, unsigned int));
    if (s[i] == 'S')
        my_showstr(va_arg(list, char *));
    if (s[i] == 'o')
        my_printf_base_control(list, 1, 8);
    return;
}

void my_printf_control(char *s, va_list list)
{
    int printtemp = 0;
    int printtime = 0;
    int i = 0;

    while (s[i] != '\0') {
        if (s[i] == '%' && s[i + 1] != '%') {
            i = my_printf_string_check(s, i, printtemp);
            i = my_printf_indicator(s, i, list);
            i = my_printf_width(s, i, list);
            my_printf_type_variable_check_fp(s, i, list);
            my_printf_type_variable_check_sp(s, i, list);
            printtemp = i + 1;
        }
        i = my_printf_pourcent(s, i, &printtemp);
        i++;
    }
    my_printf_string_check(s, i, printtemp);
}

int my_printf(char *str, ...)
{
    va_list list;

    va_start(list, str);
    my_printf_control(str, list);
    va_end(list);
    return (0);
}
