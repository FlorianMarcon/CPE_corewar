##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## corewar
##

CC	=	gcc

WAY	=	./src

SRC	=	$(WAY)/main.c	\
		$(WAY)/create_champion/create_champion.c	\
		$(WAY)/create_champion/create_list_champion.c	\
		$(WAY)/create_corewar/set_memory.c		\
		$(WAY)/create_corewar/set_virgil_corewar.c	\
		$(WAY)/create_corewar/create_corewar.c	\
		$(WAY)/create_corewar/set_dump.c	\
		$(WAY)/basic_loop_game/basic_loop_game.c	\
		$(WAY)/basic_loop_game/is_end.c	\
		$(WAY)/basic_loop_game/destroy_dead_champion.c	\
		$(WAY)/basic_loop_game/up_cycle.c	\
		$(WAY)/basic_loop_game/up_cycle_to_die.c	\
		$(WAY)/basic_loop_game/evolve_game.c	\
		$(WAY)/utilitaries/little_to_big_endian.c	\
		$(WAY)/utilitaries/get_opcode_byte.c	\
		$(WAY)/utilitaries/my_tabcat.c	\
		$(WAY)/utilitaries/op.c	\
		$(WAY)/utilitaries/write_integer.c	\
		$(WAY)/utilitaries/load_variable.c	\
		$(WAY)/utilitaries/decoding_byte.c	\
		$(WAY)/utilitaries/load_value_by_type.c	\
		$(WAY)/utilitaries/display_dump.c	\
		$(WAY)/utilitaries/convert_deci_to_hexa.c	\
		$(WAY)/utilitaries/fill_graph_memory.c	\
		$(WAY)/instruction/live_instruction.c	\
		$(WAY)/instruction/zjmp_instruction.c	\
		$(WAY)/instruction/ld_instruction.c	\
		$(WAY)/instruction/lld_instruction.c	\
		$(WAY)/instruction/sti_instruction.c	\
		$(WAY)/instruction/st_instruction.c	\
		$(WAY)/instruction/fork_instruction.c	\
		$(WAY)/instruction/lfork_instruction.c	\
		$(WAY)/instruction/add_instruction.c	\
		$(WAY)/instruction/sub_instruction.c	\
		$(WAY)/instruction/and_instruction.c	\
		$(WAY)/instruction/or_instruction.c	\
		$(WAY)/instruction/xor_instruction.c	\
		$(WAY)/instruction/ldi_instruction.c	\
		$(WAY)/instruction/lldi_instruction.c	\
		$(WAY)/instruction/aff_instruction.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -g3 -I../include

WAY_LIB	=	../lib/my

WAY_TST	=	tests

LIB	=	-L$(WAY_LIB) -lmy

NAME	=	corewar

all:	$(OBJ)
	make -C./$(WAY_LIB)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

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
