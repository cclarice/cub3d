/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 07:16:23 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/14 09:49:31 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void			cub_get_mapsize(char **map, int *x, int *y)
{
	x[0] = 0;
	y[0] = 0;
	while (map[0][x[0]] != '\0')
		x[0]++;
	while (map[y[0]][0] != '\0')
		y[0]++;
}

void			put_pixel_to_img(t_img *img, int x, int y, int color)
{
	*(unsigned int*)(img->addr + (y * img->len + x * 4)) = color;
}

unsigned int	get_pixel_from_img(t_img *img, int x, int y)
{
	return (*(unsigned int*)(img->addr + y * img->len + x * 4));
}

unsigned int	get_pixel_from_xmp(t_xpm *xpm, int x, double yy)
{
	return (*(unsigned int*)(xpm->ptr + abs((int)(xpm->h * yy)) * xpm->length +
		x * 4));
}

void			fill_img_with_color(void *img, int x, int y, int color)
{
	int xx;
	int yy;

	xx = 0;
	yy = 0;
	while (yy < y)
	{
		while (xx < x)
		{
			put_pixel_to_img(img, xx, yy, color);
			xx++;
		}
		xx = 0;
		yy++;
	}
}
