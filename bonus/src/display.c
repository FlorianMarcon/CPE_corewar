/*
** EPITECH PROJECT, 2017
** display
** File description:
** display
*/

#include <SFML/Graphics.h>
#include "header_corewar.h"
#include "bonus.h"

void	display_text(bonus_t *bonus, corewar_t *core)
{
	char *str;

	str = transform_integer_in_str(core->cycle);
	sfText_setString(bonus->value_carac[0], str);
	free(str);
	str = transform_integer_in_str(core->nbr_live_total);
	sfText_setString(bonus->value_carac[1], str);
	free(str);
	str = transform_integer_in_str(core->cycle_to_die);
	sfText_setString(bonus->value_carac[2], str);
	free(str);
	str = transform_integer_in_str(core->nb_champion);
	sfText_setString(bonus->value_carac[3], str);
	free(str);
	for (unsigned int i = 0; bonus->name_champion[i] != NULL; i++)
		sfRenderWindow_drawText(bonus->win, bonus->name_champion[i], NULL);
	for (unsigned int i = 0; bonus->caracteristique[i] != NULL; i++) {
		sfRenderWindow_drawText(bonus->win, bonus->caracteristique[i], NULL);
		sfRenderWindow_drawText(bonus->win, bonus->value_carac[i], NULL);
	}
}
void	display(bonus_t *bonus, corewar_t *core)
{
	framebuffer_t *frame = &bonus->memory;

	sfRenderWindow_drawSprite(bonus->win, bonus->spr_back, NULL);
	sfTexture_updateFromPixels(bonus->tex_mem, frame->pixels, 1200, 800, 0, 0);
	sfSprite_setTexture(bonus->spr_mem, bonus->tex_mem, sfTrue);
	sfRenderWindow_drawSprite(bonus->win, bonus->spr_mem, NULL);
	display_text(bonus, core);
}
