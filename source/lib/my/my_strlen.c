/*
** EPITECH PROJECT, 2020
** mr_strlen
** File description:
** affiche des nombres
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
        return (i);
}
