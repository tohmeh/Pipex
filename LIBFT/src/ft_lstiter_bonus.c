/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:25:32 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/12 11:03:50 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/LIBFT.h"

void	ft_lstiter(t_voidlst *lst, void (*f)(void *))
{
	t_voidlst	*temp;

	temp = lst;
	while (temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}
