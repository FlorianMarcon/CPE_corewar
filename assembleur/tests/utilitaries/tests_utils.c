/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
char	**my_str_to_word_array(char const *str);

Test(my_str_to_word_array, test1)
{
	char **tab = my_str_to_word_array("salut ca va\0");

	cr_assert_str_eq(tab[0], "salut");
	cr_assert_str_eq(tab[1], "ca");
	cr_assert_str_eq(tab[2], "va");
}
