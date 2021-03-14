/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 07:26:35 by cclarice          #+#    #+#             */
/*   Updated: 2020/12/25 07:33:00 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_getn(t_frmt *s)
{
	if (s->f[0] == '*')
	{
		s->n = va_arg(s->v, int);
		if (s->n < 0)
		{
			s->m = s->n * -1;
			s->n = MIN;
		}
	}
	else if (ft_isdigit(s->f[0]) && s->f[0] != '0')
		s->n = ft_ai(s->f);
}

void	ft_getz(t_frmt *s)
{
	if (s->f[0] == '0' && s->f[1] == '*')
	{
		s->z = va_arg(s->v, int);
		if (s->z < 0)
		{
			s->m = s->z * -1;
			s->z = MIN;
		}
	}
	else if (s->f[0] == '0' && ft_isdigit(s->f[1]))
		s->z = ft_ai(&(s->f[1]));
}

int		ft_kostil(char *str)
{
	int i;

	i = 0;
	while (str[i] == '-' || str[i] == '0')
	{
		if (str[++i] == '*')
			return (1);
	}
	return (0);
}

void	ft_getm(t_frmt *s)
{
	int i;

	i = 0;
	while (ft_isflag(s->f[i]))
	{
		if (s->f[i] == '-')
		{
			s->z = MIN;
			s->n = MIN;
			if (ft_kostil(&(s->f[i])))
			{
				s->m = va_arg(s->v, int);
				if (s->m < 0)
					s->m *= -1;
			}
			else if (ft_isdigit(s->f[i]) || s->f[i] == '-')
				s->m = ft_ai(&(s->f[i]));
			return ;
		}
		i++;
	}
}

void	ft_getd(t_frmt *s)
{
	int i;

	i = 0;
	while (ft_isflag(s->f[i]))
	{
		if (s->f[i] == '.')
		{
			s->d = 0;
			if (s->f[++i] == '*')
				s->d = va_arg(s->v, int);
			else if (ft_isdigit(s->f[i]))
				s->d = ft_ai(&(s->f[i]));
			return ;
		}
		i++;
	}
}
