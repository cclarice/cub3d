/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:38:26 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/01 17:31:02 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

unsigned int	get_pixel_from_xmp(t_xpm *xpm, double xx, double yy)
{
	unsigned int color;
	char *dst;
	int x;
	int y;

	xx = fabs(xx);
	yy = fabs(yy);
	x = (int)(xpm->w * xx);
	y = (int)(xpm->h * yy);
	dst = NULL;
	dst = xpm->ptr + (y * xpm->length + x * (xpm->bpp / 8));
	color = *(unsigned int*)dst;
	return (color);
}

void	ver_line(t_eng *e, int x, int *draw, t_xpm *xpm, double xx, double shade)
{
	const int	up = draw[0];
	const int	down = draw[1];
	const int	diapazon = down - up;
	unsigned int color = (int)shade;

	if (draw[0] < 0)
		draw[0] = 0;
	if (draw[1] >= e->rey)
		draw[1] = e->rey - 1;
	while (draw[0] < draw[1])
	{
		color = get_pixel_from_xmp(xpm, xx, (up - (double)draw[0]) / (double)diapazon);
		put_pixel_to_img(&e->mdg, x, draw[0],
			((int)((get_red(color) >> 16) * shade) << 16) + 
			((int)((get_green(color) >> 8) * shade) << 8) +
			(int)(get_blue(color) * shade));
		draw[0]++;
	}
}

void	calc_line(t_eng *e, double walldist, int x, int type, double dif)
{
	//Calculate height of line to draw on screen
	const int height = (int)(e->rey / walldist * (P * 0.5 / e->fov));
	//calculate lowest and highest pixel to fill in current stripe
	int draw[2];

	draw[0] = -height * 0.5 + e->rey * 0.5 * e->plb;
	draw[1] =  height * 0.5 + e->rey * 0.5 * e->plb;
	if (type == 1)
		ver_line(e, e->rex - x, draw, &e->tex.no, 1 + dif, 1 - walldist / e->msx);
	else if (type == 2)
		ver_line(e, e->rex - x, draw, &e->tex.we, dif, 1 - walldist / e->msx);
	else if (type == 3)
		ver_line(e, e->rex - x, draw, &e->tex.ea, 1 + dif, 1 - walldist / e->msx);
	else
		ver_line(e, e->rex - x, draw, &e->tex.so, dif, 1 - walldist / e->msx);
}

void	raycasting(t_eng *e)
{
	t_ray	r;
	double	a;
	double	one;
	int		cur;
	double	dif;

	cur = e->rex / 2;
	a = e->pla;
	one = (e->fov / (e->rex));
	dif = e->pla + e->fov / 2;
	fill_img_with_color(&(e->mdg), e->rex, e->rey, 0x0);
	while (cur > 0)
	{
		if (a >= P * 2)
			a -= P * 2;
		else if (a < 0)
			a += P * 2;
		raycasting_len(e, &r, a);
		if (r.ve[4] > r.ho[4])
			calc_line(e, r.ho[4] * fabs(cos(e->pla - a)), cur, (a > P * 0.5 && a < P * 1.5) ? 2 : 3, (int)r.ho[0] - r.ho[0]);
		else
			calc_line(e, r.ve[4] * fabs(cos(e->pla - a)), cur, (a > P) ? 1 : 0, (int)r.ve[1] - r.ve[1]);
		a -= one * cos(e->pla - a);
		cur--;
	}
	cur = e->rex / 2;
	a = e->pla;
	while (cur < e->rex)
	{
		if (a >= P * 2)
			a -= P * 2;
		else if (a < 0)
			a += P * 2;
		raycasting_len(e, &r, a);
		if (r.ve[4] > r.ho[4])
			calc_line(e, r.ho[4] * fabs(cos(e->pla - a)), cur, (a > P * 0.5 && a < P * 1.5) ? 2 : 3, (int)r.ho[0] - r.ho[0]);
		else
			calc_line(e, r.ve[4] * fabs(cos(e->pla - a)), cur, (a > P) ? 1 : 0, (int)r.ve[1] - r.ve[1]);
		a += one * cos(e->pla - a);
		cur++;
	}
	draw_dot(&(e->rma), e->plx * e->mmp.fullb, e->ply * e->mmp.fullb, 0xffffff);
	draw_dot(&(e->rma), e->crx * e->mmp.fullb, e->cry * e->mmp.fullb, 0xff0000);
	draw_dot(&(e->rma), e->clx * e->mmp.fullb, e->cly * e->mmp.fullb, 0x00ff00);
}