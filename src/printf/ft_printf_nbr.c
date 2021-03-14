/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 23:44:31 by cclarice          #+#    #+#             */
/*   Updated: 2020/12/25 08:10:47 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n)
{
	n / 10 ? ft_putnbr(n / 10) : 0;
	ft_putchar(n % 10 * (n < 0 ? -1 : 1) + 48);
}

int		ft_ne(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

int		ft_nbrlen(int n)
{
	int l;

	l = (n < 0 ? 2 : 1);
	while (n /= 10)
		l++;
	return (l);
}

void	ft_print_nbr_extend(t_frmt *s, int n)
{
	s->p += ft_ps((long)s->n - s->l -
	(s->d >= s->l ? s->d - s->l + ft_ne(n) : 0));
	s->p += ft_pzm((long)s->d - s->l, n);
	n == 0 && s->d == 0 && s->n != 0 && s->n != MIN ? s->p += ft_ps(1) : 0;
	n != 0 || s->d != 0 ? ft_putnbr(n) : 0;
}

int		ft_printf_nbr(t_frmt *s, int n)
{
	if ((s->l = ft_nbrlen(n)) && s->m != MIN)
	{
		s->p += ft_pzm((long)s->d - s->l, n);
		n == 0 && s->d == 0 && s->m != 0 && s->m != 0 ?
		s->p += ft_ps(1) : 0;
		n != 0 || s->d != 0 ? ft_putnbr(n) : 0;
		s->p += ft_ps((long)s->m - s->l -
		(s->d >= s->l ? s->d - s->l + ft_ne(n) : 0));
	}
	else if (s->z != MIN)
	{
		if (s->d != MIN)
			s->p += ft_ps((long)s->z - s->l -
		(s->d >= s->l ? s->d - s->l + ft_ne(n) : 0));
		s->d != MIN ? s->p += ft_pzm((long)s->d - s->l, n) :
		(s->p += ft_pzm((long)s->z - s->l - ft_ne(n), n));
		n == 0 && s->d == 0 && s->z != 0 && s->z != 0 ?
		s->p += ft_ps(1) : 0;
		n != 0 || s->d != 0 ? ft_putnbr(n) : 0;
	}
	else
		ft_print_nbr_extend(&(*s), n);
	s->p += s->d != 0 || n != 0 ? s->l - ft_ne(n) : 0;
	return (1);
}
