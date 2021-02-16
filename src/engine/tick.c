/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:52:50 by cclarice          #+#    #+#             */
/*   Updated: 2021/02/16 22:54:00 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.c"

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
	mlx_clear_window(e->mlx, e->win);
	if (e->mmp.mode != -1 || e->mmp.mode != 2 )
		mlx_put_image_to_window(e->mlx, e->win, e->mdg.img, 0, 0);
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
		mlx_put_image_to_window(e->mlx, e->win, e->lma.img, -e->plx * e->mmp.fullb + e->mmp.minib * e->msx / 2, -e->ply * e->mmp.fullb + e->mmp.minib * e->msy / 2);
		mlx_put_image_to_window(e->mlx, e->win, e->rma.img, -e->plx * e->mmp.fullb + e->mmp.minib * e->msx / 2, -e->ply * e->mmp.fullb + e->mmp.minib * e->msy / 2);
	}
}

int		tick(t_eng *e)
{
	movement(e);
	pre_render(e);
	raycasting(e);
	render(e);
	return (0);
}