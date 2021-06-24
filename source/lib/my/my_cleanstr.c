/*
** EPITECH PROJECT, 2021
** clean str
** File description:
** my_cleanstr
*/

#include "my.h"
#include <stdlib.h>

int skip_space(char *str, int i)
{
    while (str[i] == ' ') {
        i++;
    }
    return (i - 1);
}

int final_len_compt(char *str)
{
    int compt = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ')
            compt++;
        else {
            compt++;
            i = skip_space(str, i);
        }
    }
    return (compt + 1);
}

int my_clean_str_space(char *str, char *final_str, int i, int n)
{
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            final_str[n] = str[i];
            n++;
        }
        else {
            final_str[n] = str[i];
            n++;
            i = skip_space(str, i);
        }
        i++;
    }
    return (n);
}

char *my_clean_str(char *str)
{
    int final_len = final_len_compt(str);
    char *final_str = malloc(sizeof(char) * final_len);
    int n = 0;
    int i = 0;

    if (str[0] == ' ')
        i = skip_space(str, i) + 1;
    n = my_clean_str_space(str, final_str, i, n);
    if (final_str[n - 1] == ' ')
        final_str[n - 1] = '\0';
    else
        final_str[n] = '\0';
    return (final_str);
}