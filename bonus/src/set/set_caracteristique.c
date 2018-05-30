/*
** EPITECH PROJECT, 2017
** set_caracteristique
** File description:
** set_caracteristique
*/

#include "bonus.h"

static const char *caracteristique[4] = {
	"NBR CYCLES",
	"TOTAL LIVES",
	"CYCLE TO DIE",
	"NBR CHAMPION"
};

void	set_caracteristique(bonus_t *bonus)
{
	unsigned int i = 0;
	sfVector2f pos = {0, 300};
	sfVector2f pos_val = {1100, 300};

	for (; i != 4; i++) {
		bonus->caracteristique[i] = sfText_create();
		bonus->value_carac[i] = sfText_create();
		sfText_setFont(bonus->caracteristique[i], bonus->font);
		sfText_setFont(bonus->value_carac[i], bonus->font);
		sfText_setString(bonus->caracteristique[i], caracteristique[i]);
		sfText_setPosition(bonus->caracteristique[i], pos);
		sfText_setPosition(bonus->value_carac[i], pos_val);
		pos_val.y += 30;
		pos.y += 30;
	}
	bonus->caracteristique[i] = NULL;
	bonus->value_carac[i] = NULL;
}
