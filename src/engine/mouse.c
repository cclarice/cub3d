/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:29:53 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/14 17:01:51 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int		mouse_init(t_eng *e)
{
	if (e->mode != 2)
		mlx_mouse_move(e->win, e->rex / 2, e->rey / 2);
	e->cnt.mx = 0;
	e->cnt.my = 0;
	e->cnt.br = 0;
	e->cnt.bl = 0;
	e->cnt.mm = 0;
	return (0);
}

/*
**int		button_press(int hook, t_eng *e)
**{
**	int use;
**
**	use = hook + e->msx;
**	return (0);
**}
**
**int		button_release(int hook, t_eng *e)
**{
**	int use;
**
**	use = hook + e->msx;
**	return (0);
**}
*/

void	mouse_tick(t_eng *e)
{
	int x;
	int y;

	if (e->mode != 2)
	{
		mlx_mouse_get_pos(e->win, &x, &y);
		e->pla -= (x - e->rex / 2) * 0.0005;
		e->plb -= (y - e->rey / 2) * 0.0005;
		while (e->plb > P * 0.5 + 1)
			e->plb -= 0.005;
		while (e->plb < -P * 0.5 + 1)
			e->plb += 0.005;
		mlx_mouse_move(e->win, e->rex / 2, e->rey / 2);
	}
}
