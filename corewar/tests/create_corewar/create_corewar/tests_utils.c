/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "header_corewar.h"

Test(create_corewar, fail)
{
	char *path[2] = {
		NULL,
		NULL
	};
	corewar_t core;

	cr_assert_eq(create_corewar(&core, NULL), 1);
	cr_assert_eq(create_corewar(&core, path), 1);
	path[0] = strdup("./data/ebola.cor");
	cr_assert_eq(create_corewar(&core, path), 1);
}
Test(create_corewar, success)
{
	char *path[3] = {
		"./data/ebola.cor",
		"./data/october.cor",
		NULL
	};
	corewar_t core;

	cr_assert_eq(create_corewar(&core, path), 0);
}
