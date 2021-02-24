/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 02:39:11 by cclarice          #+#    #+#             */
/*   Updated: 2021/02/24 08:21:33 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

/*
**	r.vl1[0] = ((int)x);
**	r.vl1[1] = (y - (x - (int)x) * (1 / tan(angle)));
**	r.vl2[0] = ((int)x + 1);
**	r.vl2[1] = (y - ((int)x + 1 - x) * (1 / -tan(angle)));
**	r.vc1[0] = (x - (y - (int)y) * tan(angle));
**	r.vc1[1] = ((int)y);
**	r.vc2[0] = (x - ((int)y + 1 - y) * -tan(angle));
**	r.vc2[1] = ((int)y + 1);
*/

void	*get_pixel_from_xmp(t_xpm *xpm, int x, int y)
{
	return (xpm->img + (y * xpm->w + x * (xpm->h / 6)));
}

void	put_texture_to_terminal(t_xpm *xpm)
{
	int x;
	int y;
	char *img;
	char *color;

	x = 0;
	y = 0;
	img = (char *)xpm->img;
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	while (y < xpm->h)
	{
		while (x < xpm->w)
		{
			color = (img + (y * xpm->h + x * (xpm->w / 6)));
			ft_printf("\033[38;2;%d;%d;%dm##\033[0m", color[3], color[2], color[1]);
			x++;
		}
		y++;
		x = 0;
		write(1, "\n", 1);
	}
	//unsigned int *color;
	//int *img;
	//int a;
	//int b;
	//int i;
//
	//a = 0;
	//b = 0;
	//i = 0;
	//while (a < xpm->h)
	//{
	//	while (b < xpm->w)
	//	{
	//		color = *(unsigned int*)(xpm->img + (a * xpm->w + b * (xpm->h / 6)));
	//		ft_printf("%.8X", color[0]);
	//		ft_printf("\033[38;5;%d;%d;%dm\u2588\u2588\033[0m", get_red(color), get_green(color), get_blue(color));
	//		b++;
	//	}
	//	b = 0;
	//	++a;
	//	write(1, "\n", 1);
	//}
	//printf("[\033[38;2;%d;%d;%dm\u2588\u2588123456\033[0m, %d, %d]\n", get_red(color), get_green(color), get_blue(color), xpm.w, xpm.h);
}

void	ray_len(t_eng *e, t_ray *r, double a)
{
	r->vel[0] = ((int)e->plx);
	r->vel[1] = (e->ply - (e->plx - (int)e->plx) * (1 / tan(a)));
	r->ver[0] = ((int)e->plx + 1);
	r->ver[1] = (e->ply - ((int)e->plx + 1 - e->plx) * (1 / -tan(a)));
	r->hou[0] = (e->plx - (e->ply - (int)e->ply) * tan(a));
	r->hou[1] = ((int)e->ply);
	r->hod[0] = (e->plx - ((int)e->ply + 1 - e->ply) * -tan(a));
	r->hod[1] = ((int)e->ply + 1);
	r->vl[0] = fabs(r->vel[0] - r->ver[0]);
	r->vl[1] = fabs(r->vel[1] - r->ver[1]);
	r->hl[0] = fabs(r->hou[0] - r->hod[0]);
	r->hl[1] = fabs(r->hou[1] - r->hod[1]);
	if (a >= P)
	{
		r->vr[0] = r->vel[0];
		r->vr[1] = r->vel[1];
	}
	else
	{
		r->vr[0] = r->ver[0];
		r->vr[1] = r->ver[1];
	}
	if (a >= P * 0.5 && a <= P * 1.5)
	{
		r->hr[0] = r->hou[0];
		r->hr[1] = r->hou[1];
	}
	else
	{
		r->hr[0] = r->hod[0];
		r->hr[1] = r->hod[1];
	}
	if (a > P * 0.5 && a < P * 1.5)
		while ((int)r->hr[0] >= 0 && (int)r->hr[0] < e->msx && (int)r->hr[1] >= 0 && (int)r->hr[1] < e->msy && e->m[(int)r->hr[1] - 1][(int)r->hr[0]] != '1')
		{
			if (a > P)
				r->hr[0] -= r->hl[0];
			else
				r->hr[0] += r->hl[0];
			r->hr[1] -= r->hl[1];
		}
	else
		while ((int)r->hr[0] >= 0 && (int)r->hr[0] < e->msx && (int)r->hr[1] >= 0 && (int)r->hr[1] < e->msy && e->m[(int)r->hr[1]][(int)r->hr[0]] != '1')
		{
			if (a > P)
				r->hr[0] -= r->hl[0];
			else
				r->hr[0] += r->hl[0];
			r->hr[1] += r->hl[1];
		}
	if (a > P)
		while ((int)r->vr[0] >= 0 && (int)r->vr[0] < e->msx && (int)r->vr[1] >= 0 && (int)r->vr[1] < e->msy && e->m[(int)r->vr[1]][(int)r->vr[0] - 1] != '1')
		{
			if (a > P * 0.5 && a < P * 1.5)
				r->vr[1] -= r->vl[1];
			else
				r->vr[1] += r->vl[1];
			r->vr[0] -= r->vl[0];
		}
	else
		while ((int)r->vr[0] >= 0 && (int)r->vr[0] < e->msx && (int)r->vr[1] >= 0 && (int)r->vr[1] < e->msy && e->m[(int)r->vr[1]][(int)r->vr[0]] != '1')
		{
			if (a > P * 0.5 && a < P * 1.5)
				r->vr[1] -= r->vl[1];
			else
				r->vr[1] += r->vl[1];
			r->vr[0] += r->vl[0];
		}
	r->vl[2] = sqrt((e->crx - r->vr[0]) * (e->crx - r->vr[0]) + (e->cry - r->vr[1]) * (e->cry - r->vr[1]));
	r->hl[2] = sqrt((e->crx - r->hr[0]) * (e->crx - r->hr[0]) + (e->cry - r->hr[1]) * (e->cry - r->hr[1]));
	draw_dot(&(e->rma), e->crx * e->mmp.fullb, e->cry * e->mmp.fullb, 0x000fff);
	e->crx += e->cax;
	e->cry += e->cay;
}

