/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 20:00:59 by cclarice          #+#    #+#             */
/*   Updated: 2021/02/21 00:52:10 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

/*
**		Draw Line
**  A
**	 ####
**       ####
**           ####    
**               ####
**                   B
*/

void		draw_line(t_img *img, t_ab s, int color)
{
	const int dx = abs(s.xe - s.xa);
	const int dy = abs(s.ye - s.ya);
	const int sx = s.xa < s.xe ? 1 : -1;
	const int sy = s.ya < s.ye ? 1 : -1;
	int error = dx - dy;
	int error2;

	put_pixel_to_img(img, s.xe, s.ye, color);
	while (s.xa != s.xe || s.ya != s.ye) 
	{
		put_pixel_to_img(img, s.xa, s.ya, color);
		error2 = error * 2;
		if (error2 > -dy) 
		{
			error -= dy;
			s.xa += sx;
		}
		if (error2 < dx) 
		{
			error += dx;
			s.ya += sy;
		}
	}
}

/*
**		Draw Rectangle
** A
**	################
**  #              #
**  ################
**                  B
*/

void	draw_rectangle(t_img *img, t_ab s, int color)
{
	int	x;
	int	y;

	x = s.xa;
	y = s.ya;
	while (x != s.xe)
		put_pixel_to_img(img, x++, y, color);
	while (y != s.ye)
		put_pixel_to_img(img, x, y++, color);
	while (x != s.xa)
		put_pixel_to_img(img, x--, y, color);
	while (y != s.ya)
		put_pixel_to_img(img, x, y--, color);
}

/*
**		Draw Full Rectangle
**
** A
**	################
**  ################
**  ################
**                  B
*/

void	draw_full_rectangle(t_img *img, t_ab s, int color)
{
	const int oldx = s.xa;

	while (s.ya <= s.ye)
	{
		while (s.xa <= s.xe)
		{
			put_pixel_to_img(img, s.xa, s.ya, color);
			s.xa++;
		}
		s.xa = oldx;
		s.ya++;
	}
}
/*
**		Draw Dot
**
**   *#*
**   #A#
**   *#*
*/

void	draw_dot(t_img *img, int x, int y, int color)
{
	put_pixel_to_img(img, x + 1, y + 1, color + 0xaa000000);
	put_pixel_to_img(img, x, y + 1, color);
	put_pixel_to_img(img, x - 1, y + 1, color + 0xaa000000);
	put_pixel_to_img(img, x + 1, y, color);
	put_pixel_to_img(img, x, y, color);
	put_pixel_to_img(img, x - 1, y, color);
	put_pixel_to_img(img, x + 1, y - 1, color + 0xaa000000);
	put_pixel_to_img(img, x, y - 1, color);
	put_pixel_to_img(img, x - 1, y - 1, color + 0xaa000000);
}

/*
**		Draw Arrow
**
**         #
**          ##
**		#######A ----->a
**		    ##
**		   #
*/

void	draw_arrow(t_img *img, t_ab s, int size, double angle, int color)
{
	int salo;

	salo = size * PSZ * 0.25;
	s.xe = sin(angle + P * 1.25) * salo + s.xa;
	s.ye = cos(angle + P * 1.25) * salo + s.ya;
	draw_line(img, s, color);
	s.xe = sin(angle + P) * salo + s.xa;
	s.ye = cos(angle + P) * salo + s.ya;
	draw_line(img, s, color);
	s.xe = sin(angle - P * 1.25) * salo + s.xa;
	s.ye = cos(angle - P * 1.25) * salo + s.ya;
	draw_line(img, s, color);
}
