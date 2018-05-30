/*
** EPITECH PROJECT, 2017
** event
** File description:
** event
*/

#include <SFML/Graphics.h>
#include "header_corewar.h"
#include "bonus.h"

void	event(bonus_t *bonus)
{
	while (sfRenderWindow_pollEvent(bonus->win, &bonus->event)) {
		if (bonus->event.type == sfEvtClosed)
			sfRenderWindow_close(bonus->win);
		if (sfKeyboard_isKeyPressed(sfKeyEscape))
			sfRenderWindow_close(bonus->win);
	}
	sfRenderWindow_clear(bonus->win, sfBlack);
	display(bonus);
        sfRenderWindow_display(bonus->win);
}
