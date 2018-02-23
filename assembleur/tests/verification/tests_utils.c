/*
** EPITECH PROJECT, 2017
** verification_argument
** File description:
** verification_argument
*/

#include <criterion/criterion.h>
int	verification_argument(int op_code, char *argu);
int	verification_instruction(char **tab);

Test(verification_argument, test1)
{
	cr_assert_eq(verification_argument(1, "%4"), 1);
	cr_assert_eq(verification_argument(1, "4"), 0);
	cr_assert_eq(verification_argument(3, "r2,r1"), 1);
	cr_assert_eq(verification_argument(3, "r2,r1,r5"), 0);
	cr_assert_eq(verification_argument(3, "r2,%2"), 0);
}

Test(verification_instruction, test1)
{
	char *tab1[3] = {"ld", "%1,r1", NULL};
	char *tab2[3] = {"ld", "%1,%1", NULL};
	char *tab3[3] = {"l", "%1,r1", NULL};
	char *tab4[3] = {"ld", NULL};

	cr_assert_eq(verification_instruction(tab1), 1);
	cr_assert_eq(verification_instruction(tab2), 0);
	cr_assert_eq(verification_instruction(tab3), 0);
	cr_assert_eq(verification_instruction(tab4), 0);
	cr_assert_eq(verification_instruction(NULL), 0);
}
