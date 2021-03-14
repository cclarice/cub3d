/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 07:26:55 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/14 09:45:05 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

#define KEYP 2
#define KEYR 3
#define DESN 17

/*
**	Not used
**	mlx_hook(e->win,	ButtonPress			, 0L, &button_press			, e);
**	mlx_hook(e->win,	ButtonRelease		, 0L, &button_release		, e);
**	mlx_hook(e->win,	MotionNotify		, 0L, &mouse_motion			, e);
**	mlx_hook(e->win,	Expose				, 0L, &expose				, e);
*/

void	engine(t_eng *e)
{
	ft_printf("Run Engine\n");
	if (e->mode != 2)
	{
		mlx_hook(e->win, KEYP, 0L, &key_press, e);
		mlx_hook(e->win, KEYR, 0L, &key_release, e);
		mlx_hook(e->win, DESN, 0L, &destroy_notify, e);
	}
	mlx_loop_hook(e->mlx, &tick, e);
	mlx_loop(e->mlx);
}
