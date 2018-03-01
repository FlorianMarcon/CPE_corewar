/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "header_asm.h"

linked_list_t	*create_list_test(void)
{
	linked_list_t *list = malloc(sizeof(*list));
	label_t *label = malloc(sizeof(*label));
	label_t *label_two = malloc(sizeof(*label_two));

	if (list == NULL || label == NULL || label_two == NULL)
		return (NULL);
	label->name = my_strdup("live");
	list->data = label;
	list->next = NULL;
	label_two->name = my_strdup("label");
	create_node(list, label_two);
	return (list);
}

Test(create_list_test, test)
{
	linked_list_t *l = create_list_test();
	label_t *label;

	cr_assert_eq(l->next->next, NULL);
	cr_assert_neq(l->next, NULL);
	label = (label_t *)l->data;
	cr_assert_neq(label, NULL);
	cr_assert_str_eq(label->name, "live");
	label = (label_t *)l->next->data;
	cr_assert_neq(label, NULL);
	cr_assert_str_eq(label->name, "label");
}

Test(label_is_present_in_file, test1)
{
	linked_list_t *l = NULL;
	char *str = my_strdup("%:live");

	cr_assert_eq(label_is_present_in_file("live", NULL), 0);
	l = create_list_test();
	cr_assert_neq(l, NULL);
	cr_assert_eq(label_is_present_in_file(NULL, l), 0);
	cr_assert_eq(label_is_present_in_file(str, l), 1);
	free(str);
	str = my_strdup("%:label");
	cr_assert_eq(label_is_present_in_file(str, l), 1);
	free(str);
	str = my_strdup("%:xxx");
	cr_assert_eq(label_is_present_in_file(str, l), 0);
	free(str);
	str = my_strdup("%56");
	cr_assert_eq(label_is_present_in_file(str, l), 1);
	free(str);
}

Test(analyse_label_instruction, test1)
{
	linked_list_t *l = create_list_test();
	char *str = NULL;

	str = my_strdup("%:live");
	cr_assert_eq(analyse_label_instruction(str, l), 1);
	free(str);
	str = my_strdup("%:false");
	cr_assert_eq(analyse_label_instruction(str, l), 0);
	free(str);
}
