/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 06:55:47 by cclarice          #+#    #+#             */
/*   Updated: 2021/02/16 22:31:36 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

#define PLAYER "NWSE"

int		ft_strchar(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/*
**   ___
**	/ N \
**	W + E
**	\_S_/
*/

void	other_init(t_eng *e, t_vars v, char **map)
{
	int x;
	int y;
	char p;

	x = 1;
	y = 1;
	e->flc = v.fc;
	e->cec = v.cc;
	e->plx = 0;
	while (map[y][0] != '\0' && e->plx == 0)
	{
		while(map[y][x] != '\0')
		{
			if (ft_strchar(PLAYER, map[y][x]))
			{
				e->plx = y + .5;
				e->ply = x + .5;
				p = map[y][x];
			}
			x++;
		}
		x = 1;
		y++;
	}
	e->fov = FOV;
	p == 'S' ? e->pla = 0 : 0;
	p == 'W' ? e->pla = P / 0.5 : 0;
	p == 'N' ? e->pla = P : 0;
	p == 'E' ? e->pla = P * 1.5 : 0;
	e->cnt.kw = 0;
	e->cnt.ka = 0;
	e->cnt.ks = 0;
	e->cnt.kd = 0;
	e->cnt.kr = 0;
	e->cnt.kl = 0;
	e->cnt.mm = 1;
	ft_printf("Player XYA [ %d | %d | %d ]\n", x, y, (int)e->pla);
}
