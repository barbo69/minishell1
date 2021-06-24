/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-baptiste.barbotin
** File description:
** my_strcompare
*/

#include "my.h"

int my_strcompare(char *fstr, char *sstr)
{
    int flen = my_strlen(fstr);
    int slen = my_strlen(sstr);

    if (flen != slen)
        return (0);
    for (int i = 0; fstr[i] != 0; i++) {
        if (fstr[i] != sstr[i])
            return (0);
    }
    return (1);
}