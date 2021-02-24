/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 01:55:36 by cclarice          #+#    #+#             */
/*   Updated: 2021/02/24 06:15:32 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	get_rgb(int color, int *r, int *g, int *b)
{
	*r = get_alpha(color);
	*g = get_alpha(color);
	*b = get_alpha(color);
}

int		get_alpha(int argb)
{
	return (argb & (0xFF << 24));
}

int		get_red(int argb)
{
	return (argb & (0xFF << 16));
}

int		get_green(int argb)
{
	return (argb & (0xFF << 8));
}

int		get_blue(int argb)
{
	return (argb & 0xFF);
}
