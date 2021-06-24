/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include "my.h"

int space_test(char const str)
{
    if ((str >= 'a' && str <= 'z') ||
        (str >= 'A' && str <= 'Z') ||
        (str >= '0' && str <= '9'))
        return (0);
    return (1);
}

int lenfinstr(char const *str)
{
    int i = 0;
    int lentab = 0;

    while (str[i] != '\0') {
        if (space_test(str[i])) {
            lentab++;
        }
        i++;
    }
    return (lentab + 1);
}

char **malocword(char const *str, int e, int i, int temp)
{
    int lentab = lenfinstr(str);
    char **tabptr;

    tabptr = malloc(sizeof(char *) * lentab);
    for (; str[i] && space_test(str[i]); i++, temp++);
    for (; e < lentab && str[i]; i++) {
        if (space_test(str[i]) == 1 &&
            (space_test(str[i + 1]) == 0 || !str[i + 1])) {
            tabptr[e] = malloc(sizeof(char) * (i - temp));
            my_strncpy(tabptr[e], &str[temp], (i - temp));
            e++;
            for (; str[i] && space_test(str[i]); i++);
            i--;
            temp = i + 1;
        }
    }
    if (i > 0 && !space_test(str[i - 1]))
        e++;
    tabptr[e] = NULL;
    return (tabptr);
}

char **my_str_to_word_array(char const *str)
{
    return (malocword(str, 0, 0, 0));
}
