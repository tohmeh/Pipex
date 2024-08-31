/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:03:43 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/12 11:03:50 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/LIBFT.h"

void	ft_lstadd_front(t_voidlst **lst, t_voidlst *new)
{
	new->next = *lst;
	*lst = new;
}
