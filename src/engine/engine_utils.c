/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 07:16:23 by cclarice          #+#    #+#             */
/*   Updated: 2021/02/14 22:11:01 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	cub_get_mapsize(char **map, int *x, int *y)
{
	x[0] = 0;
	y[0] = 0;
	while (map[0][x[0]] != '\0')
		x[0]++;
    while (map[y[0]][0] != '\0')
    	y[0]++;
}

void	put_pixel_to_img(t_img *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	fill_img_with_color(t_img *img, int x, int y, int color)
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

/*
**void	make_sqrt(t_img *data, t_sqr s, int color)
**{
**	while ()
**    put_pixel_to_img()
**}
*/