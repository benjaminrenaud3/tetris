##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Basic Makfile
##

SRC	=	printf.c	\
		printf_fonction.c	\
		get_next_line.c	\
		my_getnbr.c	\
		my_strlen.c	\
		my_str_to_word_array.c	\
		my_strcat.c	\
		my_strtol.c	\
		my_tab_len.c	\
                my_strdup.c	\
		my_strcmp.c	\


OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-Wall -Wextra -W

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all
