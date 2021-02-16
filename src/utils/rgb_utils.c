/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 04:47:30 by cclarice          #+#    #+#             */
/*   Updated: 2021/01/27 04:48:20 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int		create_rgb(int r, int g, int b)
{
	return(r << 16 | g << 8 | b);
}

int		get_r(int rgb)
{
	if (0x80000000 & rgb)
		return (-1);
	return ((rgb & 0xFF0000) >> 16);
}

int		get_g(int rgb)
{
	if (0x80000000 & rgb)
		return (-1);
	return ((rgb & 0x00FF00) >> 8);
}

int		get_b(int rgb)
{
	if (0x80000000 & rgb)
		return (-1);
	return (rgb & 0x0000FF);
}