/*
**	Struct Raycasting
**
**	My own metod of raycasting
**	Explained on Russian in explaination.
**
**	hou - Upper Horizontal
**	hod - Lower Horizontal
**	vel - Left  Vertical
**	ver - Right Vertical
**	hl  - Lenght bethew Upper and Lower Horizontal
**	vl  - Lenght bethew Left  and Right Vertical
**	hr  - Current Horizontal Ray Position
**	vr  - Current Vertical   Ray Position
*/

void	ray_display_to_map(t_eng *e, t_ray *r)
{
	t_ab s;

	s.xa = e->plx * e->mmp.fullb;
	s.ya = e->ply * e->mmp.fullb;
	//if (r->vel[0] > 0 && r->vel[1] > 0 && r->vel[1] < e->msy)
	//	draw_dot(&(e->rma), r->vel[0] * e->mmp.fullb, r->vel[1] * e->mmp.fullb, Maroon);
	//if (r->ver[0] > 0 && r->ver[1] > 0 && r->ver[1] < e->msy)
	//	draw_dot(&(e->rma), r->ver[0] * e->mmp.fullb, r->ver[1] * e->mmp.fullb, Teal);
	//if (r->hou[0] > 0 && r->hou[1] > 0 && r->hou[0] < e->msx)
	//	draw_dot(&(e->rma), r->hou[0] * e->mmp.fullb, r->hou[1] * e->mmp.fullb, Navy);
	//if (r->hod[0] > 0 && r->hod[1] > 0 && r->hod[0] < e->msx)
	//	draw_dot(&(e->rma), r->hod[0] * e->mmp.fullb, r->hod[1] * e->mmp.fullb, Purple);
	//printf("[ v: %f | h: %f ]\n",r->vl[2], r->hl[2]);
	if (r->vl[2] > r->hl[2] && r->hr[0] > 0 && r->hr[1] > 0 && r->hr[0] < e->msx)
	{
		s.xe = r->hr[0] * e->mmp.fullb;
		s.ye = r->hr[1] * e->mmp.fullb;
		draw_line(&(e->rma), s, 0xaaffffff);
		draw_dot(&(e->rma), r->hr[0] * e->mmp.fullb, r->hr[1] * e->mmp.fullb, 0xffffff);
	}
	else if (r->vr[0] > 0 && r->vr[1] > 0 && r->vr[1] < e->msy)
	{
		s.xe = r->vr[0] * e->mmp.fullb;
		s.ye = r->vr[1] * e->mmp.fullb;
		draw_line(&(e->rma), s, 0xaaffffff);
		draw_dot(&(e->rma), r->vr[0] * e->mmp.fullb, r->vr[1] * e->mmp.fullb, 0xffffff);
	}
}

