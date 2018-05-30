/*
** EPITECH PROJECT, 2017
** bonus
** File description:
** bonus
*/

#ifndef BONUS_
#define BONUS_

#include <SFML/Graphics.h>
#include "header_corewar.h"

#define PATH_BACK "./picture/background.png"
#define SIZE_SQUARE 4
#define WIDTH_TEXTURE 90

void	loop_game_graphique(corewar_t *core);

typedef struct framebuffer_s {
	unsigned int width;
	unsigned int height;
	unsigned int size;
	sfUint8 *pixels;
}framebuffer_t;

typedef struct color_s {
	int id;
	sfColor color;
}color_t;

typedef struct bonus_s {
	// window
	sfVideoMode mode;
	sfRenderWindow *win;
	sfTexture *tex_back;
	sfSprite *spr_back;
	sfEvent event;

	// memory
	framebuffer_t memory;
	sfTexture *tex_mem;
	sfSprite *spr_mem;

	// color
	color_t color[6];

	// text
	sfText *name_champion[7];
	sfText *caracteristique[5];
	sfText *value_carac[5];

	// other
	sfFont *font;

} bonus_t;

void	event(bonus_t *bonus, corewar_t *core);

void	display(bonus_t *bonus, corewar_t *core);

void	update_all(bonus_t *bonus, corewar_t *core);

void	write_one_memory(framebuffer_t *frame, int x, int y, sfColor color);

char	*transform_integer_in_str(int nb);

void	destroy_dead_champion_graph(bonus_t *bonus, corewar_t *core);

// set
void	set_name_champion(bonus_t *bonus, corewar_t *core);

void	set_caracteristique(bonus_t *bonus);

void	set_bonus(bonus_t *bonus, corewar_t *core);

#endif
