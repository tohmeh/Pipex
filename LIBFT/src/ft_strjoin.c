/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:20:48 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/02 14:05:02 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/LIBFT.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	size_t	s1;
	size_t	s2;
	size_t	i;
	size_t	j;
	char	*str;

	j = -1;
	i = -1;
	if (str1 == NULL)
		s1 = 0;
	else
		s1 = ft_strlen(str1);
	if (str2 == NULL)
		s2 = 0;
	else
		s2 = ft_strlen(str2);
	str = (char *)malloc(sizeof(char) * (s1 + s2 + 1));
	if (str == NULL)
		return (NULL);
	while (str1 != NULL && str1[++i] != '\0')
		str[i] = str1[i];
	while (str2 != NULL && str2[++j] != '\0')
		str[i + j] = str2[j];
	str[i + j] = '\0';
	return (str);
}
