/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:54:41 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/02 14:05:02 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/LIBFT.h"

char	*ft_strrchr(const char *str, int character)
{
	int	i;
	int	index;

	i = 0;
	index = -1;
	while (str[i] != '\0')
	{
		if (str[i] == (char)character)
		{
			index = i;
		}
		i++;
	}
	if (character == '\0')
		return ((char *)(&str[i]));
	if (index == -1)
		return (NULL);
	return ((char *)&str[index]);
}
