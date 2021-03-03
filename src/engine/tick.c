/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:52:50 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/01 19:28:31 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	put_player_to_map(void *img, t_eng *e, int size, int color)
{
	t_ab s;

	s.xa = (e->plx - PHSZ) * size;
	s.ya = (e->ply - PHSZ) * size;
	s.xe = (e->plx + PHSZ) * size;
	s.ye = (e->ply + PHSZ) * size;
	draw_full_rectangle(img, s, color + 0xdd000000);
	draw_rectangle(img, s, color);
	s.xa = e->plx * size + sin(e->pla) * size * PSZ;
	s.ya = e->ply * size + cos(e->pla) * size * PSZ;
	draw_arrow(img, s, size, e->pla, 0xffff00);
}

void	pre_render(t_eng *e)
{
	if (e->mmp.mode == -1 || e->mmp.mode == 2 )
	{
		fill_img_with_color(&(e->rma.img), e->mmp.fullb * e->msx, e->mmp.fullb * e->msy, 0xff000000);
		put_player_to_map(&(e->rma.img), e, e->mmp.fullb, e->mmp.p_clr);
	}
	else if (e->mmp.mode == 0)
	{
		fill_img_with_color(&(e->rmi.img), e->mmp.minib * e->msx, e->mmp.minib * e->msy, 0xff000000);
		put_player_to_map(&(e->rmi.img), e, e->mmp.minib, e->mmp.p_clr);
	}
	else if (e->mmp.mode == 1)
	{
		fill_img_with_color(&(e->rma.img), e->mmp.fullb * e->msx, e->mmp.fullb * e->msy, 0xff000000);
		put_player_to_map(&(e->rma.img), e, e->mmp.fullb, e->mmp.p_clr);
	}
}

void	render(t_eng *e)
{
	t_ab s;

	//mlx_clear_window(e->mlx, e->win);
	if (e->mmp.mode != -1 || e->mmp.mode != 2 )
	{
		draw_dot(&e->mdg, e->rex / 2, e->rey / 2, 0xffffff);
		mlx_put_image_to_window(e->mlx, e->win, e->mdg.img, 0, 0);
	}
	if (e->mmp.mode == -1 || e->mmp.mode == 2 )
	{
		mlx_put_image_to_window(e->mlx, e->win, e->lma.img, 0, 0);
		mlx_put_image_to_window(e->mlx, e->win, e->rma.img, 0, 0);
	}
	else if (e->mmp.mode == 0)
	{
		mlx_put_image_to_window(e->mlx, e->win, e->lmi.img, 0, 0);
		mlx_put_image_to_window(e->mlx, e->win, e->rmi.img, 0, 0);
	}
	else if (e->mmp.mode == 1)
	{
		s.xa = 0;
		s.ya = e->ply * e->mmp.fullb + e->mmp.minib * e->msy / 2;
		s.xe = e->mmp.fullb * e->msx;
		s.ye = e->mmp.fullb * e->msy;
		draw_full_rectangle(&e->lma, s, 0xff000000);
		draw_full_rectangle(&e->rma, s, 0xff000000);
		s.xa = e->plx * e->mmp.fullb + e->mmp.minib * e->msx / 2;
		s.ya = 0;
		s.ye = e->ply * e->mmp.fullb + e->mmp.minib * e->msy / 2;
		draw_full_rectangle(&e->lma, s, 0xff000000);
		draw_full_rectangle(&e->rma, s, 0xff000000);
		mlx_put_image_to_window(e->mlx, e->win, e->lma.img, -e->plx * e->mmp.fullb + e->mmp.minib * e->msx / 2, -e->ply * e->mmp.fullb + e->mmp.minib * e->msy / 2);
		mlx_put_image_to_window(e->mlx, e->win, e->rma.img, -e->plx * e->mmp.fullb + e->mmp.minib * e->msx / 2, -e->ply * e->mmp.fullb + e->mmp.minib * e->msy / 2);
		render_map(e, &e->lma.img, e->mmp.fullb);
	}
	//mlx_put_image_to_window(e->mlx, e->win, e->tex.no.img, 0, 0);
}

int		tick(t_eng *e)
{

	movement(e);
	pre_render(e);
	raycasting(e);
	mouse_tick(e);
	if (e->cnt.kf3)
		my_put_string(&e->rma, "DJ EBAN!", (int)(e->plx * e->mmp.fullb * 0.5), (int)(e->ply * e->mmp.fullb * 0.5), 2);
	render(e);
	mlx_do_sync(e->mlx);
	return (0);
}