/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 22:40:12 by cclarice          #+#    #+#             */
/*   Updated: 2021/01/23 19:11:24 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		is_map(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S' || c == 'E'
										|| c == 'W' || c == ' ' || c == '\n')
		return (1);
	return (0);
}

char	*alloc_row(int x, char c)
{
	char *row;

	if (!(row = (char *)malloc(sizeof(char) * x + 1)))
		return (NULL);
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
	char **map;
	int i;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * y + 1)))
		return (NULL);
	if (!(map[y] = alloc_row(x, '\0')))
		return (NULL);
	y--;
	while (y >= 0)
	{
		if (!(map[y] = alloc_row(x, ' ')))
			return (NULL);
		y--;
	}
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
		{
			map[y][x] = text[i];
			x++;
			i++;
		}
	}
	return (map);
}

void	vld_map(char *map, t_cube *cube)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (map[i] != '\0')
		i++;
	while (map[i] == '\n' || map[i] == '\0')
		i--;
	while (is_map(map[i]))
	{
		if (map[i] == '\n')
		{
			if (cube->mx < x)
				cube->mx = x;
			x = 0;
			cube->my++;
		}
		x++;
		i--;
	}
	cube->mx--;
	while (map[i] != '\n')
		i++;
	while (map[i++] == '\n')
		cube->my--;
	i--;
	cube->map = alloc_map(cube->mx, cube->my, &(map[i]));
}

void	vld_end(char *map, t_cube cube, int debug)
{
	t_mlx mlx;
	!cube.no ? cube.error = cube.error | 64 : 0 ;
	cube.no && cube.no[0] == '\0' ? cube.error = cube.error | 128 : 0 ;
	!cube.so ? cube.error = cube.error | 256 : 0 ;
	cube.so && cube.so[0] == '\0' ? cube.error = cube.error | 512 : 0 ;
	!cube.we ? cube.error = cube.error | 1024 : 0 ;
	cube.we && cube.we[0] == '\0' ? cube.error = cube.error | 2048 : 0 ;
	!cube.ea ? cube.error = cube.error | 4096 : 0 ;
	cube.ea && cube.ea[0] == '\0' ? cube.error = cube.error | 8192 : 0 ;
	!cube.sp ? cube.error = cube.error | 16384 : 0 ;
	cube.sp && cube.sp[0] == '\0' ? cube.error = cube.error | 32768 : 0 ;
	cube.error_index[16] != 1 ? cube.error = cube.error | 65536 : 0 ;
	cube.error_index[17] != -1 ? cube.error = cube.error | 131072 : 0 ;
	cube.error_index[18] != -1 && cube.error_index[17] == -1 ? cube.error = cube.error | 262144 : 0;
	cube.error_index[19] != 1 ? cube.error = cube.error | 524288 : 0 ;
	cube.error_index[20] != -1 ? cube.error = cube.error | 1048576 : 0 ;
	cube.error_index[21] != -1 && cube.error_index[20] == -1 ? cube.error = cube.error | 2097152 : 0;
	vld_map(map, &cube);
	if (cube.error & 4292870128)
		write(1, "Error\n", 6);
	if (debug)
		map_debug(map, cube);
	map_error(map, cube);
	image_init(&mlx, cube);
}

void	vld_color(char *map, t_cube cube, int debug)
{
	int i;

	i = 0;
	while (map[i] != 0)
	{
		while (map[i] == ' ')
			i++;
		if (map[i] == 'F' && cube.f == -1 && map[++i] != 0 && (cube.error_index[16] = 1))
		{
			cube.f = create_rgb(ft_atoi(&map[i]), ft_atois(&map[i]), ft_atoit(&map[i]));
			ft_atoit(&map[i]) >= 256 || ft_atois(&map[i]) >= 256 || ft_ftc(&map[i]) ||
			ft_atoi(&map[i]) >= 256 || ft_atoit(&map[i]) < 0 ? cube.error_index[18] = i - 1 : 0;
			ft_isempty(&map[i]) ? cube.error_index[17] = i - 1 : 0;
		}
		if (map[i] == 'C' && cube.c == -1 && map[++i] != 0 && (cube.error_index[19] = 1))
		{
			cube.c = create_rgb(ft_atoi(&map[i]), ft_atois(&map[i]), ft_atoit(&map[i]));
			ft_atoit(&map[i]) >= 256 || ft_atois(&map[i]) >= 256 || ft_ftc(&map[i]) ||
			ft_atoi(&map[i]) >= 256 || ft_atoit(&map[i]) < 0 ? cube.error_index[21] = i - 1 : 0;
			ft_isempty(&map[i]) ? cube.error_index[20] = i - 1 : 0;
		}
		while (map[i] != '\n' && map[i] != '\0')
			i++;
		if (map[i] == '\n')
			i++;
	}
	vld_end(map, cube, debug);
}

char	*vld_gpth(char *map, int i)
{
	char	*path;
	int		c;

	c = 0;
	i += 2;
	if (map[i] != ' ')
		return (NULL);
	while (map[i] == ' ')
		i++;
	path = (char *)malloc(sizeof(char) * ft_pthlen(&(map[i]) + 1));
	while (map[i] != '\n' && map[i] != '\0')
		path[c++] = map[i++];
	path[c] = '\0';
	return (path);
}

void	vld_path(char *map, t_cube cube, int debug)
{
	int i;

	i = 0;
	while (map[i] != 0 && map[i + 1] != 0)
	{
		while (map[i] == ' ')
			i++;
		!cube.no && map[i] == 'N' && map[i + 1] == 'O' ? cube.no = vld_gpth(map, i) : 0;
		cube.no && map[i] == 'N' && map[i + 1] == 'O' && cube.no[0] == '\0' ? cube.error_index[7] = i : 0;
		!cube.so && map[i] == 'S' && map[i + 1] == 'O' ? cube.so = vld_gpth(map, i) : 0;
		cube.so && map[i] == 'S' && map[i + 1] == 'O' && cube.so[0] == '\0' ? cube.error_index[9] = i : 0;
		!cube.we && map[i] == 'W' && map[i + 1] == 'E' ? cube.we = vld_gpth(map, i) : 0;
		cube.we && map[i] == 'W' && map[i + 1] == 'E' && cube.we[0] == '\0' ? cube.error_index[11] = i : 0;
		!cube.ea && map[i] == 'E' && map[i + 1] == 'A' ? cube.ea = vld_gpth(map, i) : 0;
		cube.ea && map[i] == 'E' && map[i + 1] == 'A' && cube.ea[0] == '\0' ? cube.error_index[13] = i : 0;
		!cube.sp && map[i] == 'S' && map[i + 1] != 'O' ? cube.sp = vld_gpth(map, i - 1) : 0;
		cube.sp && map[i] == 'S' && map[i + 1] != 'O' && cube.sp[0] == '\0' ? cube.error_index[15] = i : 0;
		while (map[i] != '\n' && map[i] != '\0')
			i++;
		if (map[i] == '\n')
			i++;
	}
	vld_color(map, cube, debug);
}

void	vld_resolution(char *map, t_cube cube, int debug)
{
	int i;

	i = 0;
	while (map[i] != 0)
	{
		while (map[i] == ' ')
			i++;
		if (map[i] == 'R' && (cube.x == -1 || cube.y == -1))
		{
			cube.error_index[0] = i;
			(cube.error & 16) == 16 ? cube.error = 0 : 0;
			cube.x = ft_atoi(&(map[i + 1]));
			cube.y = ft_atois(&(map[i + 1]));
			cube.x < 320 && cube.x != -1 && cube.y != -1 ? cube.error = cube.error | 1 : 0;
			cube.y < 240 && cube.y != -1 && cube.x != -1 ? cube.error = cube.error | 2 : 0;
			cube.x > 2560 ? cube.error = cube.error | 4 : 0;
			cube.y > 1440 ? cube.error = cube.error | 8 : 0;
			cube.y == -1 || ft_ftr(&map[i]) ? cube.error = cube.error | 32 : 0;
			cube.x > 2560 ? cube.x = 2560 : 0;
			cube.y > 1440 ? cube.y = 1440 : 0;
			cube.x < 320 && cube.x != -1 ? cube.x = 320 : 0;
			cube.y < 240 && cube.y != -1 ? cube.y = 240 : 0;
		}
		while (map[i] != '\n' && map[i] != '\0')
			i++;
		if (map[i] == '\n')
			i++;
	}
	vld_path(map, cube, debug);
}

void	cube_init(char *map, int debug)
{
	t_cube cube;

	cube.x = -1;
	cube.y = -1;
	cube.no = NULL;
	cube.so = NULL;
	cube.we = NULL;
	cube.ea = NULL;
	cube.sp = NULL;
	cube.map = NULL;
	cube.mx = 0;
	cube.my = 1;
	cube.error = 32;
	cube.error_index = (int *)malloc(sizeof(int) * 32);
	while(--cube.error != 0)
		cube.error_index[cube.error] = -1;
	cube.error = 16;
	cube.f = -1;
	cube.c = -1;
	vld_resolution(map, cube, debug);
}