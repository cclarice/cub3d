/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:54:40 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/14 13:53:39 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

#define EBAN ((double)e->rex / (double)e->rey)
#define MAP_LEN (double)(e->msx >= e->msy ? e->msx * 1.42 : e->msy * 1.42)

unsigned char	*get_pafxmp(t_xpm *xpm, int x, double yy)
{
	return
	((unsigned char *)xpm->ptr + abs((int)(xpm->h * yy)) * xpm->length + x);
}

void			draw_wall(t_eng *e, t_xpm *xpm, int *d, float shade)
{
	const int		up = d[0];
	const int		range = d[1] - up;
	unsigned char	*color;
	unsigned int	shaded;

	if (d[0] < 0)
		d[0] = 0;
	if (d[1] >= e->rey)
		d[1] = e->rey;
	while (d[0] < d[1])
	{
		color = get_pafxmp(xpm, d[3], (up - d[0]) / (float)range);
		shaded = ((unsigned char)(color[2] * shade) << 16) +
				((unsigned char)(color[1] * shade) << 8) +
				(unsigned char)(color[0] * shade);
		while (d[0] < d[1] && get_pafxmp(xpm, d[3],
										(up - d[0]) / (float)range) <= color)
			put_pixel_to_img(&e->mdg, d[2], d[0]++, shaded);
	}
}

void			ver_line(t_eng *e, t_xpm *xpm, int *d, float shade)
{
	int	ceil;

	ceil = d[0] - 1;
	while (ceil >= 0)
	{
		if (get_pixel_from_img(&e->mdg, d[2], ceil) != e->cec)
			put_pixel_to_img(&e->mdg, d[2], ceil--, e->cec);
		else
			ceil--;
	}
	draw_wall(e, xpm, d, shade);
	while (d[0] < e->rey)
	{
		if (get_pixel_from_img(&e->mdg, d[2], d[0]) != e->flc)
			put_pixel_to_img(&e->mdg, d[2], d[0]++, e->flc);
		else
			d[0]++;
	}
}

void			calc_line(t_eng *e, t_ray *r, t_xpm *xpm, int xx)
{
	float	wd;
	int		height;
	float	shade;
	int		d[4];

	if (e->fov < P * 1.5)
		wd = (r->vl > r->hl ? r->hl : r->vl) * fabs(cos(e->pla - r->a));
	else
		wd = (r->vl > r->hl ? r->hl : r->vl);
	height = (int)(e->rey / wd * (P * 0.31 / e->fov) * EBAN);
	shade = 1 - wd / MAP_LEN;
	d[0] = -height * 0.5 + e->rey * 0.5 * e->plb;
	d[1] = +height * 0.5 + e->rey * 0.5 * e->plb;
	d[2] = e->rex - r->c - 1;
	d[3] = xx * 4;
	ver_line(e, xpm, d, shade);
}

void			raycasting(t_eng *e)
{
	t_ray	r;

	r.s = e->fov / (e->rex);
	init_rays(e, r);
	r.a = e->pla;
	r.c = 0;
	while (r.c < e->rex)
	{
		r.a = e->ray[r.c] + e->pla;
		raycastings(e, r);
		r.c++;
	}
	sprites(e);
}
