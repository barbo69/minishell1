/*
** EPITECH PROJECT, 2020
** my_print5_v1.c
** File description:
** my_print5_v1
*/

int my_printf_lenwidth(char *s, int *i)
{
    while (s[*i + 1] >= '0' && s[*i + 1] <= '9') {
        *i = *i + 1;
    }
    return (*i);
}

void my_printf_get_width(char *s, int *width, int *i)
{
    int e;
    int dec = 1;

    if (s[*i] == '.') {
        *i = *i - 1;
        return;
    }
    e = my_printf_lenwidth(s, i);
    while (s[e] >= '0' && s[e] <= '9') {
        *width = dec * (s[e] - 48);
        dec = dec * 10;
        e--;
    }
    return;
}
