/*
** EPITECH PROJECT, 2017
** update_all
** File description:
** update_all
*/

#include <SFML/Graphics.h>
#include "header_corewar.h"
#include "bonus.h"

void	write_one_memory(framebuffer_t *frame, int x, int y, sfColor color)
{
	int st_x = x + (SIZE_SQUARE * 4);
	int st_y = y + (SIZE_SQUARE);
	int tmp = x;

	while (y != st_y) {
		x = tmp;
		while (x != st_x) {
			frame->pixels[(y * frame->width) * 4 + x++] = color.r;
			frame->pixels[(y * frame->width) * 4 + x++] = color.g;
			frame->pixels[(y * frame->width) * 4 + x++] = color.b;
			frame->pixels[(y * frame->width) * 4 + x++] = color.a;
		}
		y++;
	}
}

sfColor	search_color_by_id(color_t *arr, int id)
{
	sfColor color = {0, 0, 0, 0};

	for (unsigned int i = 0; i != 5; i++)
		if (arr[i].id == id) {
			color = arr[i].color;
			break;
		}
	return (color);
}
void	update_memory_graph(bonus_t *bonus, corewar_t *core)
{
	framebuffer_t *frame = &bonus->memory;
	unsigned int y = 0;
	unsigned int x = 0;
	sfColor color;

	if (frame->pixels == NULL)
		return;
	while ((y * WIDTH_TEXTURE) + x < MEM_SIZE) {
		color = search_color_by_id(bonus->color, core->graph_memory[(y * WIDTH_TEXTURE) + x]);
		write_one_memory(frame, (x++ * (4 * SIZE_SQUARE)), y * SIZE_SQUARE, color);
		if (x * (SIZE_SQUARE) >= 1200) {
			x = 0;
			y++;
		}
	}
}
void	update_all(bonus_t *bonus, corewar_t *core)
{
	update_memory_graph(bonus, core);
}
