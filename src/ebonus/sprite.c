/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 03:44:10 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/16 03:48:26 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include <stdio.h>

#define EBAN ((double)e->rex / (double)e->rey)
#define MAP_LEN (double)(e->msx >= e->msy ? e->msx * 1.42 : e->msy * 1.42)

void	draw_sprite_line(t_eng *e, t_xpm *xpm, int *d, float shade)
{
	const int		u = d[0];
	const double	r = d[1] - u;
	unsigned char	*clr;
	unsigned int	shaded;

	if (d[0] < 0)
		d[0] = 0;
	if (d[1] >= e->rey)
		d[1] = e->rey;
	while (d[0] < d[1])
	{
		clr = get_pafxmp(xpm, d[3], (u - d[0]) / r);
		if (clr[2] || clr[1] || clr[0])
		{
			shaded = ((unsigned char)(clr[2] * shade) << 16) +
					((unsigned char)(clr[1] * shade) << 8) +
					(unsigned char)(clr[0] * shade);
			while (d[0] < d[1] && get_pafxmp(xpm, d[3], (u - d[0]) / r) <= clr)
				put_pixel_to_img(&e->mdg, d[2], d[0]++, shaded);
		}
		else
			while (d[0] < d[1] && get_pafxmp(xpm, d[3], (u - d[0]) / r) <= clr)
				d[0]++;
	}
}

void	calc_lines(t_eng *e, int xx, double len)
{
	int		height;
	float	shade;
	int		d[4];
	int		i;

	if (e->fov < P * 1.5)
		len = len * fabs(cos(e->ray[xx]));
	height = (int)(e->rey / len * (P * 0.31 / e->fov) * EBAN);
	if ((shade = 1 - len / (MAP_LEN / 4)) < 0)
		shade = 0;
	d[0] = -height * 0.5 + e->rey * 0.5 * e->plb + e->height;
	d[1] = +height * 0.5 + e->rey * 0.5 * e->plb + e->height;
	d[2] = xx - height / 2;
	d[3] = 0;
	if (len > 0.25 && !(i = 0))
		while (i < height)
		{
			if (d[2] >= 0 && d[2] < e->rex && e->dst[d[2]] > len &&
					is_drawable_line(&e->tex.sp, d[3]))
				draw_sprite_line(e, &e->tex.sp, d, shade);
			d[0] = -height * 0.5 + e->rey * 0.5 * e->plb + e->height;
			d[1] = +height * 0.5 + e->rey * 0.5 * e->plb + e->height;
			d[3] = e->tex.sp.w * i++ / height * 4;
			d[2]++;
		}
}

int		find_sprite_ray(t_eng *e, double angle)
{
	double	y;
	int		i;

	i = -(e->rex / 2);
	if (angle >= P * 2)
		angle -= P * 2;
	else if (angle < 0)
		angle += P * 2;
	y = angle - e->pla;
	if (y > P)
		y -= P * 2;
	else if (y < -P)
		y += P * 2;
	while (i < e->rex + e->rex / 2)
	{
		if (y >= e->ray[i] && y < e->ray[i + 1])
			return (e->rex - i);
		i++;
	}
	return (-0xffff);
}

int		draw_sprite(t_eng *e, t_spr s)
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
		calc_lines(e, ray, len);
	return (1);
}

/*
**	void	sprites_to_map(void *img, t_eng *e, int size, t_spr s)
**	{
**		t_ab c;
**		double	angle;
**
**		if (e->ply > s.y)
**			angle = atan((e->plx - s.x) / (e->ply - s.y));
**		else
**			angle = atan((e->plx - s.x) / (e->ply - s.y)) - P;
**		c.xa = (s.x - PHSZ) * size;
**		c.ya = (s.y - PHSZ) * size;
**		c.xe = (s.x + PHSZ) * size;
**		c.ye = (s.y + PHSZ) * size;
**		draw_full_rectangle(img, c, 0xdd0000ff);
**		draw_rectangle(img, c, 0x0000ff);
**		c.xa = s.x * size + sin(angle) * size * PSZ;
**		c.ya = s.y * size + cos(angle) * size * PSZ;
**		draw_arrow(img, c, size, angle, 0x0088ff);
**	}
*/

/*
**	Map + Debug
**
**	print_spritess(*e);
**
**	if (e->mmp.mode == -1 || e->mmp.mode == 2 )
**		sprites_to_map(&(e->rma.img), e, e->mmp.fullb, *crnt);
**	else if (e->mmp.mode == 0)
**		sprites_to_map(&(e->rmi.img), e, e->mmp.minib, *crnt);
**	else if (e->mmp.mode == 1)
**		sprites_to_map(&(e->rma.img), e, e->mmp.fullb, *crnt);
*/

/*
**	crnt = e->spr;
**		while (crnt)
**		{
**			clear_sprite(e, *crnt);
**			crnt = crnt->next;
**		}
*/

void	sprites(t_eng *e)
{
	t_spr *crnt;

	get_sprite_distance(e);
	sort_sprites(e);
	crnt = e->spr;
	while (crnt && draw_sprite(e, *crnt))
		crnt = crnt->next;
	if (e->mode != 2)
		mlx_put_image_to_window(e->mlx, e->win, e->mdg.img, 0, 0);
	else
	{
		write(1, "Please Wait, bmp writing\n", 25);
		mlx_do_sync(e->mlx);
		crnt = e->spr;
		while (crnt && draw_sprite(e, *crnt))
			crnt = crnt->next;
		mlx_do_sync(e->mlx);
		save_image_as_bmp(&e->mdg, "Screenshot");
		write(1, "Succesful!!!\n", 13);
		exit(0);
	}
}
