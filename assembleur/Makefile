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
		$(WAY)/assembleur.c	\
		$(WAY)/first_part/first_part.c	\
		$(WAY)/first_part/verify_file_name.c		\
		$(WAY)/first_part/create_new_file.c		\
		$(WAY)/first_part/open_create_file.c		\
		$(WAY)/first_part/field_header.c		\
		$(WAY)/second_part/second_part.c		\
		$(WAY)/second_part/choice_command.c		\
		$(WAY)/utilitaries/get_next_instruction.c	\
		$(WAY)/utilitaries/my_str_to_word_array.c	\
		$(WAY)/utilitaries/write_string.c		\
		$(WAY)/utilitaries/recuperate_string.c		\
		$(WAY)/utilitaries/syntax_instruction_is_valid.c		\

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
