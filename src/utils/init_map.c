/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 22:03:43 by cclarice          #+#    #+#             */
/*   Updated: 2021/01/27 03:36:34 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

t_map	init_map(void)
{
	t_map m;
	int n;

	n = 0;
	m.vr.rx = -1;
	m.vr.ry = -1;
	m.vr.fc = -1;
	m.vr.cc = -1;
	m.pt.no = NULL;
	m.pt.so = NULL;
	m.pt.we = NULL;
	m.pt.ea = NULL;
	m.pt.sp = NULL;
	m.map = NULL;
	m.cub = NULL;
	return (m);
}