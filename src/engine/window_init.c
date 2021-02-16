/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 07:32:27 by cclarice          #+#    #+#             */
/*   Updated: 2021/02/16 23:02:15 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	img_init(t_eng *e, t_img *img, char *name, int x, int y)
{
	ft_printf("%s Image initialization:", name);
	img->img = mlx_new_image(e->mlx, x, y);
	ft_printf(" Success!");
	ft_printf(" Get Data!");
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	ft_printf(" Success!\n");
}

void	window_init(t_eng *e, t_vars v)
{
	ft_printf("Window initialization:");
	e->win = mlx_new_window(e->mlx, e->rex, e->rey, (v.mode == 2 ? NAME_D : NAME));
	ft_printf(" Success!\n");
	img_init(e, &e->frg, "Foreground", e->rex, e->rex);
	img_init(e, &e->mdg, "Middleground", e->rex, e->rex);
	img_init(e, &e->bcg, "Background", e->rex, e->rex);
	img_init(e, &e->lmi, "Mini-Map", e->mmp.minib * e->msx, e->mmp.minib * e->msy);
	img_init(e, &e->rmi, "Ray Mini-Map", e->mmp.minib * e->msx, e->mmp.minib * e->msy);
	ft_printf("Mini-Map Render:");
	fill_img_with_color(&(e->lmi.img), e->mmp.minib * e->msx, e->mmp.minib * e->msy, 0xff000000);
	render_map(e, &e->lmi.img, e->mmp.minib);
	ft_printf(" Success!\n");
	img_init(e, &e->lma, "Map", e->mmp.fullb * e->msx, e->mmp.fullb * e->msy);
	img_init(e, &e->rma, "Ray Map", e->mmp.fullb * e->msx, e->mmp.fullb * e->msy);
	ft_printf("Map Render:");
	fill_img_with_color(&(e->lma.img), e->mmp.fullb * e->msx, e->mmp.fullb * e->msy, 0xff000000);
	render_map(e, &e->lma.img, e->mmp.fullb);
	ft_printf(" Success!\n");
}