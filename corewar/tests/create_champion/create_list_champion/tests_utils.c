/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "header_corewar.h"

Test(create_list_champion, fail)
{
	char *path[1] = {
		NULL
	};
	cr_assert_eq(create_list_champion(NULL), NULL);
	cr_assert_eq(create_list_champion(path), NULL);
}

Test(create_list_champion, success)
{
	char *path[3] = {
		"./data/ebola.cor",
		"./data/october.cor",
		NULL
	};
	linked_list_t *list = create_list_champion(path);

	cr_assert_neq(list, NULL);
	cr_assert_neq(list->next, NULL);
	cr_assert_eq(list->next->next, NULL);
}
Test(create_list_champion, success2)
{
	char *path[7] = {
		"-n",
		"13",
		"-a",
		"76",
		"./data/ebola.cor",
		"./data/october.cor",
		NULL
	};
	linked_list_t *list = create_list_champion(path);
	champion_t *champ;

	cr_assert_neq(list, NULL);
	cr_assert_neq(list->next, NULL);
	cr_assert_eq(list->next->next, NULL);
	champ = (champion_t *)list->data;
	cr_assert_eq(champ->load_address, 76);
	cr_assert_eq(champ->number, 13);
}

Test(create_list_champion, success3)
{
	char *path[7] = {
		"-n",
		"dza13",
		"-a",
		"dazd",
		"./data/ebola.cor",
		"./data/october.cor",
		NULL
	};
	linked_list_t *list = create_list_champion(path);
	champion_t *champ;

	cr_assert_neq(list, NULL);
	cr_assert_neq(list->next, NULL);
	cr_assert_eq(list->next->next, NULL);
	champ = (champion_t *)list->data;
	cr_assert_eq(champ->load_address, -1);
	cr_assert_eq(champ->number, 1);
}
