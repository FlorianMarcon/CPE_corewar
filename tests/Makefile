##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## corewar
##

CC	=	gcc

WAY	=	../src

SRC	=	$(WAY)/main.c		\

SRC_UT	=

OBJ	=	$(SRC:.c=.o)

OBJ_UT	=

CFLAGS	=	-W -Wall -Wextra -Werror -g3 --coverage

LDFLAGS	=	-lcriterion -lgcov

WAY_LIB	=	./lib/my

WAY_TST	=	./tests

LIB	=	-L$(WAY_LIB) -lmy

NAME	=	units

all:	$(OBJ)
	make -C./$(WAY_LIB)
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(LDFLAGS)

clean:
	make clean -C./$(WAY_LIB)
	make clean -C./$(WAY_TST)
	$(RM) $(OBJ)

fclean:	clean
	make fclean -C./$(WAY_LIB)
	make fclean -C./$(WAY_TST)
	$(RM) $(NAME)

re:	clean all

tests_run:
	make -C./$(WAY_TST)