void	ver_line(t_eng *e, int x, int drawStart, int drawEnd, int color)
{
	while (drawStart < drawEnd)
	{
		put_pixel_to_img(&e->mdg, x, drawStart, color);
		drawStart++;
	}
}

void	calc_line(t_eng *e, double walldist, int x, int type)
{
	//Calculate height of line to draw on screen
	const int height = (int)(e->rey / walldist * (P * 0.5 / e->fov));
	//calculate lowest and highest pixel to fill in current stripe
	int start;
	int end;

	start = -height * 0.5 + e->rey * 0.5;
	end = height * 0.5 + e->rey * 0.5;
	start < -e->rey / 16 ? start = -e->rey / 16 : 0;
	end >= e->rey ? end = e->rey - 1 - e->rey / 16 : 0;
	if (type == 1)
		ver_line(e, e->rex - x, start + e->rey / 16, end + e->rey / 16, 0xFFFF00 - 0x010100 * (int)(walldist * 16));
	else if (type == 2)
		ver_line(e, e->rex - x, start + e->rey / 16, end + e->rey / 16, 0xFF0000 - 0x010000 * (int)(walldist * 16));
	else if (type == 3)
		ver_line(e, e->rex - x, start + e->rey / 16, end + e->rey / 16, 0x00FFFF - 0x000101 * (int)(walldist * 16));
	else
		ver_line(e, e->rex - x, start + e->rey / 16, end + e->rey / 16, 0xFF00FF - 0x010001 * (int)(walldist * 16));
}

//void	cam(t_eng *e)
//{
//	e->crx = PHSZ * sin(e->pla + P / 2) + e->plx;
//	e->cry = PHSZ * cos(e->pla + P / 2) + e->ply;
//	e->clx = PHSZ * sin(e->pla - P / 2) + e->plx;
//	e->cly = PHSZ * cos(e->pla - P / 2) + e->ply;
//	draw_dot(&(e->rma), e->plx * e->mmp.fullb, e->ply * e->mmp.fullb, 0xffffff);
//	draw_dot(&(e->rma), e->crx * e->mmp.fullb, e->cry * e->mmp.fullb, 0xff0000);
//	draw_dot(&(e->rma), e->clx * e->mmp.fullb, e->cly * e->mmp.fullb, 0x00ff00);
//}

void	raycasting(t_eng *e)
{
	t_ray r;
	double a;
	double one;
	int i;

	i = 0;

	one = e->fov / (e->rex);
	a = e->pla - e->fov / 2 + one / 2;
	e->crx = (PHSZ) * sin(a) + e->plx;
	e->cry = (PHSZ) * cos(a) + e->ply;
	e->clx = (PHSZ) * sin(a + e->fov) + e->plx;
	e->cly = (PHSZ) * cos(a + e->fov) + e->ply;
	e->cax = (e->clx - e->crx) / e->rex;
	e->cay = (e->cly - e->cry) / e->rex;
	e->clx = e->crx;
	e->cly = e->cry;
	fill_img_with_color(&(e->mdg), e->rex, e->rey, 0x0);
	while (i < e->rex + e->fov / 2)
	{
		if (a >= P * 2)
			a -= P * 2;
		else if(a < 0)
			a += P * 2;
		ray_len(e, &r, a);
		ray_display_to_map(e, &r);
		if (r.vl[2] > r.hl[2])
		{
			r.hl[2] *= fabs(cos((e->pla - a) / 2));
			calc_line(e, r.hl[2], i, (a > P * 0.5 && a < P * 1.5) ? 2 : 3);
		}
		else
		{
			r.vl[2] *= fabs(cos((e->pla - a) / 2));
			calc_line(e, r.vl[2], i, (a > P) ? 1 : 0);
		}
		i++;
		a += one;
	}
	put_texture_to_terminal(&e->tex.no);
	draw_dot(&(e->rma), e->plx * e->mmp.fullb, e->ply * e->mmp.fullb, 0xffffff);
	draw_dot(&(e->rma), e->crx * e->mmp.fullb, e->cry * e->mmp.fullb, 0xff0000);
	draw_dot(&(e->rma), e->clx * e->mmp.fullb, e->cly * e->mmp.fullb, 0x00ff00);
	//printf("[i %f]\n", e->fov * (180 / P));

	//a = e->pla;
	//ray_len(e, &r, a);
	//ray_display_to_map(e, &r, a);
}
