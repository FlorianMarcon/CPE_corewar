##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## corewar
##

CC	=	gcc

WAY	=	../src

SRC	=	$(WAY)/op.c					\
		$(WAY)/create_new_file/verify_file_name.c	\
		$(WAY)/create_new_file/create_new_file.c	\
		$(WAY)/is_variable/is_registre.c		\
		$(WAY)/is_variable/is_label.c			\
		$(WAY)/is_variable/is_direct.c			\
		$(WAY)/is_variable/is_indirect.c		\
		$(WAY)/is_variable/which_variable.c		\
		$(WAY)/verification/verification_argument.c	\
		$(WAY)/verification/verification_instruction.c	\
		$(WAY)/verification/verification_file.c		\
		$(WAY)/verification/verification_name_and_comment.c	\
		$(WAY)/utilitaries/syntax_instruction_is_valid.c	\
		$(WAY)/utilitaries/len_tab.c			\
		$(WAY)/utilitaries/recuperate_string.c		\
		$(WAY)/utilitaries/parsing_str.c		\
		$(WAY)/utilitaries/get_next_instruction.c	\
		$(WAY)/utilitaries/search_function.c		\
		$(WAY)/utilitaries/save_label.c			\
		$(WAY)/utilitaries/my_strndup.c			\

SRC_UT	=	is_variable/tests_utils.c			\
		is_variable/tests_utils_second.c		\
		utilitaries/create_new_file/tests_utils.c	\
		utilitaries/instruction_is_valid/tests_utils.c	\
		utilitaries/recuperate_string/tests_utils.c	\
		utilitaries/parsing_str/tests_utils.c	\
		utilitaries/verify_file_name/tests_utils.c	\
		utilitaries/len_tab/tests_utils.c		\
		utilitaries/search_function/tests_utils.c	\
		utilitaries/save_label/tests_utils.c		\
		utilitaries/my_strndup/tests_utils.c		\
		verification/tests_utils.c			\
		verification/tests_utils_second.c		\

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
