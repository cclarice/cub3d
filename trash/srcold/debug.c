/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 02:54:24 by cclarice          #+#    #+#             */
/*   Updated: 2021/01/22 07:51:32 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	map_debug(char *map, t_cube cube)
{
	int n;
	
	n = 0;
	write(1,"\033[33m[=DEBUG============================FILE=]\033[90;2m\n", 54);
	write(1, "  \033[91m[\033[90m", 13);
	while (map[n] != '\0')
	{
		if (map[n] == '\n')
			write(1, "\033[93m]\033[90m", 11);
		write(1, &(map[n++]), 1);
		if (n != 0 && map[n - 1] == '\n')
			write(1, "  \033[93m[\033[90m", 13);
	}
	write(1, "\033[91m]\033[0m", 11);
	write(1,"\n\033[33m[=DEBUG============================VARS=]\033[0m\n", 52);
	ft_printf("  [Resolution X Y] [ \033[36m%d | %d\033[0m ]\n", cube.x,cube.y);
	ft_printf("  [Path NO] [ \033[36m%s\033[0m ]\n", cube.no != NULL ? cube.no : "NULL");
	ft_printf("  [Path SO] [ \033[36m%s\033[0m ]\n", cube.so != NULL ? cube.so : "NULL");
	ft_printf("  [Path WE] [ \033[36m%s\033[0m ]\n", cube.we != NULL ? cube.we : "NULL");
	ft_printf("  [Path EA] [ \033[36m%s\033[0m ]\n", cube.ea != NULL ? cube.ea : "NULL");
	ft_printf("  [Path SP] [ \033[36m%s\033[0m ]\n", cube.sp != NULL ? cube.sp : "NULL");
	ft_printf("  [Colors   Floor] [ \033[31m%d\033[0m |", get_r(cube.f));
	ft_printf(" \033[32m%d\033[0m | \033[34m%d\033[0m ]", get_g(cube.f), get_b(cube.f));
	ft_printf(" [\033[48;2;%d;%d;%dm   \033[49m]\n", get_r(cube.f), get_g(cube.f), get_b(cube.f));
	ft_printf("  [Colors Ceiling] [ \033[31m%d\033[0m |", get_r(cube.c));
	ft_printf(" \033[32m%d\033[0m | \033[34m%d\033[0m ]", get_g(cube.c), get_b(cube.c));
	ft_printf(" [\033[48;2;%d;%d;%dm   \033[49m]\n", get_r(cube.c), get_g(cube.c), get_b(cube.c));
	ft_printf("  [ERROR CODE]  [%s]\n", int_to_bin(cube.error));
	write(1,"\033[33m[=DEBUG=============================MAP=]\033[0m\n", 52);
	ft_printf("  [Map Size] [ %d ] [ %d ]\n", cube.mx, cube.my);
	n = 0;
	while (cube.map[n][0] != '\0')
		ft_printf("  \033[2;93m[\033[90m%s\033[93m]\033[90m\n", cube.map[n++]);
	write(1,"\033[0;33m[=DEBUG=============================MAP=]\033[0m\n", 53);
}