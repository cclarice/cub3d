/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 02:29:44 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/14 09:38:37 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

#define EBAN ((double)e->rex / (double)e->rey)
#define MAP_LEN (double)(e->msx >= e->msy ? e->msx * 1.42 : e->msy * 1.42)

void		clear_sprite_line(t_eng *e, int *d)
{
	const int		up = d[0];
	const int		range = d[1] - up;
	const int		mid = up + range / 2;

	if (d[0] < 0)
		d[0] = 0;
	if (d[1] >= e->rey)
		d[1] = e->rey;
	while (d[0] < d[1])
	{
		if (d[0] > mid)
			put_pixel_to_img(&e->mdg, d[2], d[0]++, e->flc);
		else
			put_pixel_to_img(&e->mdg, d[2], d[0]++, e->cec);
	}
}

void		clear_calc_lines(t_eng *e, int xx, double len)
{
	int		height;
	int		d[3];
	int		i;

	i = 0;
	if (e->fov < P * 1.5)
		len = len * fabs(cos(e->ray[xx]));
	height = (int)(e->rey / len * (P * 0.31 / e->fov) * EBAN);
	d[0] = -height * 0.5 + e->rey * 0.5 * e->plb;
	d[1] = +height * 0.5 + e->rey * 0.5 * e->plb;
	d[2] = xx - height / 2;
	if (len > 0.25)
		while (i < height)
		{
			if (d[2] >= 0 && d[2] < e->rex && e->dst[d[2]] > len)
				clear_sprite_line(e, d);
			d[0] = -height * 0.5 + e->rey * 0.5 * e->plb;
			d[2]++;
			i++;
		}
}

void		clear_sprite(t_eng *e, t_spr s)
{
	double	len;
	double	angle;
	int		ray;

	if (e->ply < s.y)
		angle = atan((e->plx - s.x) / (e->ply - s.y));
	else
		angle = atan((e->plx - s.x) / (e->ply - s.y)) - P;
	len = s.len;
	if ((ray = find_sprite_ray(e, angle)) != -0xffff)
		clear_calc_lines(e, ray, len);
}
