##
## EPITECH PROJECT, 2020
## make_file
## File description:
## make_file
##

SRC	=	my_getnbr.c \
		my_put_nbr.c \
		my_revstr.c \
		my_strcpy.c \
		my_strlen.c \
		my_strncpy.c \
		my_str_to_word_array.c \
		my_compute_power_rec.c \
		my_putchar.c \
		my_putstr.c \
		my_putstr_error.c \
		my_strcat.c \
		my_str_int_to_char.c \
		my_strlowcase.c \
		my_strstr.c \
		my_printf_v1.c \
		my_printf2_v1.c \
		my_printf3_v1.c \
		my_printf4_v1.c \
		my_printf5_v1.c \
		my_nbr_base.c \
		my_showstr.c \
		my_strupcase.c \
		my_put_unsigned_int.c \
		my_unsigned_int_to_char.c \
		my_cleanstr_nom.c \
		my_cleanstr.c \
		my_strcompare.c\
		my_strncompare.c\
		my_swap.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-I ../../include

all:	$(NAME)

$(NAME):
	@gcc -c $(SRC) $(CFLAGS)
	@ar rc $(NAME) $(OBJ)
clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f ../../$(NAME) $(NAME)

re: 	fclean all

auteur:
	echo $(USER) > auteur

%.o: %.c
	@gcc -c $< $(CFLAGS)
