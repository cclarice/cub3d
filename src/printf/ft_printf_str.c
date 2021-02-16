/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 06:57:07 by cclarice          #+#    #+#             */
/*   Updated: 2020/12/25 08:07:04 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr(char *str, int n)
{
	int c;

	c = 0;
	if (str)
		while (*str && n-- > 0)
		{
			ft_putchar(*str++);
			c++;
		}
	return (c);
}

int		ft_strlen(char *str)
{
	int n;

	n = 0;
	if (str)
		while (*str++ != '\0')
			n++;
	return (n);
}

int		ft_printf_str(t_frmt *s, char *c)
{
	if (c == NULL)
		c = "(null)";
	s->l = ft_strlen(c);
	if (s->d < s->l && s->d >= 0)
		s->l = s->d;
	if (s->m != MIN)
	{
		s->p += ft_putstr(c, s->l);
		s->p += ft_ps(s->m - s->l);
	}
	else if (s->z != MIN)
	{
		s->p += ft_pz(s->z - s->l);
		s->p += ft_putstr(c, s->l);
	}
	else
	{
		s->p += ft_ps((long)s->n - s->l);
		s->p += ft_putstr(c, s->l);
	}
	return (1);
}
