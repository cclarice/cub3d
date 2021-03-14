/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 06:56:26 by cclarice          #+#    #+#             */
/*   Updated: 2020/12/25 08:05:57 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_char(t_frmt *s, unsigned int c)
{
	s->l = 0;
	if (s->m != MIN)
	{
		ft_putchar(c);
		while ((s->m > ++s->l || s->z > s->l) && ++s->p)
			ft_putchar(' ');
	}
	else if (s->z != MIN)
	{
		while ((s->z > ++s->l || s->m > s->l) && ++s->p)
			ft_putchar('0');
		ft_putchar(c);
	}
	else
	{
		while ((s->n > ++s->l || s->m > s->l) && ++s->p)
			ft_putchar(' ');
		ft_putchar(c);
	}
	++s->p;
	return (1);
}
