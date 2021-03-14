/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 22:03:00 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/14 13:55:32 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	vertical_ray(t_eng *e, t_ray *r)
{
	if (r->a > P)
	{
		r->vx = ((int)e->plx);
		r->vy = (e->ply - (e->plx - (int)e->plx) * (1 / tan(r->a)));
		r->vc = -1 / (e->plx - (int)e->plx) * (e->ply - r->vy);
		while ((int)r->vx > 0 && (int)r->vy > 0 && (int)r->vy < e->msy &&
										e->m[(int)r->vy][(int)r->vx - 1] != '1')
		{
			r->vx--;
			r->vy += r->vc;
		}
	}
	else
	{
		r->vx = ((int)e->plx + 1);
		r->vy = (e->ply - ((int)e->plx + 1 - e->plx) * (1 / -tan(r->a)));
		r->vc = -1 / ((int)e->plx + 1 - e->plx) * (e->ply - r->vy);
		while ((int)r->vx < e->msx && (int)r->vy > 0 && (int)r->vy < e->msy &&
										e->m[(int)r->vy][(int)r->vx] != '1')
		{
			r->vx++;
			r->vy += r->vc;
		}
	}
}

void	horisontal_ray(t_eng *e, t_ray *r)
{
	if (r->a >= P * 0.5 && r->a < P * 1.5)
	{
		r->hx = (e->plx - (e->ply - (int)e->ply) * tan(r->a));
		r->hy = ((int)e->ply);
		r->hc = -1 / (e->ply - (int)e->ply) * (e->plx - r->hx);
		while ((int)r->hx > 0 && (int)r->hx < e->msx && (int)r->hy > 0 &&
										e->m[(int)r->hy - 1][(int)r->hx] != '1')
		{
			r->hx += r->hc;
			r->hy--;
		}
	}
	else
	{
		r->hx = (e->plx - ((int)e->ply + 1 - e->ply) * -tan(r->a));
		r->hy = ((int)e->ply + 1);
		r->hc = -1 / ((int)e->ply + 1 - e->ply) * (e->plx - r->hx);
		while ((int)r->hx > 0 && (int)r->hx < e->msx && (int)r->hy < e->msy &&
										e->m[(int)r->hy][(int)r->hx] != '1')
		{
			r->hx += r->hc;
			r->hy++;
		}
	}
}

void	raycastings(t_eng *e, t_ray r)
{
	if (r.a >= P * 2)
		r.a -= P * 2;
	else if (r.a < 0)
		r.a += P * 2;
	raycasting_len(e, &r);
	if (r.vl >= r.hl)
	{
		if (r.a > P * 0.5 && r.a < P * 1.5)
			calc_line(e, &r, &e->tex.no,
				abs((int)(e->tex.no.w * (r.hx - (int)r.hx))));
		else
			calc_line(e, &r, &e->tex.so,
				abs((int)(e->tex.so.w * (r.hx - (int)r.hx - 1))));
		e->dst[e->rex - r.c] = r.hl;
	}
	else
	{
		if (r.a > P)
			calc_line(e, &r, &e->tex.we,
				abs((int)(e->tex.we.w * (r.vy - (int)r.vy - 1))));
		else
			calc_line(e, &r, &e->tex.ea,
				abs((int)(e->tex.ea.w * (r.vy - (int)r.vy))));
		e->dst[e->rex - r.c] = r.vl;
	}
}

void	init_rays(t_eng *e, t_ray r)
{
	r.a = e->pla;
	r.c = e->rex / 2;
	while (r.c >= -(e->rex / 2))
	{
		e->ray[r.c] = r.a - e->pla;
		if (e->fov < P * 1.5)
			r.a -= r.s * cos(e->pla - r.a);
		else
			r.a -= r.s;
		r.c--;
	}
	r.c = e->rex / 2 + 1;
	r.a = e->pla;
	while (r.c < e->rex + e->rex / 2)
	{
		e->ray[r.c] = r.a - e->pla;
		if (e->fov < P * 1.5)
			r.a += r.s * cos(e->pla - r.a);
		else
			r.a += r.s;
		r.c++;
	}
}

void	raycasting_len(t_eng *e, t_ray *r)
{
	vertical_ray(e, r);
	horisontal_ray(e, r);
	r->vl = sqrt((e->plx - r->vx) * (e->plx - r->vx) +
				(e->ply - r->vy) * (e->ply - r->vy));
	r->hl = sqrt((e->plx - r->hx) * (e->plx - r->hx) +
				(e->ply - r->hy) * (e->ply - r->hy));
}
