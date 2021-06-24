/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** echange deux variables
*/

#include <unistd.h>

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
