/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 00:10:30 by cclarice          #+#    #+#             */
/*   Updated: 2020/12/25 08:05:44 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_isflag(char c)
{
	char *flag;

	flag = FLAG;
	while (*flag)
		if (*flag++ == c)
			return (1);
	return (0);
}

int		ft_ai(char *str)
{
	long	r;

	r = 0;
	while (*str == ' ' || *str == '-' || *str == '+' ||
	(*str <= 13 && *str >= 9))
		++str;
	while (*str >= '0' && *str <= '9' && r <= 2147483647)
	{
		r = r * 10;
		r += *str - 48;
		++str;
	}
	if (r > 2147483647)
		return (0);
	return (r);
}
