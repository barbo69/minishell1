/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** put two strings in one
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int src_len = my_strlen(src);
    int dest_len = my_strlen(dest);
    int n = dest_len;

    for (int i = 0; src[i] != '\0'; i++) {
        dest[n] = src[i];
        n++;
    }
    dest[src_len + dest_len] = '\0';
    return (dest);
}
