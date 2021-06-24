/*
** EPITECH PROJECT, 2020
** my_unsigned_int_to_char.c
** File description:
** my_unsigned_int_to_char
*/

#include <stdlib.h>

int my_unsigned_int_nbrdiv(unsigned int nbr)
{
    unsigned int nbrdiv = 0;

    for (unsigned int i = 1; nbr >= i; i = i * 10) {
        nbrdiv++;
    }
    return (nbrdiv);
}

unsigned int my_unsigned_int_power(int nbrdiv)
{
    unsigned int i = 1;

    for (int compt = 0; compt < nbrdiv - 1; compt++) {
        i = i * 10;
    }
    return (i);
}

char *my_unsigned_int_to_char(unsigned int nbr)
{
    unsigned int nbrtemp  = nbr;
    unsigned int outtest = nbr;
    int nbrdiv = my_unsigned_int_nbrdiv(nbr);
    char *str = malloc(sizeof(char) * (nbrdiv + 1));
    unsigned int i = my_unsigned_int_power(nbrdiv);
    char cartemp = 0;

    for (int compt = 0; compt <= (nbrdiv - 1); compt++) {
        cartemp = (nbrtemp / i) + 48;
        str[compt] = cartemp;
        nbrtemp = nbrtemp - (i * (cartemp - 48));
        i = i / 10;
    }
    return (str);
}
