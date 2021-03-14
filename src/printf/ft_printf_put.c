/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 07:42:06 by cclarice          #+#    #+#             */
/*   Updated: 2020/12/25 07:45:28 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ps(long c)
{
	int	n;

	n = 0;
	while (c-- > 0 && ++n)
		ft_putchar(' ');
	return (n);
}

int		ft_pz(long c)
{
	int n;

	n = 0;
	while (c-- > 0 && ++n)
		ft_putchar('0');
	return (n);
}

int		ft_pzm(long c, int d)
{
	int n;

	n = 0;
	if (d < 0 && ++n)
	{
		if (c != MIN)
			c++;
		ft_putchar('-');
	}
	while (c-- > 0 && ++n)
		ft_putchar('0');
	return (n);
}
