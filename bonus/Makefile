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
		src/ai.c	\
		src/new_ai.c	\
		src/ai_move.c	\
		src/score.c	\

OBJ	=	$(SRC:.c=.o)

MAKELIB =       make -C ../lib

NAME	=	tetris

CFLAGS	=	-Wall -Wextra -W -I./include -O3 -Ofast -march=native

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKELIB)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -L. ../lib/libmy.a -lncurses

clean:
	$(MAKELIB) clean
	rm -f $(OBJ)

fclean:	clean
	$(MAKELIB) fclean
	rm -f $(NAME)

re:	fclean all	
