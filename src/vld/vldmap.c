/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vldmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 11:01:46 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/15 22:27:44 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

char	*alloc_row(int x, char c)
{
	char *row;

	if (!(row = (char *)malloc(sizeof(char) * x + 1)))
		exit((ft_printf("Error\n Malloc Error!")) * 0);
	row[x--] = '\0';
	while (x >= 0)
	{
		row[x] = c;
		x--;
	}
	return (row);
}

char	**alloc_map(int x, int y, char *text)
{
	char	**map;
	int		i;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * y + 1)) ||
		!(map[y] = alloc_row(x, '\0')))
		exit((ft_printf("Error\n Malloc Error!")) * 0);
	y--;
	while (y >= 0)
		if (!(map[y--] = alloc_row(x, ' ')))
			exit((ft_printf("Error\n Malloc Error!")) * 0);
	x = 0;
	y = 0;
	while (text[i] != 0)
	{
		if (text[i] == '\n')
		{
			x = 0;
			y++;
			i++;
		}
		else
			map[y][x++] = text[i++];
	}
	return (map);
}

char	**get_map3d(char *map)
{
	int i;
	int cx;
	int x;
	int y;

	i = 0;
	cx = 0;
	x = 0;
	y = 0;
	while (map[i] != '\0')
	{
		while (map[i] != '\n' && map[i] != '\0')
		{
			cx++;
			i++;
		}
		if (cx > x)
			x = cx;
		cx = 0;
		y++;
		if (map[i] != '\0')
			i++;
	}
	return (alloc_map(x, y, map));
}

void	check_spaces(char *m, int *e)
{
	int i;

	i = 0;
	while (m[i] == '\n')
		i++;
	while (m[i] != '\0')
	{
		if (m[i + 1] && m[i] == '\n' && m[i + 1] == '\n' && m[i + 2] != '\0')
			e[25] = 0;
		i++;
	}
	if (e[25] && m[i - 1] && m[i - 2] && m[i - 2] == '\n' && m[i - 1] == '\n')
		e[26] = 0;
}

void	vldmap(char *map, int *ei, char ***m)
{
	int i;

	i = 0;
	ei[19] = (map[0] != '\0' ? -1 : 0);
	check_spaces(map, ei);
	if (ei[19] != 0 && ei[25] != 0 && ei[26] != 0)
	{
		*m = get_map3d(map);
		validmap(*m, ei);
	}
	free(map);
}
