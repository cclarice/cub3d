/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:30:34 by cclarice          #+#    #+#             */
/*   Updated: 2021/02/16 23:03:24 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

#define KeyW 			13
#define KeyA 			0
#define KeyS 			1
#define KeyD 			2
#define KeyR 			124
#define KeyL 			123
#define KeyM			46
#define KeyF3			99
#define KeyMM			10

int		key_press(int key, t_eng *e)
{
	ft_printf("key: %d\n", key);
	if (key == 53)
		destroyer();
	if (key == KeyM && e->mmp.mode != -1)
		e->mmp.mode++;
	if (e->mmp.mode == 4)
		e->mmp.mode = 0;
	if (key == 10)
		e->cnt.mm = e->cnt.mm == 0 ? 1 : 0;
	key == KeyW ? e->cnt.kw = 1 : 0;
	key == KeyA ? e->cnt.ka = 1 : 0;
	key == KeyS ? e->cnt.ks = 1 : 0;
	key == KeyD ? e->cnt.kd = 1 : 0;
	key == KeyR ? e->cnt.kr = 1 : 0;
	key == KeyL ? e->cnt.kl = 1 : 0;
	key == KeyF3 ? e->cnt.kf3 = 1 : 0;
	return (0);
}

int		key_release(int key, t_eng *e)
{
	key == KeyW ? e->cnt.kw = 0 : 0;
	key == KeyA ? e->cnt.ka = 0 : 0;
	key == KeyS ? e->cnt.ks = 0 : 0;
	key == KeyD ? e->cnt.kd = 0 : 0;
	key == KeyR ? e->cnt.kr = 0 : 0;
	key == KeyL ? e->cnt.kl = 0 : 0;
	key == KeyF3 ? e->cnt.kf3 = 0 : 0;
	return (0);
}

void	 keyboard_init(t_eng *e)
{
	
}