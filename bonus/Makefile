##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## corewar
##

CC	=	gcc

WAY	=	./src

WAY_COR	=	../corewar/src

SRC	=	$(WAY)/main.c	\
		$(WAY)/loop_game_graphique.c			\
		$(WAY)/set/set_bonus.c			\
		$(WAY)/set/set_caracteristique.c			\
		$(WAY)/set/set_name_champion.c			\
		$(WAY)/event.c			\
		$(WAY)/transform_integer_in_str.c			\
		$(WAY)/display.c			\
		$(WAY)/update_all.c			\
		$(WAY)/destroy_dead_champion_graph.c			\
		$(WAY_COR)/create_champion/create_champion.c	\
		$(WAY_COR)/create_champion/create_list_champion.c	\
		$(WAY_COR)/create_corewar/set_memory.c		\
		$(WAY_COR)/create_corewar/set_virgil_corewar.c	\
		$(WAY_COR)/create_corewar/create_corewar.c	\
		$(WAY_COR)/create_corewar/set_dump.c	\
		$(WAY_COR)/basic_loop_game/basic_loop_game.c	\
		$(WAY_COR)/basic_loop_game/is_end.c	\
		$(WAY_COR)/basic_loop_game/destroy_dead_champion.c	\
		$(WAY_COR)/basic_loop_game/up_cycle.c	\
		$(WAY_COR)/basic_loop_game/up_cycle_to_die.c	\
		$(WAY_COR)/basic_loop_game/evolve_game.c	\
		$(WAY_COR)/utilitaries/little_to_big_endian.c	\
		$(WAY_COR)/utilitaries/get_opcode_byte.c	\
		$(WAY_COR)/utilitaries/my_tabcat.c	\
		$(WAY_COR)/utilitaries/op.c	\
		$(WAY_COR)/utilitaries/write_integer.c	\
		$(WAY_COR)/utilitaries/load_variable.c	\
		$(WAY_COR)/utilitaries/decoding_byte.c	\
		$(WAY_COR)/utilitaries/load_value_by_type.c	\
		$(WAY_COR)/utilitaries/display_dump.c	\
		$(WAY_COR)/utilitaries/convert_deci_to_hexa.c	\
		$(WAY_COR)/utilitaries/fill_graph_memory.c	\
		$(WAY_COR)/instruction/live_instruction.c	\
		$(WAY_COR)/instruction/zjmp_instruction.c	\
		$(WAY_COR)/instruction/ld_instruction.c	\
		$(WAY_COR)/instruction/lld_instruction.c	\
		$(WAY_COR)/instruction/sti_instruction.c	\
		$(WAY_COR)/instruction/st_instruction.c	\
		$(WAY_COR)/instruction/fork_instruction.c	\
		$(WAY_COR)/instruction/lfork_instruction.c	\
		$(WAY_COR)/instruction/add_instruction.c	\
		$(WAY_COR)/instruction/sub_instruction.c	\
		$(WAY_COR)/instruction/and_instruction.c	\
		$(WAY_COR)/instruction/or_instruction.c	\
		$(WAY_COR)/instruction/xor_instruction.c	\
		$(WAY_COR)/instruction/ldi_instruction.c	\
		$(WAY_COR)/instruction/lldi_instruction.c	\
		$(WAY_COR)/instruction/aff_instruction.c	\


OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -g3 -I../include

LDFLAGS_ME	=	-lcsfml-system -lcsfml-window -lcsfml-graphics -lm

LDFLAGS	=	-lc_graph_prog -lm

WAY_LIB	=	../lib/my

LIB	=	-L$(WAY_LIB) -lmy

NAME	=	corewar

all:	$(NAME)

mouli:$(OBJ)
	make -C./$(WAY_LIB)
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(LDFLAGS)

$(NAME):	$(OBJ)
	make -C./$(WAY_LIB)
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(LDFLAGS_ME)

clean:
	make clean -C./$(WAY_LIB)
	$(RM) $(OBJ)

fclean:	clean
	make fclean -C./$(WAY_LIB)
	$(RM) $(NAME)

re:	clean all
