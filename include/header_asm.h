/*
** EPITECH PROJECT, 2017
** header_asm
** File description:
** header_asm
*/

#include "my.h"

#ifndef ASM_
#define ASM_

typedef struct label {
	char *name;
	int position;
}label_t;

typedef struct analyse_file {
	linked_list_t *label;
	int count;
}analyse_file_t;

typedef struct fd {
	int fd_old;
	int fd_new;

	int write_byte;
}fd_t;

// verification
int	verification_argument(int op_code, char *argu);

int	verification_instruction(char **tab);

int	verification_name_and_comment(int fd);

int	verification_comment(int fd);

int	verification_name(int fd);

analyse_file_t	*verification_file(char *path);

int	loop_save_label(char *str, analyse_file_t *an);

analyse_file_t	*count_file_and_save_label(char *path);

int	label_is_present_in_file(char *label, linked_list_t *l);

int	analyse_label_instruction(char *argument, linked_list_t *l);

// utilitaries

char	*get_next_instruction(int fd);

int	len_tab(char **tab);

char	*my_strndup(char *str, int n);

char	**parsing_str(char *str, char separator);

	int	len_until_separator(char *str, char sep);

	int	nb_element(char *str, char sep);

char	*recuperate_string(char *str);

int	save_label(analyse_file_t *an, char *label);

int	search_function(char *str);

int	syntax_instruction_is_valid(char **msg);

	void	delete_inutile_space(char **str);

	void	delete_commentary(char *str);

// size

int	size_argument(char *str);

int	size_function(char *str);

int	size_instruction(char **tab);

// is variable

int	is_direct(char *str);

int	is_indirect(char *str);

int	is_label(char *str);

int	is_registre(char *str);

int	which_variable(char *str);

#endif
