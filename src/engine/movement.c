/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:47:12 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/14 09:59:58 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	check_control(t_cnt *c)
{
	if (c->kw && c->ks)
	{
		c->kw = 0;
		c->ks = 0;
	}
	if (c->ka && c->kd)
	{
		c->ka = 0;
		c->kd = 0;
	}
}

void	player_move(t_eng *e, t_cnt c)
{
	double ang;

	ang = 0;
	check_control(&c);
	if (c.kw && c.kd)
		ang -= P * 0.25;
	else if (c.kw && c.ka)
		ang = P * 0.25;
	else if (c.ks && c.kd)
		ang -= P * 0.75;
	else if (c.ks && c.ka)
		ang = P * 0.75;
	else if (c.kw)
		ang = 0;
	else if (c.ka)
		ang += P * 0.5;
	else if (c.ks)
		ang -= P;
	else if (c.kd)
		ang -= P * 0.5;
	if (c.kw || c.ka || c.ks || c.kd)
	{
		e->plx += sin(e->pla + ang) * PS;
		e->ply += cos(e->pla + ang) * PS;
	}
}

void	rotating(t_eng *e)
{
	if (e->pla >= P * 2)
		e->pla -= P * 2;
	else if (e->pla < 0)
		e->pla += P * 2;
	if (!e->cnt.kr && e->cnt.kl)
		e->pla += PS;
	else if (e->cnt.kr && !e->cnt.kl)
		e->pla -= PS;
}

void	movement(t_eng *e)
{
	rotating(e);
	player_move(e, e->cnt);
	collision(e);
}
