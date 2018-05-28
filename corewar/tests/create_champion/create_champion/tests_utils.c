/*
** EPITECH PROJECT, 2018
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "header_corewar.h"

Test(fill, test)
{
	int fd = open("data/ebola.cor", O_RDONLY);
	champion_t champ;

	cr_assert_neq(fd, -1);
	cr_assert_eq(fill_header(&champ, fd), 0);
	cr_assert(champ.prog_size > 0);
	cr_assert_eq(fill_program(&champ, fd), 0);
	for (unsigned int i = 0; i != REG_SIZE; i++)
		cr_assert_eq(champ.r[i], 0);
	cr_assert_eq(fill_header(&champ, 99999), 1);
	cr_assert_eq(fill_program(&champ, 99999), 1);
}

Test(create_champion, test)
{
	champion_t *champ = create_champion(1, -1, "data/ebola.cor");

	cr_assert_neq(champ, NULL);
	cr_assert_eq(champ->number, 1);
	cr_assert_eq(champ->r[0], 1);
	cr_assert_eq(champ->r[1], 0);
	cr_assert_eq(champ->alive, true);
	cr_assert_eq(champ->action_cycle, 0);
	cr_assert_eq(champ->life_cycle, 0);
	cr_assert_eq(champ->load_address, -1);
}
