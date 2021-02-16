/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 06:54:44 by cclarice          #+#    #+#             */
/*   Updated: 2021/02/09 12:50:09 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "../cube3d.h"

int		run_engine(t_eng eng)
{
	int x;
	int y;

	x = -1;
	y = -1;
   if (D3 >= 1)
	eng.win = mlx_new_window(eng.mlx, eng.msx * BLOCK, eng.msy * BLOCK, "cube2D");
   else
      eng.win = mlx_new_window(eng.mlx, eng.rx, eng.ry, "cube3D");
   eng.cub3d.img = mlx_new_image(eng.mlx, eng.rx, eng.ry);
   eng.cub3d.addr = mlx_get_data_addr(eng.cub3d.img, &eng.cub3d.bits_per_pixel, &eng.cub3d.line_length,
                                &eng.cub3d.endian);
	eng.ray.img = mlx_new_image(eng.mlx, eng.msx * BLOCK, eng.msy * BLOCK);
   eng.ray.addr = mlx_get_data_addr(eng.ray.img, &eng.ray.bits_per_pixel, &eng.ray.line_length,
                                &eng.ray.endian);
   eng.frm.img = mlx_new_image(eng.mlx, eng.msx * BLOCK, eng.msy * BLOCK);
   eng.frm.addr = mlx_get_data_addr(eng.frm.img, &eng.frm.bits_per_pixel, &eng.frm.line_length,
                                &eng.frm.endian);
   set_img_transparent(&eng.cub3d, eng.rx, eng.ry);
   set_img_transparent(&eng.ray, eng.msx * BLOCK, eng.msy * BLOCK);
   while (eng.m[++y][0] != 0)
   	while (eng.m[y][++x] != 0 || (x = -1) != -1)
   		if (eng.m[y][x] == '1')
   			put_square_to_image(&eng.frm, (x) * BLOCK, y * BLOCK, 0xFFFFFF);
   		else if (eng.m[y][x] >= 'A' && eng.m[y][x] <= 'Z')
   		{
   			eng.plaX = x + 0.5;
   			eng.plaY = y + 0.5;
   			put_square_to_image(&eng.frm, (x) * BLOCK, y * BLOCK, 0x111111);
   		}
   mlx_put_image_to_window(eng.mlx, eng.win, eng.frm.img, 0, 0);
   engine(eng);
   return (0);
}

void	get_mapsize(char **map, int *x, int *y)
{
	x[0] = 0;
	y[0] = 0;
	while (map[0][x[0]] != '\0')
		x[0]++;
	while (map[y[0]][0] != '\0')
		y[0]++;
	ft_printf("%d,%d", x[0], y[0]);
}

int		engine_mlx(t_path pt, t_vars vr, char **map)
{
	t_eng	eng;

	eng.mlx = mlx_init();
    !(eng.no.img = mlx_xpm_file_to_image(eng.mlx, pt.no, &eng.no.w, &eng.no.h)) 
    		? ft_printf("Error\n\033[31mNorth texture is not found!\n") : 0;
    !(eng.so.img = mlx_xpm_file_to_image(eng.mlx, pt.so, &eng.so.w, &eng.so.h)) 
    		? ft_printf("Error\n\033[31mSouth texture is not found!\n") : 0;
    !(eng.we.img = mlx_xpm_file_to_image(eng.mlx, pt.we, &eng.we.w, &eng.we.h)) 
    		? ft_printf("Error\n\033[31mWest texture is not found!\n") : 0;
    !(eng.ea.img = mlx_xpm_file_to_image(eng.mlx, pt.ea, &eng.ea.w, &eng.ea.h)) 
    		? ft_printf("Error\n\033[31mEast texture is not found!\n") : 0;
    !(eng.sp.img = mlx_xpm_file_to_image(eng.mlx, pt.sp, &eng.sp.w, &eng.sp.h)) 
    		? ft_printf("Error\n\033[31mSprite texture is not found!\n") : 0;
    if (!(eng.no.img && eng.so.img && eng.we.img && eng.ea.img && eng.sp.img))
    	return (0);
    mlx_get_screen_size(eng.mlx, &eng.rx, &eng.ry);
    eng.rx >= vr.rx ?
    eng.rx = vr.rx : ft_printf("\033[36mWarning! Wight was changed to %d!\n", eng.rx);
    eng.ry >= vr.ry ?
    eng.ry = vr.ry : ft_printf("\033[36mWarning! Height was changed to %d!\n", eng.ry);
    eng.cc = vr.cc;
    eng.fc = vr.fc;
    eng.plaX = 0;
    eng.plaY = 0;
    eng.angV = 0;
    eng.camLX = 0;
    eng.camLY = 0;
    eng.camRX = 0;
    eng.camRY = 0;
    eng.camVX = 0;
    eng.camVY = 0;
    eng.dDX = -1;
    eng.dDY = -1;
    eng.mousex = -16000;
    eng.mousey = -16000;
    get_mapsize(map, &eng.msx, &eng.msy);
    eng.m = map;
    run_engine(eng);
    return (0);
}
