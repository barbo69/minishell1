/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** yop
*/

int my_compute_power_rec(int nb, int p)
{
    int result;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    result = my_compute_power_rec(nb, p - 1);
    return (result * nb);
}
