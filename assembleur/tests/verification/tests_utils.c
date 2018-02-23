/*
** EPITECH PROJECT, 2017
** verification_argument
** File description:
** verification_argument
*/

#include <criterion/criterion.h>
int	verification_argument(int op_code, char *argu);

Test(verification_argument, test1)
{
	cr_assert_eq(verification_argument(1, "%4"), 1);
	cr_assert_eq(verification_argument(1, "4"), 0);
	cr_assert_eq(verification_argument(3, "r2,r1"), 1);
	cr_assert_eq(verification_argument(3, "r2,r1,r5"), 0);
	cr_assert_eq(verification_argument(3, "r2,%2"), 0);
}
