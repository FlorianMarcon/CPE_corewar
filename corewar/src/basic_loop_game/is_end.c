/*
** EPITECH PROJECT, 2017
** is_end
** File description:
** is_end
*/

#include "header_corewar.h"

int	is_end(linked_list_t *list)
{
	champion_t *champ;
	int mem;

	if (list == NULL)
		return (1);
	mem = ((champion_t *)(list->data))->number;
	while (list != NULL) {
		champ = (champion_t *)list->data;
		if (champ != NULL && champ->alive == true && champ->number != mem)
			return (0);
		list = list->next;
	}
	return (1);
}
