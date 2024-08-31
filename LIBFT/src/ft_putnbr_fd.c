/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:58:02 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/02 14:13:59 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/LIBFT.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	digits[16];
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (n == 0)
		return (write(fd, "0", 1));
	if (n == INT_MIN)
		return (write(fd, "-2147483648", 11));
	if (n < 0)
	{
		count = count + write(fd, "-", 1);
		n = -n;
	}
	while (n > 0)
	{
		digits[i++] = (n % 10) + '0';
		n = n / 10;
	}
	count = count + i;
	digits[i] = '\0';
	while (--i >= 0)
		write(fd, &digits[i], 1);
	return (count);
}
