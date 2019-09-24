##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Basic Makfile
##


SRC	=	src/main.c	\
		src/clock.c	\
		src/tetrimino.c	\
		src/add_tetrimino.c	\
		src/draw_point.c	\
		src/create_new_piece.c	\
		src/move.c	\
		src/core.c	\
		src/check_line.c	\
		src/stat.c	\
		src/check_loose.c	\
		src/sort_list.c	\
		src/get_control.c	\
		src/fill_tab_control.c	\
		src/fill_tab_control_fct.c	\
		src/displaydebug_mod.c  \
		src/displaydebug_mod_verif.c	\
		src/key_to_launch.c		\
		src/base_function.c     \
		src/event.c     \
		src/init_game.c	\

OBJ	=	$(SRC:.c=.o)

MAKELIB =       make -C lib

NAME	=	tetris

CFLAGS	=	-Wall -Wextra -W -I./include -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKELIB)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -L. lib/libmy.a -lncurses

clean:
	$(MAKELIB) clean
	rm -f $(OBJ)

fclean:	clean
	$(MAKELIB) fclean
	rm -f $(NAME)

re:	fclean all
