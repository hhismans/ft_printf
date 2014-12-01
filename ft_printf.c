/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 16:51:05 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/28 10:18:10 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
/* The function getinfo create a lst "lst" who contain the flag of "format"
 * RETURN VALUE : number of flag
 * flag format : %x */
int		get_info(const char *format, t_list **lst)
{
	int i;
	int nbr_prc;
	char tmp[1];
	t_list *lst_tmp;

	i = 0;
	nbr_prc = 0;
	while (format[i])
	{
		if (format[i] == '\\')
			i++;
		if (format[i] == '%')
		{
			if (format[i + 1])
			{
				nbr_prc++;
				if (lst_tmp == NULL)
				{
					tmp[0] = format[i + 1];
					lst_tmp = ft_lstnew(tmp, sizeof(char));
					*lst = lst_tmp;
				}
				else
				{
					tmp[0] = format[i + 1];
					lst_tmp->next = ft_lstnew(tmp, sizeof(char));
					lst_tmp = lst_tmp->next;
				}
				i++;
			}
		}
		i++;
	}
	return (nbr_prc);
}

int		ft_printf(const char *format, ...)
{
	int		i;
	int		nbr_prc;
	t_list	*lst;
	t_list	*lst_tmp;
	char	tmp[1];

	lst = NULL;
	i = 0;

	nbr_prc = get_info(format, &lst);
	while (format[i])
	{
		if (format[i] == '\\')
			i++;
		if (format[i] == '%')
		{
			i++;
			if (format[i]
		}
	}

	return (nbr_prc);
}

int main(int argc, char **argv)
{
	ft_putnbr(ft_printf(argv[1]));
	printf("salut %s", 124);
}
