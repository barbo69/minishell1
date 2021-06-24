/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** copie a string
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int e = 0;

    while (src[e] != '\0')
        e++;
    while (i < n) {
        dest[i] = src[i];
        i++;
    }
    if (n > e)
        dest[i] = '\0';
    return (dest);
}
