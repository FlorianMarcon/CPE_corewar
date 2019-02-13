/*
** EPITECH PROJECT, 2017
** live_intruction
** File description:
** live_intruction
*/

#include "header_corewar.h"

int	live_instruction(corewar_t *core, champion_t *ch)
{
	linked_list_t *list = core->champion;
	int nb = load_integer_variable(core, ch->pc + 1);
	bool isdo = false;
	champion_t *champ;
	champion_t *real;

	while (list != NULL) {
		champ = (champion_t *)list->data;
		if (champ->number == nb) {
			champ->life_cycle = 0;
			if (isdo == false) {
				real = champ;
				isdo = true;
				core->nbr_live++;
				core->nbr_live_total++;
				core->last_alive = ch;
			}
		}
		list = list->next;
	}
	if (isdo == true && core->dump == -1)
		my_printf("The player %i (%s) is alive\n", nb, real->name);
	ch->pc = (ch->pc + 5) % core->size_memory;
	return (0);
}
