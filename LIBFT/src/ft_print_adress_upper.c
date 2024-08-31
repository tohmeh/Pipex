/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress_upper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:33:25 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/02 14:13:59 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/LIBFT.h"

static void	declare_caracterarray(char *chararray)
{
	int	i;

	i = 0;
	while (i <= 9)
	{
		chararray[i] = i + '0';
		i++;
	}
	chararray[10] = 'A';
	chararray[11] = 'B';
	chararray[12] = 'C';
	chararray[13] = 'D';
	chararray[14] = 'E';
	chararray[15] = 'F';
}

int	ft_print_adress_upper(unsigned int m)
{
	char			temp[20];
	char			chararray[16];
	unsigned int	i;
	int				count;

	count = 0;
	i = 0;
	declare_caracterarray(chararray);
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
