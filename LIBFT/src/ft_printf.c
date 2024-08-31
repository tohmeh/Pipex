/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:03:04 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/02 14:13:59 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/LIBFT.h"

static void	handle_all_cases(int *count, va_list a, const char *str, int *i)
{
	if (str[*i + 1] == 'c')
		*count = *count + ft_putchar_fd((char)va_arg(a, int), 1);
	else if (str[*i + 1] == 's')
		*count = *count + ft_putstr_fd(va_arg(a, char *), 1);
	else if (str[*i + 1] == 'p')
		*count = *count + ft_print_address(va_arg(a, void *));
	else if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
		*count = *count + ft_putnbr_fd(va_arg(a, int), 1);
	else if (str[*i + 1] == 'u')
		*count = *count + ft_putlnbr(va_arg(a, unsigned int));
	else if (str[*i + 1] == 'x')
		*count = *count + ft_print_adress_lower(va_arg(a, unsigned int));
	else if (str[*i + 1] == 'X')
		*count = *count + ft_print_adress_upper(va_arg(a, unsigned int));
	else if (str[*i + 1] == '%')
		*count = *count + write(1, "%", 1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	a;
	int		count;

	va_start(a, str);
	count = 0;
	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == '%' && str[i + 1])
		{
			handle_all_cases(&count, a, str, &i);
			i += 2;
		}
		else
			count = count + write(1, &str[i++], 1);
	}
	va_end(a);
	return (count);
}
