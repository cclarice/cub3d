/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 02:39:11 by cclarice          #+#    #+#             */
/*   Updated: 2021/02/16 22:59:22 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	ray(t_eng *e, t_ray r)
{
	
}

void	raycasting(t_eng *e)
{
	t_ray r;

	ray(e, r);
	if (e->mmp.mode != -1)
		draw_dot(&(e->rma), e->plx * e->mmp.fullb, e->ply * e->mmp.fullb, 0xffff00);
}