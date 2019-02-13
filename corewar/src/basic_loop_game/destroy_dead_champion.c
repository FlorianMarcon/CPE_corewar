/*
** EPITECH PROJECT, 2017
** destroy_dead_champion
** File description:
** destroy_dead_champion
*/

#include "header_corewar.h"

linked_list_t	*destroy_node(linked_list_t *list, linked_list_t *node)
{
	linked_list_t *start = list;

	if (node == NULL || list == NULL)
		return (list);
	if (list == node) {
		list = list->next;
		free (node);
		return (list);
	} else {
		while (list->next != node)
			list = list->next;
		list->next = list->next->next;
		free(node);
		return (start);
	}
}
void	destroy_dead_champion(corewar_t *core)
{
	linked_list_t *list = core->champion;
	linked_list_t *tmp = list;
	champion_t *champ = NULL;

	while (tmp != NULL) {
		champ = (champion_t *)tmp->data;
		if (champ == NULL || champ->alive == false ||
				champ->life_cycle > core->cycle_to_die) {
			list = destroy_node(list, tmp);
			tmp = list;
		} else
			tmp = tmp->next;
	}
	core->champion = list;
}
