/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 02:18:29 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/14 10:16:54 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	get_sprite_distance(t_eng *e)
{
	t_spr *crnt;

	crnt = e->spr;
	while (crnt)
	{
		crnt->len = sqrt((e->plx - crnt->x) * (e->plx - crnt->x) +
						(e->ply - crnt->y) * (e->ply - crnt->y));
		crnt = crnt->next;
	}
}

int		not_sorted(t_eng *e)
{
	t_spr	*crnt;
	double	max;

	crnt = e->spr;
	max = crnt->len;
	while (crnt->next)
	{
		crnt = crnt->next;
		if (max < crnt->len)
			return (1);
		max = crnt->len;
	}
	return (0);
}

void	swap(t_spr *one, t_spr *two)
{
	t_spr	buf;

	buf.x = two->x;
	buf.y = two->y;
	buf.len = two->len;
	two->x = one->x;
	two->y = one->y;
	two->len = one->len;
	one->x = buf.x;
	one->y = buf.y;
	one->len = buf.len;
}

void	sort_sprites(t_eng *e)
{
	t_spr	*crnt;

	while (not_sorted(e))
	{
		crnt = e->spr;
		while (crnt->next)
		{
			if (crnt->len < crnt->next->len)
				swap(crnt, crnt->next);
			crnt = crnt->next;
		}
	}
}

int		is_drawable_line(t_xpm *xpm, int x)
{
	int				i;
	unsigned char	*color;

	i = 0;
	while (i < xpm->h)
	{
		color = get_pafxmp(xpm, x, i);
		if (color[2] || color[1] || color[0])
			return (1);
		i++;
	}
	return (0);
}
