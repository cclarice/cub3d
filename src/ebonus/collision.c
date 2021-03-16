/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:33:05 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/16 03:25:09 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

#define SM 0.0001
#define H PHSZ

short	in_wall(t_eng *e)
{
	if (e->m[(int)(e->ply - H)][(int)(e->plx - H)] == '1')
		return ('a');
	if (e->m[(int)(e->ply + H)][(int)(e->plx - H)] == '1')
		return ('b');
	if (e->m[(int)(e->ply - H)][(int)(e->plx + H)] == '1')
		return ('c');
	if (e->m[(int)(e->ply + H)][(int)(e->plx + H)] == '1')
		return ('d');
	if (e->m[(int)(e->ply - H)][(int)(e->plx - H)] == '2')
		return ('a');
	if (e->m[(int)(e->ply + H)][(int)(e->plx - H)] == '2')
		return ('b');
	if (e->m[(int)(e->ply - H)][(int)(e->plx + H)] == '2')
		return ('c');
	if (e->m[(int)(e->ply + H)][(int)(e->plx + H)] == '2')
		return ('d');
	return (0);
}

short	in_walls(t_eng *e)
{
	short c;

	c = 0;
	if (e->m[(int)(e->ply - H)][(int)(e->plx - H)] == '1')
		c += 1;
	if (e->m[(int)(e->ply + H)][(int)(e->plx - H)] == '1')
		c += 2;
	if (e->m[(int)(e->ply - H)][(int)(e->plx + H)] == '1')
		c += 4;
	if (e->m[(int)(e->ply + H)][(int)(e->plx + H)] == '1')
		c += 8;
	if (e->m[(int)(e->ply - H)][(int)(e->plx - H)] == '2')
		c += 1;
	if (e->m[(int)(e->ply + H)][(int)(e->plx - H)] == '2')
		c += 2;
	if (e->m[(int)(e->ply - H)][(int)(e->plx + H)] == '2')
		c += 4;
	if (e->m[(int)(e->ply + H)][(int)(e->plx + H)] == '2')
		c += 8;
	return (c);
}

void	wall_collision(t_eng *e, short wall)
{
	if (wall == 3)
		e->plx += 1 - (e->plx - H - (int)(e->plx - H)) + SM;
	else if (wall == 5)
		e->ply += 1 - (e->ply - H - (int)(e->ply - H)) + SM;
	else if (wall == 10)
		e->ply -= (e->ply + H - (int)(e->ply + H)) + SM;
	else
		e->plx -= (e->plx + H - (int)(e->plx + H)) + SM;
}

void	push(t_eng *e, short wall, const short in)
{
	if (in == 3 || in == 5 || in == 10 || in == 12)
		wall_collision(e, in);
	else if (wall == 'a')
		if (1 - (e->plx - H - (int)(e->plx - H)) <
			1 - (e->ply - H - (int)(e->ply - H)))
			e->plx += 1 - (e->plx - H - (int)(e->plx - H)) + SM;
		else
			e->ply += 1 - (e->ply - H - (int)(e->ply - H)) + SM;
	else if (wall == 'b')
		if (1 - (e->plx - H - (int)(e->plx - H)) <
			e->ply + H - (int)(e->ply + H))
			e->plx += 1 - (e->plx - H - (int)(e->plx - H)) + SM;
		else
			e->ply -= e->ply + H - (int)(e->ply + H) + SM;
	else if (wall == 'c')
		if (e->plx + H - (int)(e->plx + H) <
			1 - (e->ply - H - (int)(e->ply - H)))
			e->plx -= e->plx + H - (int)(e->plx + H) + SM;
		else
			e->ply += 1 - (e->ply - H - (int)(e->ply - H)) + SM;
	else if (e->plx + H - (int)(e->plx + H) <
		e->ply + H - (int)(e->ply + H))
		e->plx -= e->plx + H - (int)(e->plx + H) + SM;
	else
		e->ply -= e->ply + H - (int)(e->ply + H) + SM;
}

void	collision(t_eng *e)
{
	short		wall;
	const short in = in_walls(e);
	int			i;

	i = 4;
	while ((wall = in_wall(e)) && (i--))
		push(e, wall, in);
}
