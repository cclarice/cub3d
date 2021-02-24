/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 07:26:55 by cclarice          #+#    #+#             */
/*   Updated: 2021/02/19 05:26:44 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

#define KeyPress		2
#define KeyRelease		3
#define ButtonPress		4
#define ButtonRelease	5
#define MotionNotify	6
#define Expose			12
#define DestroyNotify	17

void	engine(t_eng *e)
{
	ft_printf("Run Engine\n");
	mlx_put_image_to_window(e->mlx, e->win, e->lma.img, 0, 0);
	mlx_hook(e->win,	KeyPress			, 0L, &key_press			, e);
	mlx_hook(e->win,	KeyRelease			, 0L, &key_release			, e);
	mlx_hook(e->win,	ButtonPress			, 0L, &button_press			, e);
	mlx_hook(e->win,	ButtonRelease		, 0L, &button_release		, e);
	mlx_hook(e->win,	MotionNotify		, 0L, &mouse_motion			, e);
	mlx_hook(e->win,	Expose				, 0L, &expose				, e);
	mlx_hook(e->win,	DestroyNotify		, 0L, &destroy_notify		, e);
	mlx_loop_hook(e->mlx, &tick, e);
	mlx_loop(e->mlx);
}