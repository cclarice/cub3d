/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:29:53 by cclarice          #+#    #+#             */
/*   Updated: 2021/02/24 07:35:55 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int		mouse_init(t_eng *e)
{
	int mousey;
	int mousex;
	
	mlx_mouse_move(e->win, e->rex / 2, e->rey / 2);
	mlx_mouse_get_pos(e->win, &mousex, &mousey);
	mlx_mouse_move(e->win, e->rex / 2, mousey);
	e->cnt.mx = 0;
	e->cnt.my = 0;
	e->cnt.br = 0;
	e->cnt.bl = 0;
	e->cnt.mm = 0;
	return (0);
}

int		button_press(int hook, t_eng *e)
{
	int use;

	use = hook + e->msx;
	return (0);
}

int		button_release(int hook, t_eng *e)
{
	int use;

	use = hook + e->msx;
	return (0);
}

int		mouse_motion(int x, int y, t_eng *e)
{
	int use;

	use = x + y + e->msx;
	return (0);
}