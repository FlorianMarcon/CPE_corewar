/*
** EPITECH PROJECT, 2017
**
** File description:
**
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
	unsigned int i = 0;

	while (list != NULL) {
		champ = (champion_t *)list->data;
		op = get_opcode_byte(champ, core);
		i++;
		if (op != 0 && champ->action_cycle > op_tab[op - 1].nbr_cycles) {
			fprintf(stderr, "---------------------------\n");
			fprintf(stderr, "|	%s	%i|\n", champ->name, i);
			fprintf(stderr, "|	pc = %i	|\n", champ->pc);
			fprintf(stderr, "|	%s	|\n", op_tab[op -1].mnemonique);
			fprintf(stderr, "---------------------------\n");
			champ->action_cycle = 0;
			if (ptr[op - 1] != NULL)
				ptr[op - 1](core, champ);
		} else if (op == 0)
			champ->pc++;
		list = list->next;
	}
	fprintf(stderr, "Il y a %i champion\n", i);
}
void	evolve_game(corewar_t *core)
{
	action_champion(core);
	up_cycle(core->champion);
	up_cycle_to_die(core);
	destroy_dead_champion(core);
}
