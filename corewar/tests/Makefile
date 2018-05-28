##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## corewar
##

CC	=	gcc

WAY	=	../src

SRC	=	$(WAY)/create_champion/create_champion.c	\
		$(WAY)/create_champion/create_list_champion.c	\
		$(WAY)/create_corewar/set_memory.c		\
		$(WAY)/create_corewar/set_virgil_corewar.c	\
		$(WAY)/create_corewar/create_corewar.c	\
		$(WAY)/create_corewar/set_dump.c	\
		$(WAY)/utilitaries/little_to_big_endian.c	\
		$(WAY)/utilitaries/my_tabcat.c	\
		$(WAY)/utilitaries/convert_deci_to_hexa.c	\

SRC_UT	=	create_champion/create_champion/tests_utils.c	\
		create_champion/create_list_champion/tests_utils.c	\
		create_corewar/set_memory/tests_utils.c	\
		create_corewar/set_virgil_corewar/tests_utils.c	\
		create_corewar/set_dump/tests_utils.c	\
		create_corewar/create_corewar/tests_utils.c	\
		utilitaries/my_tabcat/tests_utils.c	\
		utilitaries/convert_deci_to_hexa/tests_utils.c	\

OBJ	=	$(SRC:.c=.o)

OBJ_UT	=	$(SRC_UT:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -g3 --coverage -I../../include

LDFLAGS	=	-lcriterion -lgcov

WAY_LIB	=	../../lib/my

LIB	=	-L$(WAY_LIB) -lmy

NAME	=	units

RM	=	rm -rf

all:	$(OBJ) $(OBJ_UT)
	make -C./$(WAY_LIB)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_UT) $(LIB) $(LDFLAGS)
	./$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_UT)
	$(RM) $(OBJ:.o=.gcda)
	$(RM) $(OBJ:.o=.gcno)
	$(RM) $(OBJ_UT:.o=.gcda)
	$(RM) $(OBJ_UT:.o=.gcno)
	$(RM) a.cor
fclean:	clean
	$(RM) $(NAME)

re:	clean all
