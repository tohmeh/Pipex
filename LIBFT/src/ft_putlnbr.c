/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:30:51 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/02 14:13:59 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/LIBFT.h"

static int	numofdigits(unsigned int nb)
{
	size_t	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

int	ft_putlnbr(unsigned int nb)
{
	int		i;
	int		len;
	char	hold[24];
	int		count;

	count = 0;
	i = 0;
	len = numofdigits(nb);
	while (i < len)
	{
		hold[i] = nb % 10 + '0';
		i++;
		nb = nb / 10;
	}
	count = i;
	while (--i >= 0)
		write(1, &hold[i], 1);
	return (count);
}
