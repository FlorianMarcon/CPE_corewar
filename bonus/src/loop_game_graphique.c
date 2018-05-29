/*
** EPITECH PROJECT, 2017
** loop_game_graphique
** File description:
** loop_game_graphique
*/

#include <SFML/Graphics.h>
#include "header_corewar.h"
#include "bonus.h"

void	loop_game_graphique(corewar_t *core)
{
	bonus_t bonus;

	set_bonus(&bonus);
	while (sfRenderWindow_isOpen(bonus.win)) {
		update_all(&bonus, core);
		event(&bonus);
	}
}
