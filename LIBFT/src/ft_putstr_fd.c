/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:50:59 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/02 14:13:59 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/LIBFT.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	if (!fd)
		return (0);
	if (s == NULL)
		return (write(1, "(null)", 6));
	len = ft_strlen((const char *)s);
	write(fd, s, len);
	return (len);
}
