/*
** EPITECH PROJECT, 2017
** my_str_isnum.c
** File description:
** know if str is num
*/

#include <unistd.h>

int	my_str_isnum(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		else if (str[i] < 48 || str[i] > 57)
			return (0);
		else
			i++;
	}
	return (1);
}
