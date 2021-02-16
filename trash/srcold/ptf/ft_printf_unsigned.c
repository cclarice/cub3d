/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 23:45:03 by cclarice          #+#    #+#             */
/*   Updated: 2020/12/25 08:04:51 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr(unsigned int n)
{
	n / 10 ? ft_putunbr(n / 10) : 0;
	ft_putchar(n % 10 + 48);
}

int		ft_lnbrlen(long n)
{
	int l;

	l = (n < 0 ? 2 : 1);
	while (n /= 10)
		l++;
	return (l);
}

int		ft_printf_unsigned(t_frmt *s, unsigned int n)
{
	if ((s->l = ft_lnbrlen(n)) && s->m != MIN)
	{
		s->p += ft_pz((long)s->d - s->l);
		n == 0 && s->d == 0 && s->m != 0 ? s->p += ft_ps(1) : 0;
		n != 0 || s->d != 0 ? ft_putunbr(n) : 0;
		s->p += ft_ps((long)s->m - s->l - (s->d > s->l ? s->d - s->l : 0));
	}
	else if (s->z != MIN)
	{
		if (s->d != MIN)
			s->p += ft_ps((long)s->z - s->l - (s->d > s->l ? s->d - s->l : 0));
		s->p += ft_pz((long)s->d != MIN ? s->d - s->l : s->z - s->l);
		n == 0 && s->d == 0 && s->z != 0 ? s->p += ft_ps(1) : 0;
		n != 0 || s->d != 0 ? ft_putunbr(n) : 0;
	}
	else
	{
		s->p += ft_ps((long)s->n - s->l - (s->d > s->l ? s->d - s->l : 0));
		s->p += ft_pz((long)s->d - s->l);
		n == 0 && s->d == 0 && s->n != 0 && s->n != MIN ? s->p += ft_ps(1) : 0;
		n != 0 || s->d != 0 ? ft_putunbr(n) : 0;
	}
	s->p += s->d != 0 || n != 0 ? s->l : 0;
	return (1);
}
