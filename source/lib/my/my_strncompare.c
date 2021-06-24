/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-baptiste.barbotin
** File description:
** my_strncompare
*/

int my_strncompare(char *fstr, char *sstr, int n)
{
    for (int i = 0; i < n; i++) {
        if (fstr[i] != sstr[i])
            return (0);
    }
    return (1);
}