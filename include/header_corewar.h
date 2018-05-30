/*
** EPITECH PROJECT, 2017
** header_corewar
** File description:
** header_corewar
*/
#ifndef COREWAR_
#define COREWAR_

#include "my.h"
#include <stdbool.h>
#include "op.h"

#define QUART_MEMORY MEM_SIZE / 4

typedef struct champion {
	int pc;
	int r[REG_NUMBER];
	int carry;

	bool alive;
	int action_cycle;

	int life_cycle;

	// caractéristique
	char name[PROG_NAME_LENGTH + 1];
	int number;
	char programme[MEM_SIZE / 6];
	char comment[COMMENT_LENGTH + 1];
	int prog_size;
	int load_address;

}champion_t;

typedef struct corewar {
	linked_list_t *champion;

	int cycle_to_die;
	int cycle_delta;

	int cycle;

	int nb_champion;
	int nbr_max_live;
	int nbr_live;
	int dump;

	char memory[MEM_SIZE];
	unsigned int size_memory;

	char graph_memory[MEM_SIZE];
	bool graphical;

	champion_t *last_alive;
}corewar_t;

// create_champion

champion_t	*create_champion(unsigned int nb,int load_address, char *path);

linked_list_t	*create_list_champion(char **path);

int	fill_header(champion_t *champ, int fd);

int	fill_program(champion_t *champ, int fd);

// create_corewar

void	set_virgil_corewar(corewar_t *core);

void	set_memory(corewar_t *core);

void	put_programm_in_memory(corewar_t *core, champion_t *champ, unsigned int start);

int	create_corewar(corewar_t *core, char **path);

char	**set_dump(corewar_t *core, char **cmd);

// basic_loop_game

int	is_end(linked_list_t *list);

int	basic_loop_game(corewar_t *core);

void	up_cycle(linked_list_t *list);

void	up_cycle_to_die(corewar_t *core);

void	destroy_dead_champion(corewar_t *core);

void	evolve_game(corewar_t *core);

//utilitaries

void	integer_little_to_big_endian(int *nb);

void	short_little_to_big_endian(short *nb);

char	**my_tabcat(char **fir, char **sec);

int	get_opcode_byte(champion_t *ch, corewar_t *core);

int	load_integer_variable(corewar_t *core, int pc);

short	load_short_variable(corewar_t *core, int pc);

int	*decoding_byte(char encode);

void	write_integer(corewar_t *core, int pc, int nb);

int	load_value_by_type(corewar_t *core, int type, int pc);

void	display_dump(corewar_t *core);

char	*convert_deci_to_hexa(int nb);

void	fill_graph_memory(corewar_t *core, champion_t *ch, int start, int nb);
//instruction

int	live_instruction(corewar_t *core, champion_t *ch);

int	ld_instruction(corewar_t *core, champion_t *ch);

int	lld_instruction(corewar_t *core, champion_t *ch);

int	st_instruction(corewar_t *core, champion_t *champ);

int	zjmp_instruction(corewar_t *core, champion_t *ch);

int	sti_instruction(corewar_t *core, champion_t *ch);

int	fork_instruction(corewar_t *core, champion_t *ch);

int	lfork_instruction(corewar_t *core, champion_t *ch);

champion_t	*copy_champion(champion_t *ch);

int	add_instruction(corewar_t *core, champion_t *ch);

int	sub_instruction(corewar_t *core, champion_t *ch);

int	and_instruction(corewar_t *core, champion_t *ch);

int	or_instruction(corewar_t *core, champion_t *ch);

int	xor_instruction(corewar_t *cxore, champion_t *ch);

int	ldi_instruction(corewar_t *core, champion_t *ch);

int	lldi_instruction(corewar_t *core, champion_t *ch);

int	aff_instruction(corewar_t *core, champion_t *ch);

#endif
