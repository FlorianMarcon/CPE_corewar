/*
** EPITECH PROJECT, 2017
** set_memory
** File description:
** set_memory
*/

#include "header_corewar.h"

void	put_programm_in_memory(corewar_t *core, champion_t *champ, unsigned int start)
{
	if (champ->load_address != -1)
		start = champ->load_address;
	champ->pc = start;
	for (int i = 0; i != champ->prog_size; i++) {
		core->memory[start] = champ->programme[i];
		core->graph_memory[start++] = champ->number;
		if (start >= core->size_memory)
			start = 0;
	}
}

void	set_memory(corewar_t *core)
{
	linked_list_t *list = core->champion;
	unsigned int start = 0;
	unsigned int i = 0;

	while (list != NULL) {
		start = i * (core->size_memory / core->nb_champion);
		if (list->data != NULL) {
			put_programm_in_memory(core, list->data, start);
			i++;
		}
		list = list->next;
	}
}
