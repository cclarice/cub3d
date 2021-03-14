/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:52:50 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/14 10:30:45 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

/*
**	Bonus minimap part
**
**	void	put_player_to_map(void *img, t_eng *e, int size, int color)
**	{
**		t_ab s;
**
**		s.xa = (e->plx - PHSZ) * size;
**		s.ya = (e->ply - PHSZ) * size;
**		s.xe = (e->plx + PHSZ) * size;
**		s.ye = (e->ply + PHSZ) * size;
**		draw_full_rectangle(img, s, color + 0xdd000000);
**		draw_rectangle(img, s, color);
**		s.xa = e->plx * size + sin(e->pla) * size * PSZ;
**		s.ya = e->ply * size + cos(e->pla) * size * PSZ;
**		draw_arrow(img, s, size, e->pla, 0xffff00);
**	}
*/

/*
**	Bonus minimap part
**
**	void	pre_render(t_eng *e)
**	{
**		if (e->mmp.mode == -1 || e->mmp.mode == 2 )
**		{
**			fill_img_with_color(&(e->rma.img), e->mmp.fullb * e->msx,
**										e->mmp.fullb * e->msy, 0xff000000);
**			put_player_to_map(&(e->rma.img), e, e->mmp.fullb, e->mmp.p_clr);
**		}
**		else if (e->mmp.mode == 0)
**		{
**			fill_img_with_color(&(e->rmi.img), e->mmp.minib * e->msx,
**										e->mmp.minib * e->msy, 0xff000000);
**			put_player_to_map(&(e->rmi.img), e, e->mmp.minib, e->mmp.p_clr);
**		}
**		else if (e->mmp.mode == 1)
**		{
**			fill_img_with_color(&(e->rma.img), e->mmp.fullb * e->msx,
**										e->mmp.fullb * e->msy, 0xff000000);
**			put_player_to_map(&(e->rma.img), e, e->mmp.fullb, e->mmp.p_clr);
**		}
**	}
**	mlx_put_image_to_window(e->mlx, e->win, e->fps.img, 0, 0);
*/

/*
**	FPS bonus part
**
**	void	fps_meter(t_eng *e)
**	{
**		static struct timeval	time;
**		static struct timeval	old;
**		static int				tact;
**		double					tim;
**		char					str[6];
**
**		tim = 1000000.0 / (time.tv_usec - old.tv_usec);
**		old = time;
**		if (tact == 15)
**		{
**			if (tim > 10)
**				str[0] = (int)(tim / 10) + '0';
**			else
**				str[0] = ' ';
**			str[1] = (int)(tim) % 10 + '0';
**			str[2] = '.';
**			str[3] = (int)(tim * 10) % 10 + '0';
**			str[4] = (int)(tim * 100) % 10 + '0';
**			str[5] = 0;
**			fill_img_with_color(&e->fps, 15 * 6, 15, 0xff000000);
**			my_put_string(&e->fps, str, 0, 0, 3);
**			tact = 0;
**		}
**		else
**			tact++;
**		gettimeofday(&time, NULL);
**	}
**
**	fps_meter(e);
*/

/*
**	tick()
**
**	pre_render(e);
**	mlx_do_sync(e->mlx);
*/

int		tick(t_eng *e)
{
	movement(e);
	if ((e->plx <= (int)e->plx + 0.00001 && e->plx >= (int)e->plx - 0.00001)
		|| (e->plx <= (int)e->plx + 1.00001 && e->plx >= (int)e->plx + 0.99998))
		e->plx = e->plx + 0.0001;
	if ((e->ply <= (int)e->ply + 0.00001 && e->ply >= (int)e->ply - 0.00001)
		|| (e->ply <= (int)e->ply + 1.00001 && e->ply >= (int)e->ply + 0.99998))
		e->ply = e->ply + 0.0001;
	raycasting(e);
	if (e->cnt.kf3)
		mouse_tick(e);
	return (0);
}
