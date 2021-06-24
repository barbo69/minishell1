/*
** EPITECH PROJECT, 2020
** my_
** File description:
** my_
*/

#ifndef MY_H
#define MY_H

#include <stdarg.h>
int my_compute_power_rec(int nb, int p);
char const *get_nbr_check(char const *str);
int my_getnbr(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_putstr_error(char const *str);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
void int_negcheck(int *nb, int *e, int *c, char *str);
int my_int_to_char_len(int nb);
char *my_int_to_char_convert(int nb);
char *my_str_int_to_char(int nb);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncpy(char *dest, char const *src, int n);
int my_strlenfind(char const *str);
char *test(char *str, int len, int i, int n);
char *my_strstr(char *str, char const *to_find);
int space_test(char const str);
int lenfinstr(char const *str);
char **malocword(char const *str, int e, int i, int temp);
char **my_str_to_word_array(char const *str);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_unsigned_int_nbrdiv(unsigned int nbr);
unsigned int my_unsigned_int_power(int nbrdiv);
char *my_unsigned_int_to_char(unsigned int nbr);
void my_put_unsigned_int(unsigned int nbr);
int my_number_of_div(int decvar, int base);
int my_put_zero(int i);
void my_base_check(int rest);
void my_put_nbr_base(int temprest, int dec);
void my_nbr_base(int nbr, int base);
int my_showstr(char const *str);
int my_printf_string_check(char *s, int i, int printtemp);
void my_printf_type_variable_check_sp(char *s, int i, va_list list);
void my_printf_type_variable_check_fp(char *s, int i, va_list list);
void my_printf_control(char *s, va_list list);
int my_printf(char *str, ...);
void my_printf_base_check(long rest, char *result, int i);
int my_printf_number_of_div(long decvar, int base);
char *my_printf_decimal_to_base(va_list list, int base);
void my_printf_base_control(va_list list, int i, int base);
int my_printf_space(char *s, int i, va_list list);
int my_printf_add(char *s, int i, va_list list);
int my_printf_hashtag(char *s, int i, va_list list);
int my_printf_indicator(char *s, int i, va_list list);
int my_printf_width(char *s, int i, va_list list);
void my_printf_putwidth(int width, int e);
int my_printf_pourcent(char *s, int i, int *printemp);
int my_printf_prec(char *s, int *i, int *prec, int width);
int my_printf_arglencalc(va_list list, char car);
int my_printf_arglen(va_list list, char *s, int i);
int my_printf_lenwidth(char *s, int *i);
void my_printf_get_width(char *s, int *width, int *i);
char *my_cleanstr_nom(char *str);
char *my_clean_str(char *str);
int my_strcompare(char *fstr, char *sstr);
int my_strncompare(char *fstr, char *sstr, int n);

#endif /* MY_H */