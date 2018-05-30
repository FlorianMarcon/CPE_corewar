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
	sfColor arr[5] = {sfRed, sfBlue, sfGreen, sfYellow, transp};
	int x = 500;
	int y = 450;

	for (unsigned int i = 0; i != 5 ; i++) {
		bonus->color[i].color = arr[i];
		bonus->color[i].id = i + 1;
		write_one_memory(&bonus->memory, x * 4, y, arr[i]);
		write_one_memory(&bonus->memory, x * 4, y + 20, arr[i]);
		write_one_memory(&bonus->memory, (x + 20) * 4, y, arr[i]);
		write_one_memory(&bonus->memory, (x + 20) * 4, y + 20, arr[i]);
		y += 85;
	}
	bonus->color[4].id = 0;
}

void	set_bonus(bonus_t *bonus, corewar_t *core)
{
	create_window(bonus);
	set_memory_graph(bonus);
	set_color(bonus);
	set_name_champion(bonus, core);
	set_caracteristique(bonus);
}
