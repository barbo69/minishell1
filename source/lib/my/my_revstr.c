/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** revers a string
*/

char *my_revstr(char *str)
{
    int len = 0;
    int i = 0;
    char tmp = 0;

    while (str[len] != '\0') {
        len++;
    }
    while (i < len / 2) {
        tmp = str[i];
        str[i] = str [len - 1 - i];
        str [len - 1 - i] = tmp;
        i++;
    }
    return (str);
}
