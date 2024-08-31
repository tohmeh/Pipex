/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:28:42 by mtohmeh           #+#    #+#             */
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
	chararray[10] = 'a';
	chararray[11] = 'b';
	chararray[12] = 'c';
	chararray[13] = 'd';
	chararray[14] = 'e';
	chararray[15] = 'f';
}

int	ft_print_address(void *p)
{
	unsigned long int	m;
	char				temp[20];
	char				chararray[20];
	int					i;
	int					count;

	count = 0;
	i = 0;
	declare_caracterarray(chararray);
	m = (unsigned long int)(p);
	if (m == 0)
		return (write(1, "(nil)", 5));
	while (m > 0)
	{
		temp[i++] = chararray[m % 16];
		m = m / 16;
	}
	count = i;
	write(1, "0x", 2);
	while (i-- > 0)
	{
		write(1, &temp[i], 1);
	}
	return (count + 2);
}
