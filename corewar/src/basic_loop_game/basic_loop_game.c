/*
** EPITECH PROJECT, 2017
** basic_loop_game
** File description:
** basic_loop_game
*/

#include "header_corewar.h"

int	(*ptr[])(corewar_t *, champion_t *) = {
	&live_instruction,
	&ld_instruction,
	&st_instruction,
	&add_instruction,
	&sub_instruction,
	&and_instruction,
	&or_instruction,
	&xor_instruction,
	&zjmp_instruction,
	&ldi_instruction,
	&sti_instruction,
	&fork_instruction,
	&lld_instruction,
	&lldi_instruction,
	&lfork_instruction,
	&aff_instruction
};

void	action_champion(corewar_t *core)
{
	linked_list_t *list = core->champion;
	champion_t *champ;
	int op;

	while (list != NULL) {
		champ = (champion_t *)list->data;
		op = get_opcode_byte(champ, core);
		if (op != 0 && champ->action_cycle > op_tab[op - 1].nbr_cycles) {
			champ->action_cycle = 0;
			if (ptr[op - 1] != NULL)
				ptr[op - 1](core, champ);
		} else if (op == 0)
			champ->pc++;
		list = list->next;
	}
}
int	basic_loop_game(corewar_t *core)
{
	core->last_alive = core->champion->data;
	while (is_end(core->champion) == 0) {
		if (core->cycle == core->dump)
			display_dump(core);
		action_champion(core);
		up_cycle(core->champion);
		up_cycle_to_die(core);
		destroy_dead_champion(core);
	}
	if (core->dump == -1)
		my_printf("The player %i (%s) has won.\n", core->last_alive->number, core->last_alive->name);
	return (0);
}
