/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:54:29 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/12 11:01:10 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/LIBFT.h"

void	lstadd_back(t_char_list **lst, t_char_list *new)
{
	t_char_list	*temp;

	if (!lst || !new)
		return ;
	temp = *lst;
	if (temp == NULL)
	{
		*lst = new;
		return ;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
}

t_char_list	*lstnew(char content)
{
	t_char_list	*new;

	new = malloc(sizeof(t_char_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	lstsize(t_char_list *lst)
{
	t_char_list	*temp;
	int			count;

	count = 0;
	temp = lst;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

int	exists(t_char_list *head)
{
	while (head)
	{
		if ((head->content) == '\n')
			return (1);
		head = head->next;
	}
	return (0);
}
