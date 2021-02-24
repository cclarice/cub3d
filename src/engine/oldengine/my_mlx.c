/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 02:33:31 by cclarice          #+#    #+#             */
/*   Updated: 2021/02/24 04:15:19 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	put_pixel_to_frame(t_xmp *xpm, int x, int y, int color)
{
    char    *dst;

    dst = xpm->addr + (y * xpm->line_length + x * (xpm->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	put_square_to_image(t_data *img, int x, int y, int color)
{
	int xx;
	int yy;

	xx = 0;
	yy = 0;
	while (yy <= BLOCK - 1)
	{
		while (xx <= BLOCK - 1)
		{
			if (xx != 0 && yy != 0 && xx != BLOCK - 1 && yy != BLOCK - 1)
				put_pixel_to_frame(&img[0], x + xx, y + yy, color & 0x888888);
			else
				put_pixel_to_frame(&img[0], x + xx, y + yy, color);
			xx++;
		}
		xx = 0;
		yy++;
	}
}

void	put_player_to_image(t_data *img, int x, int y, int color)
{
	int xx;
	int yy;

	xx = 0;
	yy = 0;
	while (yy <= BLOCK * PSIZE - 1)
	{
		while (xx <= BLOCK * PSIZE - 1)
		{
			if (xx != 0 && yy != 0 && xx != BLOCK * PSIZE - 1 && yy != BLOCK * PSIZE - 1)
				put_pixel_to_frame(&img[0], x + xx, y + yy, color & 0x444444);
			else
				put_pixel_to_frame(&img[0], x + xx, y + yy, color);
			xx++;
		}
		xx = 0;
		yy++;
	}
}

void	set_img_transparent(t_data *img, int x, int y)
{
	int xx;
	int yy;

	xx = 0;
	yy = 0;
	while (yy <= y)
	{
		while (xx <= x)
		{
			put_pixel_to_frame(&img[0], xx, yy, 0xFFFFFFFF);
			xx++;
		}
		xx = 0;
		yy++;
	}
}

void	put_circle(t_data *img, int x, int y, int color)
{
	//x *= BLOCK;
	//y *= BLOCK;
	put_pixel_to_frame(img, x - 1, y - 1, /*0xCC000000 +*/ color);
	put_pixel_to_frame(img, x - 1, y,     /*0x00000000 +*/ color);
	put_pixel_to_frame(img, x - 1, y + 1, /*0xCC000000 +*/ color);

	put_pixel_to_frame(img, x, y - 1,     /*0x44000000 +*/ color);
	put_pixel_to_frame(img, x, y,         /*0x00000000 +*/ color);
	put_pixel_to_frame(img, x, y + 1,     /*0x44000000 +*/ color);

	put_pixel_to_frame(img, x + 1, y - 1, /*0xCC000000 +*/ color);
	put_pixel_to_frame(img, x + 1, y,     /*0x44000000 +*/ color);
	put_pixel_to_frame(img, x + 1, y + 1, /*0xCC000000 +*/ color);
}

void drawLine(t_data *img, int x1, int y1, int x2, int y2, int color) 
{
	//x1 *= BLOCK;
	//y1 *= BLOCK;
	//x2 *= BLOCK;
	//y2 *= BLOCK;
    const int deltaX = abs(x2 - x1);
    const int deltaY = abs(y2 - y1);
    const int signX = x1 < x2 ? 1 : -1;
    const int signY = y1 < y2 ? 1 : -1;
    int error = deltaX - deltaY;
    put_pixel_to_frame(img, x2, y2, color);
    while(x1 != x2 || y1 != y2) 
   	{
        put_pixel_to_frame(img, x1, y1, color);
        int error2 = error * 2;
        if(error2 > -deltaY) 
        {
            error -= deltaY;
            x1 += signX;
        }
        if(error2 < deltaX) 
        {
            error += deltaX;
            y1 += signY;
        }
    }
}

void drawArrow(t_data *img, int x, int y, double angle, int color)
{
	//x *= BLOCK;
	//y *= BLOCK;
    drawLine(img, x, y, sin(angle + PI * 1.25) * BLOCK * PSIZE * 0.1 + x, cos(angle + PI * 1.25) * BLOCK * PSIZE * 0.1 + y , color);
    drawLine(img, x, y, sin(angle + PI) * BLOCK * PSIZE * 0.1 + x, cos(angle + PI) * BLOCK * PSIZE * 0.1 + y , color);
    drawLine(img, x, y, sin(angle - PI * 1.25) * BLOCK * PSIZE * 0.1 + x, cos(angle - PI * 1.25) * BLOCK * PSIZE * 0.1 + y , color);
}