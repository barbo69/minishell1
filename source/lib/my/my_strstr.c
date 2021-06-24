/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** reproduce str str
*/

#include <stddef.h>

int my_strlenfind(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char *test(char *str, int len, int i, int n)
{
    if (n == len) {
        return (&str[i - (len - 1)]);
    }
    else {
        return (NULL);
    }
}

char *my_strstr(char *str, char const *to_find)
{
    int out = 0;
    int i = 0;
    int e = 0;
    int len = my_strlenfind(to_find);
    int n = 0;

    while ((str[i] != '\0') && (out == 0)) {
        if (n == len)
            out++;
        if (str[i] != to_find[e]) {
            e = e - n;
            n = 0;
        }
        if (str[i] == to_find[e]) {
            n++;
            e++;
        }
        i++;
    }
    return (test(str, len, i, n));
}
