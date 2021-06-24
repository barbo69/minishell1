/*
** EPITECH PROJECT, 2020
** my_printf2_v1.c
** File description:
** my_printf2_v1
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

void my_printf_base_check(long rest, char *result, int i)
{
    if (rest == 10)
        result[i] = 'a';
    if (rest == 11)
        result[i] = 'b';
    if (rest == 12)
        result[i] = 'c';
    if (rest == 13)
        result[i] = 'd';
    if (rest == 14)
        result[i] = 'e';
    if (rest == 15)
        result[i] = 'f';
    if (rest < 10)
        result[i] = rest + 48;
    return;
}

int my_printf_number_of_div(long decvar, int base)
{
    int i = 0;

    while (decvar > 0) {
        decvar = decvar / base;
        i++;
    }
    return (i);
}

char *my_printf_decimal_to_base(va_list list, int base)
{
    void *test = va_arg(list, void *);
    long decvar = (long) test;
    int i = my_printf_number_of_div(decvar, base);
    char *result = malloc(sizeof(char) * (i + 1));
    long rest = 0;

    if (i == 0)
        result[0] = '0';
    while (i > 0) {
        rest = decvar % base;
        my_printf_base_check(rest, result, (i - 1));
        decvar = decvar / base;
        i--;
    }
    return (result);
}

void my_printf_base_control(va_list list, int i, int base)
{
    char *result = my_printf_decimal_to_base(list, base);

    if (i == 1) {
        my_putstr(result);
    }
    if (i == 2) {
        my_putstr("0x");
        my_putstr(result);
    }
    if (i == 3) {
        result = my_strupcase(result);
        my_putstr(result);
    }
    free(result);
    return;
}
