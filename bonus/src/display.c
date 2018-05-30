/*
** EPITECH PROJECT, 2017
** display
** File description:
** display
*/

#include <SFML/Graphics.h>
#include "header_corewar.h"
#include "bonus.h"

void	display_text(bonus_t *bonus)
{
	for (unsigned int i = 0; bonus->name_champion[i] != NULL; i++)
		sfRenderWindow_drawText(bonus->win, bonus->name_champion[i], NULL);
}
void	display(bonus_t *bonus)
{
	framebuffer_t *frame = &bonus->memory;

	sfRenderWindow_drawSprite(bonus->win, bonus->spr_back, NULL);
	sfTexture_updateFromPixels(bonus->tex_mem, frame->pixels, 1200, 800, 0, 0);
	sfSprite_setTexture(bonus->spr_mem, bonus->tex_mem, sfTrue);
	sfRenderWindow_drawSprite(bonus->win, bonus->spr_mem, NULL);
	display_text(bonus);
}
