/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:04:16 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/12 11:01:10 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/LIBFT.h"

void	retrieve_from_list_helper(t_char_list **head, char *result)
{
	int			i;
	t_char_list	*to_free;

	i = 0;
	while (*head && (*head)->content != '\n')
	{
		result[i++] = (*head)->content;
		to_free = *head;
		*head = (*head)->next;
		free(to_free);
	}
	if (*head)
	{
		result[i++] = (*head)->content;
		to_free = *head;
		*head = (*head)->next;
		free(to_free);
	}
	result[i] = '\0';
}

char	*retrieve_from_list(t_char_list **head)
{
	char	*result;

	if (*head == NULL)
		return (NULL);
	result = malloc(sizeof(char) * (lstsize(*head) + 2));
	if (!result)
		return (NULL);
	retrieve_from_list_helper(head, result);
	return (result);
}

void	read_to_list(int fd, t_char_list **list, int *feof)
{
	char	buffer[BUFFER_SIZE];
	int		bytes_read;
	int		i;

	while (!exists(*list))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			*feof = -1;
			return ;
		}
		if (bytes_read == 0)
		{
			*feof = 0;
			return ;
		}
		i = 0;
		while (i < bytes_read)
		{
			lstadd_back(list, lstnew(buffer[i]));
			i++;
		}
	}
}

char	*get_next_line(int fd)
{
	static t_char_list	*new = NULL;
	static int			feof = 1;
	char				*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_to_list(fd, &new, &feof);
	if (feof == -1)
		return (NULL);
	str = retrieve_from_list(&new);
	if (str)
		return (str);
	return (NULL);
}
