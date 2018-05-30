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
		bonus->caract[i] = sfText_create();
		bonus->val_carac[i] = sfText_create();
		sfText_setFont(bonus->caract[i], bonus->font);
		sfText_setFont(bonus->val_carac[i], bonus->font);
		sfText_setString(bonus->caract[i], caracteristique[i]);
		sfText_setPosition(bonus->caract[i], pos);
		sfText_setPosition(bonus->val_carac[i], pos_val);
		pos_val.y += 30;
		pos.y += 30;
	}
	bonus->caract[i] = NULL;
	bonus->val_carac[i] = NULL;
}
