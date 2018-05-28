##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## corewar
##

CC	=	gcc

WAY	=	./src

SRC	=	$(WAY)/main.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -g3

WAY_LIB	=	./lib/my

WAY_ASM	=	./asm/

WAY_VM	=	./corewar/

WAY_TST_ASM	=	./$(WAY_ASM)/tests/

WAY_TST_VM	=	./$(WAY_VM)/tests/

LIB	=	-L$(WAY_LIB) -lmy

all:
	make -C./$(WAY_ASM)
	make -C./$(WAY_VM)

clean:
	make clean -C./$(WAY_LIB)
	make clean -C./$(WAY_ASM)
	make clean -C./$(WAY_VM)

fclean:	clean
	make fclean -C./$(WAY_LIB)
	make fclean -C./$(WAY_ASM)
	make fclean -C./$(WAY_VM)

re:	clean all

tests_run:
	make -C./$(WAY_TST_ASM)
	make -C./$(WAY_TST_VM)
