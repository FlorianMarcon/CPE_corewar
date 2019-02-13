/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "header_corewar.h"

Test(put_programm_in_memory, test1)
{
	corewar_t core;
	char *path[2] = {
		"./data/ebola.cor",
		NULL
	};
	linked_list_t *list = create_list_champion(path);

	cr_assert_neq(list, NULL);
	set_virgil_corewar(&core);
	put_programm_in_memory(&core, list->data, 0);
	cr_assert_neq(core.memory[0], 0);
	cr_assert_eq(core.graph_memory[0], 1);
}

Test(set_memory, test1)
{
	char *path[3] = {
		"./data/ebola.cor",
		"./data/october.cor",
		NULL
	};
	corewar_t core;

	set_virgil_corewar(&core);
	core.champion = create_list_champion(path);
	core.nb_champion = 2;
	cr_assert_neq(core.champion, NULL);
	set_memory(&core);
	cr_assert_eq(core.graph_memory[0], 1);
	cr_assert_eq(core.graph_memory[MEM_SIZE / 2], 2);
}
Test(set_memory, test2)
{
	char *path[3] = {
		"./data/test.cor",
		NULL
	};
	corewar_t core;

	set_virgil_corewar(&core);
	core.champion = create_list_champion(path);
	core.nb_champion = 1;
	cr_assert_neq(core.champion, NULL);
	set_memory(&core);
	fprintf(stderr, "%i\n", core.memory[0]);
	cr_assert_eq(core.memory[0], 01);
}

Test(put_programm_in_memory, test2)
{
	corewar_t core;
	char *path[4] = {
		"-a",
		"42",
		"./data/ebola.cor",
		NULL
	};
	linked_list_t *list = create_list_champion(path);

	cr_assert_neq(list, NULL);
	set_virgil_corewar(&core);
	put_programm_in_memory(&core, list->data, 0);
	cr_assert_neq(core.memory[42], 0);
	cr_assert_eq(core.graph_memory[42], 1);
}
