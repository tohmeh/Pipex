/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:34:51 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/02 14:05:02 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/LIBFT.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	size_t	i;
	char	*str;

	str = (char *)ptr;
	i = 0;
	while (i < num)
	{
		if (str[i] == (char)value)
		{
			return ((char *)(&str[i]));
		}
		i++;
	}
	if ((char)value == '\0' && num > 0)
		return ((char *)(&str[i]));
	return (NULL);
}
