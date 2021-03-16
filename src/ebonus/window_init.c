/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 07:32:27 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/16 03:03:25 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	img_init(t_eng *e, t_img *img, int x, int y)
{
	ft_printf("%s Image initialization:", "Middleground");
	img->img = mlx_new_image(e->mlx, x, y);
	img->width = x;
	img->height = y;
	ft_printf(" Success!");
	ft_printf(" Get Data!");
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->endian);
	ft_printf(" Success!\n");
}

/*
**	Bonus minimap part
**
**	img_init(e, &e->lmi, "Mini-Map", e->mmp.minib * e->msx,
**									e->mmp.minib * e->msy);
**	img_init(e, &e->rmi, "Ray Mini-Map", e->mmp.minib * e->msx,
**									e->mmp.minib * e->msy);
**	ft_printf("Mini-Map Render:");
**	fill_img_with_color(&e->lmi.img, e->mmp.minib * e->msx,
**									e->mmp.minib * e->msy, 0xff000000);
**	render_map(e, &e->lmi.img, e->mmp.minib);
**	ft_printf(" Success!\n");
**	img_init(e, &e->lma, "Map", e->mmp.fullb * e->msx, e->mmp.fullb * e->msy);
**	img_init(e, &e->rma, "Ray", e->mmp.fullb * e->msx, e->mmp.fullb * e->msy);
**	ft_printf("Map Render:");
**	fill_img_with_color(&e->lma.img, e->mmp.fullb * e->msx,
**									e->mmp.fullb * e->msy, 0xff000000);
**	render_map(e, &e->lma.img, e->mmp.fullb);
**	ft_printf(" Success!\n");
**
**	img_init(e, &e->fps, "Fps meter", 15 * 6, 15);
*/

void	window_init(t_eng *e, t_vars v)
{
	if (v.mode != 2)
	{
		ft_printf("Window initialization:");
		e->win = mlx_new_window(e->mlx, e->rex, e->rey, NAME);
		ft_printf(" Success!\n");
	}
	img_init(e, &e->mdg, e->rex, e->rey);
}
