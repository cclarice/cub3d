/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:12:53 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/14 14:44:13 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

/*
**  c  ___
** cxc _x_
**  c  __c
*/

void	validmap(char **m, int *e)
{
	int x;
	int y;
	int p;

	p = 0;
	x = -1;
	y = 1;
	while (m[0][++x] != '\0')
		m[0][x] != ' ' && m[0][x] != '1' ? e[20] = 0 : 0;
	x = -1;
	while (m[++x][0] != '\0')
		m[x][0] != ' ' && m[x][0] != '1' ? e[20] = 0 : 0;
	x = 1;
	while (m[y][0] != '\0')
	{
		m[y][x] != ' ' && m[y][x] != '1' && (
		m[y - 1][x] == ' ' || m[y][x - 1] == ' ' ||
		m[y][x + 1] == ' ' || m[y + 1][x] == ' ' ||
		m[y + 1][x + 1] == '\0') ? e[20] = 0 : 0;
		x++ && (m[y][x - 1] == 'N' || m[y][x - 1] == 'S' ||
		m[y][x - 1] == 'W' || m[y][x - 1] == 'E') ? p++ : 0;
		m[y][x] == '\0' && y++ ? x = 1 : 0;
	}
	p == 0 ? e[21] = 0 : 0;
	p >= 2 ? e[22] = 0 : 0;
}
