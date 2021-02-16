/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:27:23 by cclarice          #+#    #+#             */
/*   Updated: 2021/02/14 14:30:16 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

/*(b.xo >= b.size - b.trim && b.yo >= b.size - b.trim && e->m[b.y + 1][b.x + 1] != '1') ||
		(b.xo >= b.size - b.trim && b.yo < b.trim && e->m[b.y + 1][b.x - 1] != '1') ||
		(b.xo < b.trim && b.yo >= b.size - b.trim && e->m[b.y - 1][b.x + 1] != '1') ||
		(b.xo < b.trim && b.yo < b.trim && b.y != 0 && b.x != 0 && e->m[b.y - 1][b.x - 1] != '1'))*/

void	put_trim(t_blc b, t_img *img, t_eng *e)
{
	int htrim;

	htrim = b.trim - 1 != 0 ? b.trim - 1 : 1;
	if ((b.x == 0 && b.xo < b.trim) || (b.y == 0 && b.yo < b.trim) ||
		(b.xo < b.trim && e->m[b.y][b.x - 1] != '1') ||
		(b.yo < b.trim && e->m[b.y - 1][b.x] != '1') ||
		(b.xo >= b.size - b.trim && e->m[b.y][b.x + 1] != '1') ||
		(b.yo >= b.size - b.trim && e->m[b.y + 1][b.x] != '1'))
		put_pixel_to_img(img, b.x * b.size + b.xo, b.y * b.size + b.yo, e->mmp.o_clr);
	//else if (b.xo >= b.size - b.trim && b.yo >= b.size - b.trim && e->m[b.y + 1][b.x + 1] != '1')
	//	put_pixel_to_img(img, b.x * b.size + b.xo, b.y * b.size + b.yo, 0xffffff);
	//else if (b.xo >= b.size - b.trim && b.yo >= b.size - b.trim && e->m[b.y + 1][b.x + 1] != '1')
	//	put_pixel_to_img(img, b.x * b.size + b.xo, b.y * b.size + b.yo, 0xffffff);
	else if (b.xo < htrim || b.xo >= b.size - htrim || b.yo >= b.size - htrim || b.yo < htrim)
		put_pixel_to_img(img, b.x * b.size + b.xo, b.y * b.size + b.yo, e->mmp.t_clr);
	else
		put_pixel_to_img(img, b.x * b.size + b.xo, b.y * b.size + b.yo, e->mmp.b_clr);
}

void	put_block(t_blc b, t_img *img, t_eng *e)
{
	while (b.yo < b.size)
	{
		while (b.xo < b.size)
		{			
			if (b.xo < b.trim || b.xo >= b.size - b.trim || b.yo >= b.size - b.trim || b.yo < b.trim)
				put_trim(b, img, e);
			else
				put_pixel_to_img(img, b.x * b.size + b.xo, b.y * b.size + b.yo, e->mmp.b_clr);
			b.xo++;
		}
		b.yo++;
		b.xo = 0;
	}
}

void	put_floor(t_blc b, t_img *img, t_eng *e)
{
	if (b.trim != 1)
		b.trim /= 2;
	while (b.yo < b.size)
	{
		while (b.xo < b.size)
		{			
			if (b.xo < b.trim || b.xo >= b.size - b.trim || b.yo >= b.size - b.trim || b.yo < b.trim)
				put_pixel_to_img(img, b.x * b.size + b.xo, b.y * b.size + b.yo, e->mmp.a_clr);
			else
				put_pixel_to_img(img, b.x * b.size + b.xo, b.y * b.size + b.yo, e->mmp.f_clr);
			b.xo++;
		}
		b.yo++;
		b.xo = 0;
	}
}

void	put_respawn(t_blc b, t_img *img, t_eng *e)
{
	b.trim += b.size / 4;
	b.xo += b.size / 4;
	b.yo += b.size / 4;
	while (b.yo < b.size - b.size / 4)
	{
		while (b.xo < b.size - b.size / 4)
		{
			if (b.xo < b.trim || b.xo >= b.size - b.trim || b.yo >= b.size - b.trim || b.yo < b.trim)
				put_pixel_to_img(img, b.x * b.size + b.xo, b.y * b.size + b.yo, e->mmp.a_clr);
			else
				put_pixel_to_img(img, b.x * b.size + b.xo, b.y * b.size + b.yo, e->mmp.f_clr);
			b.xo++;
		}
		b.yo++;
		b.xo = b.size / 4;
	}
}

void	render_map(t_eng *e, t_img *img, int sizeb)
{
	t_blc	b;

	b.x = 0;
	b.y = 0;
	b.xo = 0;
	b.yo = 0;
	b.size = sizeb;
	b.trim = sizeb / 16 > 3 ? 3 : sizeb / 16;
	b.trim == 0 ? b.trim = 1 : 0;
	while (b.y < e->msy)
	{
		while (b.x < e->msx)
		{
			//ft_printf("[%d | %d]", b.x, b.y);
			if (e->m[b.y][b.x] == '1')
				put_block(b, img, e);
			if (e->m[b.y][b.x] != '1' && e->m[b.y][b.x] != ' ')
				put_floor(b, img, e);
			//if (e->m[b.y][b.x] >= 'E' && e->m[b.y][b.x] <= 'W')
			//	put_respawn(b, img, e);
			b.x++;
		}
		b.x = 0;
		b.y++;
	}
}