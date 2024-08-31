/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:53:53 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/02 14:05:02 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/LIBFT.h"
#include <stdio.h>

static size_t	ft_const_strlen(char const*str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static size_t	actual_length_calc(size_t start, size_t len, const char *str)
{
	size_t	alength;

	if (start + len > ft_const_strlen(str))
		alength = ft_const_strlen(str) - start;
	else
		alength = len;
	return (alength);
}
//If str is NULL, return NULL.
//If start is greater than or equal to str_len, return an empty string.
//If start + len exceeds str_len, adjust len to be str_len - start.

char	*ft_substr(char const *str, size_t start, size_t len)
{
	char	*sub_str;
	size_t	actual_length;
	size_t	i;

	i = -1;
	if (str == NULL)
		return (NULL);
	if (start >= ft_const_strlen(str))
	{
		sub_str = malloc(sizeof(char));
		if (sub_str == NULL)
			return (NULL);
		sub_str[0] = '\0';
		return (sub_str);
	}
	actual_length = actual_length_calc(start, len, str);
	sub_str = malloc(sizeof(char) * (actual_length + 1));
	if (sub_str == NULL)
		return (NULL);
	while (++i < actual_length)
		sub_str[i] = str[start + i];
	sub_str[i] = '\0';
	return (sub_str);
}
