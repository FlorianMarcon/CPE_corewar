/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
int	is_registre(char *str);

Test(is_registre, test1)
{
	cr_assert_eq(is_registre("r1"), 1);
	cr_assert_eq(is_registre("r16"), 16);
	cr_assert_eq(is_registre("r9"), 9);
	cr_assert_eq(is_registre("rally"), 0);
	cr_assert_eq(is_registre("r"), 0);
	cr_assert_eq(is_registre("a1"), 0);
	cr_assert_eq(is_registre("r-2"), 0);
	cr_assert_eq(is_registre("r99"), 0);
}
