/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** toto
*/

char const *get_nbr_check(char const *str)
{
    if ((str[0] < '0' || str[0] > '9') && (str[0] != '-'))
        return ("0");
    return (str);
}

int ne_compt(char const *str, int *e, int necompt)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-')
            necompt = necompt * -1;
        if (str[i] >= '0' && str[i] <= '9')
            break;
        *e = *e + 1;
    }
    return (necompt);
}

int my_getnbr(char const *str)
{
    int necompt = 1;
    char temp = '0';
    int nbr = 0;
    int e = 0;

    str = get_nbr_check(str);
    necompt = ne_compt(str, &e, necompt);
    for (int i = e; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            break;
        temp = str[i];
        nbr = nbr * 10;
        nbr = nbr + (temp - 48);
    }
    return (nbr * necompt);
}
