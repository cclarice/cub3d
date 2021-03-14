/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 06:55:47 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/14 18:07:06 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

#define RWCDM ft_printf("\033[35mD! \nWt: %d\nH: %d\033[36m\n", e->rex, e->rey)

/*
**	Textures initialization
**
**  Initializate textures from pt(Path) to e(Engine)
**  Textures list:
**  no so we ea sp
*/

int		textures_init(t_eng *e, t_tex *t, t_path pt)
{
	!(t->no.img = mlx_xpm_file_to_image(e->mlx, pt.no, &t->no.w, &t->no.h))
			? ft_printf("Error\n\033[31mNorth texture is not found!\n") : 0;
	!(t->so.img = mlx_xpm_file_to_image(e->mlx, pt.so, &t->so.w, &t->so.h))
			? ft_printf("Error\n\033[31mSouth texture is not found!\n") : 0;
	!(t->we.img = mlx_xpm_file_to_image(e->mlx, pt.we, &t->we.w, &t->we.h))
			? ft_printf("Error\n\033[31mWest texture is not found!\n") : 0;
	!(t->ea.img = mlx_xpm_file_to_image(e->mlx, pt.ea, &t->ea.w, &t->ea.h))
			? ft_printf("Error\n\033[31mEast texture is not found!\n") : 0;
	!(t->sp.img = mlx_xpm_file_to_image(e->mlx, pt.sp, &t->sp.w, &t->sp.h))
			? ft_printf("Error\n\033[31mSprite texture is not found!\n") : 0;
	if (!(t->no.img && t->so.img && t->we.img && t->ea.img && t->sp.img))
		return (1);
	t->no.ptr = mlx_get_data_addr(t->no.img, &t->no.bpp, &t->no.length,
		&t->no.endian);
	t->so.ptr = mlx_get_data_addr(t->so.img, &t->so.bpp, &t->so.length,
		&t->so.endian);
	t->we.ptr = mlx_get_data_addr(t->we.img, &t->we.bpp, &t->we.length,
		&t->we.endian);
	t->ea.ptr = mlx_get_data_addr(t->ea.img, &t->ea.bpp, &t->ea.length,
		&t->ea.endian);
	t->sp.ptr = mlx_get_data_addr(t->sp.img, &t->sp.bpp, &t->sp.length,
		&t->sp.endian);
	return (0);
}

void	resolution_init(t_eng *e, t_vars v)
{
	int		screen_w;
	int		screen_h;

	mlx_get_screen_size(&screen_w, &screen_h);
	ft_printf("Your screen size: %d/%d\n", screen_w, screen_h);
	if (v.ry > screen_h - 22)
		screen_h -= 22;
	if (v.mode != 2 && (screen_w < v.rx || v.rx < MSW))
	{
		e->rex = (screen_w < v.rx ? screen_w : MSW);
		WWC;
	}
	else
		e->rex = v.rx;
	if (v.mode != 2 && (screen_h < v.ry || v.ry < MSH))
	{
		e->rey = (screen_h < v.ry ? screen_h : MSH);
		HWC;
	}
	else
		e->rey = v.ry;
}

/*
**	!!!	Bonus Minimap part !!!
**
**	void	mini_map_init(t_eng *e, t_vars v)
**	{
**		int x;
**		int y;
**
**		x = e->rex / e->msx;
**		y = e->rey / e->msy;
**		ft_printf("x: %d rex: %d msx: %d\ny: %d rey: %d msy: %d\n",
**							x, e->rex, e->msx, y, e->rey, e->msy);
**		if (x < y)
**		{
**			e->mmp.fullb = x;
**			e->mmp.minib = x / 3;
**			v.mode == 2 ? e->rex = x * e->msx : 0;
**			v.mode == 2 ? e->rey = x * e->msy : 0;
**		}
**		else
**		{
**			e->mmp.fullb = y;
**			e->mmp.minib = y / 3;
**			v.mode == 2 ? e->rex = y * e->msx : 0;
**			v.mode == 2 ? e->rey = y * e->msy : 0;
**		}
**		e->mmp.mode = v.mode == 2 ? -1 + RWCDM * 0 : 0;
**	ft_printf("Full Map Block Size: %d\nMini-Map Block Size: %d\nMode: %d\n",
**						e->mmp.fullb, e->mmp.minib, v.mode);
**		ft_printf("Map Size X: %d Map Size Y: %d\n", e->msx, e->msy);
**		ft_printf("Resolution Y: %d Resolution X: %d\n", e->rex, e->rey);
**	}
**
**	void		color_init(t_eng *e)
**	{
**		e->mmp.b_clr = 0x404040;
**		e->mmp.t_clr = 0x3a3a3a;
**		e->mmp.o_clr = 0x40a040;
**		e->mmp.d_clr = 0x7f7f7f;
**		e->mmp.s_clr = 0x0005ff;
**		e->mmp.p_clr = 0xac3232;
**		e->mmp.f_clr = 0x040804;
**		e->mmp.a_clr = 0x080f08;
**	}
**
**	mini_map_init(&e, v);
**	color_init(&e);
*/

/*
**  Initialization
*/

int		initialization(t_path pt, t_vars v, char **map)
{
	t_eng e;

	e.mlx = mlx_init();
	e.mode = 0;
	if (textures_init(&e, &e.tex, pt))
		return (0);
	if (v.mode == 2 && ft_printf("Screenshot mode!\n") && (e.mode = 2)
									&& (v.rx > 16384 || v.ry > 16384))
	{
		ft_printf("Error\nBro is too high to save!\n");
		ft_printf("Please use resolution less than 16384n");
		exit(1);
	}
	ft_printf("Errors was not found\n");
	resolution_init(&e, v);
	cub_get_mapsize(map, &e.msx, &e.msy);
	e.m = map;
	window_init(&e, v);
	mouse_init(&e);
	keyboard_init(&e);
	mouse_init(&e);
	other_init(&e, v, map);
	engine(&e);
	return (0);
}
