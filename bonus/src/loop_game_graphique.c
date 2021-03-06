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

	set_bonus(&bonus, core);
	core->last_alive = core->champion->data;
	while (sfRenderWindow_isOpen(bonus.win) &&
						is_end(core->champion) == 0) {
		event(&bonus, core);
		evolve_game(core);
		destroy_dead_champion_graph(&bonus, core);
		destroy_dead_champion(core);
		update_all(&bonus, core);
	}
	my_printf("The player %i (%s) has won.\n", core->last_alive->number,
							core->last_alive->name);
}
