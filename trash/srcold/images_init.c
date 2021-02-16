/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 06:16:29 by cclarice          #+#    #+#             */
/*   Updated: 2021/01/27 08:27:17 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <mlx.h>

int		key_hook(int key, t_mlx *mlx)
{
	if (key == 13)
	{
		mlx->py-=32;
		ft_printf("W\n");
	}
	else if (key == 0)
	{
		mlx->px-=32;
		ft_printf("A\n");
	}
	else if (key == 1)
	{
		mlx->py+=32;
		ft_printf("S\n");
	}
	else if (key == 2)
	{
		mlx->px+=32;
		ft_printf("D\n");
	}
	ft_printf("bruh1");
    mlx_pixel_put(mlx->mlx, mlx->win, mlx->px, mlx->py, 0xFF0000);
    mlx_pixel_put(mlx->mlx, mlx->win, mlx->px+1, mlx->py, 0xFF0000);
    mlx_pixel_put(mlx->mlx, mlx->win, mlx->px, mlx->py+1, 0xFF0000);
    mlx_pixel_put(mlx->mlx, mlx->win, mlx->px+1, mlx->py+1, 0xFF0000);
	ft_printf("bruh2");
	return (0);
}

void	put_square(void *mlx, void *win, int color, int x, int y)
{
	int xs;
	int ys;

	xs = 1;
	ys = 1;
	while (ys <= 30)
	{
		while (xs <= 30)
		{
			mlx_pixel_put(mlx, win, x+xs, y+ys, color);
			xs++;
		}
		xs = 1;
		ys++;
	}
}

void	image_init(t_mlx *mlx, t_cube cube)
{
	int x;
	int y;

	x = 0;
	y = 0;
	mlx->cube = cube;
	mlx->mlx = mlx_init();
    mlx->no.img = mlx_xpm_file_to_image(mlx->mlx, cube.no, &mlx->no.w, &mlx->no.h);
    mlx->so.img = mlx_xpm_file_to_image(mlx->mlx, cube.so, &mlx->so.w, &mlx->so.h);
    mlx->we.img = mlx_xpm_file_to_image(mlx->mlx, cube.we, &mlx->we.w, &mlx->we.h);
    mlx->ea.img = mlx_xpm_file_to_image(mlx->mlx, cube.ea, &mlx->ea.w, &mlx->ea.h);
    mlx->sp.img = mlx_xpm_file_to_image(mlx->mlx, cube.sp, &mlx->sp.w, &mlx->sp.h);
    mlx->win = mlx_new_window(mlx->mlx, cube.x, cube.y, "Hello world!");
    while (y <= cube.my)
    {
    	while (x <= cube.mx)
    	{
    		if (cube.map[y][x] == '1')
    			put_square(mlx->mlx, mlx->win, 0xFFFFFF, x * 32, y * 32);
    		if (cube.map[y][x] == 'N')
    		{
    			mlx->px = x*32+15;
    			mlx->py = y*32+15;
    		}
    		x++;
    	}
    	x = 0;
    	y++;
    }
    mlx_key_hook(mlx->win, key_hook, mlx);
    mlx_loop(mlx->mlx);
    //double posX = 22; //x and y start position
  	//double posY = 12;
  	//double dirX = -1; //initial direction vector
  	//double dirY = 0;
  	//double planeX = 0; //the 2d raycaster version of camera plane
  	//double planeY = 0.66; 
	//
  	//double time = 0; //time of current frame
  	//double oldTime = 0; //time of previous frame
}