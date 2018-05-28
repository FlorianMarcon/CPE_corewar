/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "header_corewar.h"

Test(set_dump, fail)
{
	corewar_t core;

	cr_assert_eq(set_dump(NULL, NULL), NULL);
	cr_assert_eq(set_dump(&core, NULL), NULL);
}
Test(set_dump, success)
{
	char *cmd[4] = {
		"-dump",
		"78",
		"./data/ebola.cor",
		NULL
	};
	char **new;
	corewar_t core;

	set_virgil_corewar(&core);
	new = set_dump(&core, cmd);
	cr_assert_neq(new, NULL);
	cr_assert_str_eq(new[0], "./data/ebola.cor");
	cr_assert_eq(core.dump, 78);
	cr_assert_eq(new[1], NULL);
}
Test(set_dump, success2)
{
	char *cmd[4] = {
		"-dump",
		"azdaz",
		"./data/ebola.cor",
		NULL
	};
	char **new;
	corewar_t core;

	set_virgil_corewar(&core);
	new = set_dump(&core, cmd);
	cr_assert_neq(new, NULL);
	cr_assert_str_eq(new[0], "./data/ebola.cor");
	cr_assert_eq(core.dump, -1);
	cr_assert_eq(new[1], NULL);
}
