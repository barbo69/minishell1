##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

SRC	=	source/prompt.c\
		source/shell_loop.c\
		source/shell_signal.c\
		source/environment.c\
		source/set_env.c\
		source/unset_env.c\
		source/linked_list.c\
		source/execution_control.c\
		source/cd_command.c\
		source/cd_command_back.c\
		source/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-I ./source/include

all: $(NAME)

$(NAME): $(OBJ)
	make -C source/lib/my/
	gcc $(OBJ) -Lsource/lib/my/ -lmy -o $(NAME)
clean:
	rm -f $(OBJ)
	make clean -C source/lib/my/

fclean: clean
	rm -f $(NAME)
	make fclean -C source/lib/my/

re: fclean all

perso: $(OBJ)
	@make re -C source/lib/my/
	gcc $(OBJ) -Lsource/lib/my/ -lmy -o $(NAME)

p: perso clean
	make clean -C source/lib/my/

fcp: fclean
	make fclean -C source/lib/my/

cp: clean
	make clean -C source/lib/my/

auteur:
	echo $(USER) > auteur
