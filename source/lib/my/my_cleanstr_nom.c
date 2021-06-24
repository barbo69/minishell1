/*
** EPITECH PROJECT, 2021
** clean str
** File description:
** my_cleanstr
*/

#include "my.h"

void move_characters_in_str(char *str, int i, int compt)
{
    int temp = 0;

    for (int n = i; str[n] != '\0'; n++) {
        str[n - (compt - 1)] = str[n];
        str[n] = ' ';
    }
    return;
}

void compt_space(char *str, int *compt, int i, int *first_word_car)
{
    for (int n = i; str[n] == ' '; n++) {
        (*compt)++;
        *first_word_car = n;
    }
    return;
}

void clean_space(char *str)
{
    int compt = 0;
    int temp_compt = 0;
    int word_number = 0;
    int i = 0;
    int first_word_car = 0;

    while (str[i] != '\0') {
        compt_space(str, &compt, i, &first_word_car);
        if (compt > 1 && str[first_word_car + 1] != '\0') {
            word_number++;
            temp_compt = compt + temp_compt;
            move_characters_in_str(str, first_word_car, compt);
            i = 0;
        }
        i++;
        compt = 0;
    }
    str[(i - temp_compt) + word_number] = '\0';
    return;
}

void clean_final_space_nom(char *str)
{
    int len = my_strlen(str);
    int i = len;

    while (str[i - 1] == ' ') {
        i--;
    }
    str[i] = '\0';
    return;
}

char *my_cleanstr_nom(char *str)
{
    int i = 0;

    if (str[0] == '\0') {
        return (str);
    }
    while (str[i] == ' ') {
        i++;
    }
    clean_space(str + i);
    clean_final_space_nom(str);
    return (str);
}