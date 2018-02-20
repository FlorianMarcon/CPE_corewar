##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## corewar
##

CC	=	gcc

WAY	=	../src

SRC	=	$(WAY)/first_part/verify_file_name.c	\
		$(WAY)/utilitaries/my_str_to_word_array.c	\
		$(WAY)/utilitaries/syntax_instruction_is_valid.c	\
		$(WAY)/utilitaries/recuperate_string.c		\
		$(WAY)/first_part/create_new_file.c		\
		$(WAY)/first_part/open_create_file.c		\
		$(WAY)/first_part/field_header.c		\

SRC_UT	=	first_part/tests_utils.c	\
		first_part/tests_utils_second.c	\
		utilitaries/tests_utils.c	\
		utilitaries/instruction_is_valid/tests_utils.c	\
		utilitaries/recuperate_string/tests_utils.c	\

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

fclean:	clean
	$(RM) $(NAME)

re:	clean all
