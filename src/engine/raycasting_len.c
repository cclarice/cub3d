/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 15:57:51 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/01 18:52:23 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	vertical_ray(t_eng *e, t_ray *r, double a)
{
	if (a > P)
	{
		r->ve[0] = ((int)e->plx);
		r->ve[1] = (e->ply - (e->plx - (int)e->plx) * (1 / tan(a)));
		r->ve[2] = -1;
		r->ve[3] = -1 / (e->plx - (int)e->plx) * (e->ply - r->ve[1]);
		while ((int)r->ve[0] >= 0 && (int)r->ve[0] < e->msx && (int)r->ve[1] >= 0 && (int)r->ve[1] < e->msy && e->m[(int)r->ve[1]][(int)r->ve[0] - 1] != '1')
		{
			r->ve[1] += r->ve[3];
			r->ve[0] += r->ve[2];
		}
	}
	else
	{
		r->ve[0] = ((int)e->plx + 1);
		r->ve[1] = (e->ply - ((int)e->plx + 1 - e->plx) * (1 / -tan(a)));
		r->ve[2] = 1;
		r->ve[3] = -1 / ((int)e->plx + 1 - e->plx) * (e->ply - r->ve[1]);
		while ((int)r->ve[0] >= 0 && (int)r->ve[0] < e->msx && (int)r->ve[1] >= 0 && (int)r->ve[1] < e->msy && e->m[(int)r->ve[1]][(int)r->ve[0]] != '1')
		{
			r->ve[1] += r->ve[3];
			r->ve[0] += r->ve[2];
		}
	}
	r->ve[4] = sqrt((e->plx - r->ve[0]) * (e->plx - r->ve[0]) + (e->ply - r->ve[1]) * (e->ply - r->ve[1]));
}

void	horisontal_ray(t_eng *e, t_ray *r, double a)
{
	if (a > P * 0.5 && a < P * 1.5)
	{
		r->ho[0] = (e->plx - (e->ply - (int)e->ply) * tan(a));
		r->ho[1] = ((int)e->ply);
		r->ho[2] = -1 / (e->ply - (int)e->ply) * (e->plx - r->ho[0]);
		r->ho[3] = -1;
		while ((int)r->ho[0] >= 0 && (int)r->ho[0] < e->msx && (int)r->ho[1] >= 0 && (int)r->ho[1] < e->msy && e->m[(int)r->ho[1] - 1][(int)r->ho[0]] != '1')
		{
			r->ho[0] += r->ho[2];
			r->ho[1] += r->ho[3];
		}
	}
	else
	{
		r->ho[0] = (e->plx - ((int)e->ply + 1 - e->ply) * -tan(a));
		r->ho[1] = ((int)e->ply + 1);
		r->ho[2] = -1 / ((int)e->ply + 1 - e->ply) * (e->plx - r->ho[0]);
		r->ho[3] = 1;
		while ((int)r->ho[0] >= 0 && (int)r->ho[0] < e->msx && (int)r->ho[1] >= 0 && (int)r->ho[1] < e->msy && e->m[(int)r->ho[1]][(int)r->ho[0]] != '1')
		{
			r->ho[0] += r->ho[2];
			r->ho[1] += r->ho[3];
		}
	}
	r->ho[4] = sqrt((e->plx - r->ho[0]) * (e->plx - r->ho[0]) + (e->ply - r->ho[1]) * (e->ply - r->ho[1]));
}

//void	ray_fire()
//{
//	int hit;
//	const int ve = (a > P) ? 1 : 0;
//	const int ho = (a > P * 0.5 && a < P * 1.5) ? 1 : 0;
//
//	hit = 0;
//	while (!hit)
//	{
//		if (r->ve < ho)
//		{
//			r->ve[1] += r->ve[3];
//			r->ve[0] += r->ve[2];
//			if (e->m[(int)r->ve[1]][(int)r->ve[0] - ve] != '1')
//			{
//				hit++;
//				r->ve[4] = sqrt((e->plx - r->ve[0]) * (e->plx - r->ve[0]) + (e->ply - r->ve[1]) * (e->ply - r->ve[1]));
//			}
//		}
//		else
//		{
//			r->ho[0] += r->ho[2];
//			r->ho[1] += r->ho[3];
//			if (e->m[(int)r->ve[1]][(int)r->ve[0] - ho] != '1')
//			{
//				hit++;
//				r->ho[4] = sqrt((e->plx - r->ho[0]) * (e->plx - r->ho[0]) + (e->ply - r->ho[1]) * (e->ply - r->ho[1]));
//			}
//		}
//	}
//}

void	ray_to_map(t_eng *e, t_ray *r)
{
	t_ab s;

	s.xa = e->plx * e->mmp.fullb;
	s.ya = e->ply * e->mmp.fullb;
	if (r->ve[4] > r->ho[4] && r->ho[0] > 0.1 && r->ho[1] > 0.1 && r->ho[0] < e->msx - 0.1)
	{
		s.xe = r->ho[0] * e->mmp.fullb;
		s.ye = r->ho[1] * e->mmp.fullb;
		draw_line(&(e->rma), s, 0xaaffffff);
		draw_dot(&(e->rma), (r->ho[0]) * e->mmp.fullb, (r->ho[1]) * e->mmp.fullb, 0xffffff);
	}
	else if (r->ve[0] > 0.1 && r->ve[1] > 0.1 && r->ve[1] < e->msy - 0.1)
	{
		s.xe = r->ve[0] * e->mmp.fullb;
		s.ye = r->ve[1] * e->mmp.fullb;
		draw_line(&(e->rma), s, 0xaaffffff);
		draw_dot(&(e->rma), r->ve[0] * e->mmp.fullb, r->ve[1] * e->mmp.fullb, 0xffffff);
	}
}

void	raycasting_len(t_eng *e, t_ray *r, double a)
{
	vertical_ray(e, r, a);
	horisontal_ray(e, r, a);
	if (e->mmp.mode == 2)
		ray_to_map(e, r);
}