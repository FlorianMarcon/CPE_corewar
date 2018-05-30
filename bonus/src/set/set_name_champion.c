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
	sfVector2f vec = {550, 400};

	bonus->font = sfFont_createFromFile("picture/attack_of_the_cucumbers.ttf");
	while (bonus->font != NULL && list != NULL) {
		champ = (champion_t *)list->data;
		bonus->name_champion[i] = sfText_create();
		if (bonus->name_champion[i] != NULL) {
			sfText_setString(bonus->name_champion[i], champ->name);
			sfText_setFont(bonus->name_champion[i], bonus->font);
			sfText_setPosition(bonus->name_champion[i], vec);
			vec.y += 100;
		}
		list = list->next;
		i++;
	}
	bonus->name_champion[i] = NULL;
}
