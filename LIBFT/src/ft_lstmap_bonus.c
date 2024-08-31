/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:27:57 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/12 11:03:50 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/LIBFT.h"

t_voidlst	*ft_lstmap(t_voidlst *lst, void *(*f)(void *), void (*del)(void *))
{
	t_voidlst	*new;

	new = NULL;
	while (lst)
	{
		ft_lstadd_back(&new, ft_lstnew(f(lst->content)));
		if (!new)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (new);
}
