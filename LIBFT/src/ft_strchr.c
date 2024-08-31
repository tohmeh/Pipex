/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:35:19 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/02 14:05:02 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/LIBFT.h"

char	*ft_strchr(const char *str, int character)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)character)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (str[i] == character)
	{
		return ((char *)&str[i]);
	}
	return (NULL);
}
