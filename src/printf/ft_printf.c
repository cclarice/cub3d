/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:34:41 by cclarice          #+#    #+#             */
/*   Updated: 2020/12/25 07:32:42 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_getflag(t_frmt *s)
{
	int i;

	i = 0;
	ft_getn(&(*s));
	ft_getz(&(*s));
	ft_getm(&(*s));
	ft_getd(&(*s));
	if (s->d < 0)
		s->d = MIN;
	while (ft_isflag(s->f[i]))
		i++;
	return (&s->f[i] - &s->f[0] + 1);
}

void	ft_strctzero(t_frmt *s)
{
	s->n = MIN;
	s->m = MIN;
	s->z = MIN;
	s->d = MIN;
	s->l = MIN;
}

int		ft_printf_printf(t_frmt *s)
{
	int exit;

	exit = 0;
	if (s->f[-1] == '%')
		exit = ft_printf_char(&(*s), '%');
	else if (s->f[-1] == 'd' || s->f[-1] == 'i')
		exit = ft_printf_nbr(&(*s), va_arg(s->v, int));
	else if (s->f[-1] == 'u')
		exit = ft_printf_unsigned(&(*s), va_arg(s->v, unsigned int));
	else if (s->f[-1] == 'p')
		exit = ft_printf_hex(&(*s), va_arg(s->v, unsigned long), s->f[-1]);
	else if (s->f[-1] == 'x' || s->f[-1] == 'X')
		exit = ft_printf_hex(&(*s), va_arg(s->v, unsigned int), s->f[-1]);
	else if (s->f[-1] == 's')
		exit = ft_printf_str(&(*s), va_arg(s->v, char *));
	else if (s->f[-1] == 'c')
		exit = ft_printf_char(&(*s), va_arg(s->v, unsigned int));
	else
		return (-1);
	if (exit == -1)
		return (-1);
	return (1);
}

int		ft_printf(const char *f, ...)
{
	t_frmt	s;

	s.f = (char *)f;
	va_start(s.v, f);
	s.p = 0;
	while (*s.f != '\0')
	{
		if (*s.f == '%')
		{
			ft_strctzero(&s);
			++s.f;
			s.f = s.f + ft_getflag(&s);
			if ((ft_printf_printf(&s)) == -1)
			{
				va_end(s.v);
				return (-1);
			}
		}
		else
			++s.p ? ft_putchar(*s.f++) : 0;
	}
	va_end(s.v);
	return (s.p);
}
