/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 06:55:47 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/14 09:50:36 by cclarice         ###   ########.fr       */
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

void	player_init(t_eng *e, char **map)
{
	int x;
	int y;

	x = 1;
	y = 1;
	e->plx = 0;
	while (map[y][0] != '\0' && e->plx == 0)
	{
		while (map[y][x] != '\0')
		{
			if (ft_strchar(PLAYER, map[y][x]))
			{
				e->plx = x + .500001;
				e->ply = y + .500001;
				map[y][x] == 'S' ? e->pla = 0.00001 : 0;
				map[y][x] == 'W' ? e->pla = P * 0.5 : 0;
				map[y][x] == 'N' ? e->pla = P : 0;
				map[y][x] == 'E' ? e->pla = P * 1.5 : 0;
			}
			x++;
		}
		x = 1;
		y++;
	}
}

/*
** ft_printf("%d: %p %p", i++, &e.spr->x, &e.spr->y);
*/

void	print_sprites(t_eng e)
{
	int i;

	i = 1;
	if (e.spr)
	{
		while (e.spr)
		{
			i++;
			e.spr = e.spr->next;
		}
		ft_printf("Sprites: %d\n", i);
	}
	else
		ft_printf("Sprites is not found!\n");
}

void	sprites_init(t_eng *e, char **map)
{
	int		x;
	int		y;

	x = 1;
	y = 1;
	e->spr = NULL;
	while (map[y][0] != '\0')
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '2')
				ft_lstadd_back(&e->spr, ft_newsprite(x + 0.5, y + 0.5));
			x++;
		}
		x = 1;
		y++;
	}
	e->dst = (double *)malloc(sizeof(double) * e->rex + 1);
	e->ray = (double *)malloc(sizeof(double) * (e->rex * 2) + 1);
	if (!e->dst || !e->ray)
		ft_printf("MALLOC ERROR!\n");
	e->rayr = e->ray;
	e->ray = &e->ray[e->rex / 2 + 1];
	print_sprites(*e);
}

void	other_init(t_eng *e, t_vars v, char **map)
{
	ft_printf("Player init\n");
	player_init(e, map);
	ft_printf("Sprites init\n");
	sprites_init(e, map);
	e->flc = v.fc;
	e->cec = v.cc;
	e->plb = 1;
	e->fov = FOV;
	e->cnt.kw = 0;
	e->cnt.ka = 0;
	e->cnt.ks = 0;
	e->cnt.kd = 0;
	e->cnt.kr = 0;
	e->cnt.kl = 0;
	e->cnt.mm = 1;
}
