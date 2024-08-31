/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:20:28 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/12 10:59:00 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/LIBFT.h"

char	*ft_strnstr(const char *str, const char *to_found, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_found[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] == to_found[j] && to_found[j] != '\0' && i + j < len)
		{
			j++;
		}
		if (to_found[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
