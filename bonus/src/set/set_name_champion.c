/*
** EPITECH PROJECT, 2017
** set_name_champion
** File description:
** set_name_champion
*/

#include "bonus.h"

void	set_name_champion(bonus_t *bonus, corewar_t *core)
{
	linked_list_t *list = core->champion;
	champion_t *champ = NULL;
	unsigned int i = 0;
	sfVector2f vec = {550, 450};

	bonus->font = sfFont_createFromFile("mat/attack_of_the_cucumbers.ttf");
	while (bonus->font != NULL && list != NULL) {
		champ = (champion_t *)list->data;
		bonus->name_champ[i] = sfText_create();
		if (bonus->name_champ[i] != NULL) {
			sfText_setString(bonus->name_champ[i], champ->name);
			sfText_setFont(bonus->name_champ[i], bonus->font);
			sfText_setPosition(bonus->name_champ[i], vec);
			vec.y += 85;
			i++;
			bonus->id_champ[i] = champ->number;
		}
		list = list->next;
	}
	bonus->name_champ[i] = NULL;
}
