/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:52:16 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/02 14:05:02 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/LIBFT.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)ptr1;
	str2 = (unsigned char *)ptr2;
	i = 0;
	if (num == 0)
		return (0);
	while (i < num && str1[i] == str2[i])
		i++;
	if (i == num)
		return (0);
	return ((int)(str1[i] - str2[i]));
}
