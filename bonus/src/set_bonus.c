/*
** EPITECH PROJECT, 2017
** set_bonus
** File description:
** set_bonus
*/

#include "bonus.h"

void	create_window(bonus_t *bonus)
{
	bonus->mode = (sfVideoMode){1200, 800, 32};
	bonus->win = sfRenderWindow_create(bonus->mode, "COREWAR", sfClose, NULL);
	if (!bonus->win)
		return;
	bonus->tex_back = sfTexture_createFromFile(PATH_BACK, NULL);
	bonus->spr_back = sfSprite_create();
	sfSprite_setTexture(bonus->spr_back, bonus->tex_back, sfFalse);
}

void	set_memory_graph(bonus_t *bonus)
{
	bonus->memory.width = 1200;
	bonus->memory.height = 800;
	bonus->memory.size = 1200 * 800 * 4;
	bonus->memory.pixels = malloc(sizeof(sfUint8) * bonus->memory.size);
	bonus->tex_mem = sfTexture_create(1200, 800);
	bonus->spr_mem = sfSprite_create();
}

void	set_color(bonus_t *bonus)
{
	sfColor transp = {0, 0, 0, 0};

	bonus->color[0].color = sfRed;
	bonus->color[0].id = 1;
	bonus->color[1].color = sfBlue;
	bonus->color[1].id = 2;
	bonus->color[2].color = sfGreen;
	bonus->color[2].id = 3;
	bonus->color[3].color = sfYellow;
	bonus->color[3].id = 4;
	bonus->color[4].color = transp;
	bonus->color[4].id = 0;
}
void	set_bonus(bonus_t *bonus)
{
	create_window(bonus);
	set_memory_graph(bonus);
	set_color(bonus);
}
