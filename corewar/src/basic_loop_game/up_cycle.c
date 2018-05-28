/*
** EPITECH PROJECT, 2017
** up_cycle
** File description:
** up_cycle
*/

#include "header_corewar.h"

void	up_cycle(linked_list_t *list)
{
	champion_t *champ = NULL;

	while (list != NULL) {
		champ = (champion_t *)list->data;
		if (champ != NULL) {
			champ->life_cycle++;
			champ->action_cycle++;
		}
		list = list->next;
	}
}
