/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress_lower.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:32:16 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/02 14:13:59 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/LIBFT.h"

static void	declare_lcaracterarray(char *chararray)
{
	int	i;

	i = 0;
	while (i <= 9)
	{
		chararray[i] = i + '0';
		i++;
	}
	chararray[10] = 'a';
	chararray[11] = 'b';
	chararray[12] = 'c';
	chararray[13] = 'd';
	chararray[14] = 'e';
	chararray[15] = 'f';
}

int	ft_print_adress_lower(unsigned int m)
{
	char			temp[20];
	char			chararray[16];
	unsigned int	i;
	int				count;

	count = 0;
	i = 0;
	declare_lcaracterarray(chararray);
	if (m == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (m > 0)
	{
		temp[i++] = chararray[m % 16];
		m = m / 16;
	}
	count = i;
	while (i-- > 0)
	{
		write(1, &temp[i], 1);
	}
	return (count);
}
