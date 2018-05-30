/*
** EPITECH PROJECT, 2017
** destroy_dead_champion_graph
** File description:
** destroy_dead_champion_graph
*/

#include "bonus.h"

void	mark_dead_champion(bonus_t *bonus, int id)
{
	const char *str;
	char *new;

	for (unsigned int i = 0; bonus->name_champion[i] != NULL; i++) {
		if (id == bonus->id_champ[i]) {
			str = sfText_getString(bonus->name_champion[i - 1]);
			new = my_strcat((char *)str, " DEAD");
			sfText_setString(bonus->name_champion[i - 1], new);
		}
	}
}
void	destroy_dead_champion_graph(bonus_t *bonus, corewar_t *core)
{
	linked_list_t *list = core->champion;
	champion_t *ch = NULL;

	while (list != NULL) {
		ch = list->data;
		if (ch != NULL && (ch->alive == false || ch->life_cycle > core->cycle_to_die)) {
			mark_dead_champion(bonus, ch->number);
		}
		list = list->next;
	}
}
