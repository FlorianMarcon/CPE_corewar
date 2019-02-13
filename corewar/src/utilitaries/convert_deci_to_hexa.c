/*
** EPITECH PROJECT, 2017
** convert_deci_to_hexa
** File description:
** convert_deci_to_hexa
*/

#include "header_corewar.h"

int	my_pow(int nb, int pow)
{
	int val = nb;

	if (pow == 0)
		return (1);
	for (int i = 1; i != pow; i++)
		val = val * nb;
	return (val);
}
int	determine_max_pss(int nb)
{
	int pss = 0;

	while (my_pow(16, pss) <= nb)
		pss++;
	if (pss != 0)
		pss--;
	return (pss);
}

char	determine_value_in_hexa(int nb)
{
	char model[17] = "0123456789ABCDEF";

	if (nb >= 16 || nb < 0)
		return ('\0');
	return (model[nb]);
}
char	*convert_deci_to_hexa(int nb)
{
	int pss;
	char *str;
	int tmp = 0;
	unsigned int i = 0;

	if (nb < 0)
		nb = 255 + nb + 1;
	pss = determine_max_pss(nb);
	if ((str = malloc(sizeof(*str) * (pss + 2))) == NULL)
		return (NULL);
	for (; pss != -1; i++) {
		tmp = nb / my_pow(16, pss);
		str[i] = determine_value_in_hexa(tmp);
		nb = nb - (tmp * my_pow(16, pss));
		pss--;
	}
	str[i] = '\0';
	return (str);
}
