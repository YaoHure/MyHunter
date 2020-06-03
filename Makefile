##
## EPITECH PROJECT, 2018
## Huré Yaowanart
## File description:
## Makefile
##

SRC	=	./src/main.c   					\
		./src/game.c					\
		./src/destroy.c					\
		./src/my_first_int_len.c 		\
		./src/my_itoa.c					\
		./src/my_revstr.c				\
		./src/mouse.c					\
		./src/my_duck.c					\
		./src/display_text.c			\
		./src/my_strcmp.c				\
		./src/my_putstr.c				\
		./src/my_strlen.c

OBJ	= $(SRC:.c=.o)

CFLAGS = -W -Wall -Wextra

CGRAPH = -l csfml-graphics -l csfml-window -l csfml-system

all:
		gcc $(SRC) -o my_hunter $(CGRAPH) $(CFLAGS)
clean:
		rm -f $(OBJ) *~

fclean:	clean
		rm -f $(NAME)

re:		fclean all
