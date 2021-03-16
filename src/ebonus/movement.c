/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:47:12 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/16 04:16:50 by cclarice         ###   ########.fr       */
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
	if (!e->cnt.kup && e->cnt.kdw)
		e->plb += PS;
	else if (e->cnt.kup && !e->cnt.kdw)
		e->plb -= PS;
	while (e->plb > P * 0.5 + 1)
		e->plb -= 0.005;
	while (e->plb < -P * 0.5 + 1)
		e->plb += 0.005;
}

void	movement(t_eng *e)
{
	if (e->cnt.kspace && e->height < 0.1)
	{
		e->hspeed = e->rey / 24;
	}
	if (e->hspeed > 0 || e->height > 0)
	{
		e->height += e->hspeed;
		if (e->hspeed > 1)
			e->hspeed -= (1 + fabs(e->hspeed)) * (double)e->rey / 4096;
		else
			e->hspeed -= (1 + fabs(e->hspeed)) * (double)e->rey / 4096;
	}
	else
	{
		e->height = 0;
		e->hspeed = 0;
	}
	rotating(e);
	player_move(e, e->cnt);
	collision(e);
}
