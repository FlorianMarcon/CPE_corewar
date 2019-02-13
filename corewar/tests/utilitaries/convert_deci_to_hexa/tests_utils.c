/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "header_corewar.h"

Test(convert_deci_to_hexa, test1)
{
	cr_assert_str_eq(convert_deci_to_hexa(12), "C");
	cr_assert_str_eq(convert_deci_to_hexa(4567), "11D7");
	cr_assert_str_eq(convert_deci_to_hexa(0), "0");
}
