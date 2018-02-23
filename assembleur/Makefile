##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## corewar
##

CC	=	gcc

WAY	=	./src

SRC	=	$(WAY)/main.c		\
		$(WAY)/op.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -g3 -I../include

WAY_LIB	=	../lib/my

WAY_TST	=	tests

LIB	=	-L$(WAY_LIB) -lmy

NAME	=	asm

all:	$(OBJ)
	make -C./$(WAY_LIB)
	$(CC) -o $(NAME) $(OBJ) $(LIB)
	cp $(NAME) ../

clean:
	make clean -C./$(WAY_LIB)
	$(RM) $(OBJ)
	make clean -C./$(WAY_TST)

fclean:	clean
	make fclean -C./$(WAY_LIB)
	$(RM) $(NAME)
	make fclean -C./$(WAY_TST)

re:	clean all

tests_run:
	make -C./$(WAY_TST)
