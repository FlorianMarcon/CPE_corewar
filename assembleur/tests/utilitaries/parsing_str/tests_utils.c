/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>

int	nb_element(char *str, char sep);
char	**parsing_str(char *str, char separator);

Test(nb_element, test1)
{
	cr_assert_eq(nb_element(",,yes,oui", ','), 2);
	cr_assert_eq(nb_element("r1,r2,r3", ','), 3);
}

Test(parsing_str, test1)
{
	char **tab = parsing_str("r1,r2,r3", ',');

	cr_assert_neq(tab[0], NULL);
	cr_assert_str_eq(tab[0], "r1");
	cr_assert_str_eq(tab[1], "r2");
	cr_assert_str_eq(tab[2], "r3");
	cr_assert_eq(tab[3], NULL);
}
