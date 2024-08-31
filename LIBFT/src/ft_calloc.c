/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:44:23 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/02 14:05:03 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/LIBFT.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*str;

	total_size = nmemb * size;
	if (nmemb != 0 && total_size / nmemb != size)
		return (NULL);
	str = malloc(total_size);
	if (str == NULL)
		return (NULL);
	ft_memset(str, 0, total_size);
	return (str);
}
