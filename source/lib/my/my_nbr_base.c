/*
** EPITECH PROJECT, 2020
** my_nbr_base.c
** File description:
** my_nbr_base.c
*/

#include <unistd.h>

int my_put_zero(int i)
{
    int compt = 3 - i;
    int e = 0;

    while (e < compt) {
        write(1, "0", 1);
        e++;
    }
}

int my_number_of_div(int decvar, int base)
{
    int i = 0;

    while (decvar > 0) {
        decvar = decvar / base;
        i++;
    }
    return (i);
}

void my_base_check(int rest)
{
    char c = rest + 48;

    if (rest == 10)
        write(1, "a", 1);
    if (rest == 11)
        write(1, "b", 1);
    if (rest == 12)
        write(1, "c", 1);
    if (rest == 13)
        write(1, "d", 1);
    if (rest == 14)
        write(1, "e", 1);
    if (rest == 15)
        write(1, "f", 1);
    if (rest < 10)
        write(1, &c, 1);
    return;
}

void my_put_nbr_base(int temprest, int dec)
{
    int temp = 0;

    while (dec >= 10) {
        temp = temprest / 10;
        temprest = temprest - (dec * temp);
        my_base_check(temp);
        dec = dec / 10;
    }
    my_base_check(temprest % 10);
}

void my_nbr_base(int nbr, int base)
{
    int i = my_number_of_div(nbr, base);
    int rest = 0;
    int temprest = 0;
    int dec = 1;

    if (i == 0)
        write(1, "0", 1);
    for (int compt = 0; compt < i; compt++) {
        rest = nbr % base;
        temprest = (rest * dec) + temprest;
        dec = dec * 10;
        nbr = nbr / base;
    }
    my_put_zero(i);
    my_put_nbr_base(temprest, dec / 10);
    return;
}
