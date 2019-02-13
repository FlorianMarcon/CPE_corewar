/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "header_corewar.h"
#include "op.h"

Test(set_virgil_corewar, test1)
{
	corewar_t core;

	set_virgil_corewar(&core);
	cr_assert_eq(core.champion, NULL);
	cr_assert_eq(core.nb_champion, 0);
	cr_assert_eq(core.cycle_to_die, CYCLE_TO_DIE);
	cr_assert_eq(core.cycle_delta, CYCLE_DELTA);
	cr_assert_eq(core.nbr_max_live, NBR_LIVE);
	cr_assert_eq(core.nbr_live, 0);
	cr_assert_eq(core.size_memory, MEM_SIZE);
	cr_assert_eq(core.memory[5], 0);
	cr_assert_eq(core.graph_memory[5], 0);
}
