/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 22:30:40 by cclarice          #+#    #+#             */
/*   Updated: 2021/01/22 07:51:45 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

#define M00 "\033[0;35mWarning: Resolution is too small!"
#define E00 "\033[0;35mWidth changed to 320!"
#define E01 "\033[0;35mHeight changed to 240!"
#define M01 "\033[0;35mWarning: Resolution is too large!"
#define E02 "\033[0;35mWidth changed to 2560!"
#define E03 "\033[0;35mHeight changed to 1440!"
#define M02 "\033[0;31mError: No screen resolution!"
#define E04 "\033[0;31m       Put resolutions in *.map R <Width> <Height>"
#define E05 "\033[0;31m       One or Both of resolutions is not specified!"
#define E06 "\033[0;31mError: North texture path is not specified!"
#define E07 "\033[0;31mError: North texture path is empty!"
#define E08 "\033[0;31mError: South texture path is not specified!"
#define E09 "\033[0;31mError: South texture path is empty!"
#define E10 "\033[0;31mError: West texture path is not specified!"
#define E11 "\033[0;31mError: West texture path is empty!"
#define E12 "\033[0;31mError: East texture path is not specified!"
#define E13 "\033[0;31mError: East texture path is empty!"
#define E14 "\033[0;31mError: Sprite texture path is not specified!"
#define E15 "\033[0;31mError: Sprite texture path is empty!"
#define E16 "\033[0;31mError: Floor color is not specified"
#define E17 "\033[0;31mError: Floor color is empty"
#define E18 "\033[0;31mError: Floor color is bad"
#define E19 "\033[0;31mError: Ceiling color is not specified"
#define E20 "\033[0;31mError: Ceiling color is empty"
#define E21 "\033[0;31mError: Ceiling color is bad"

int		p_str(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		write(1, &(str[i++]), 1);
	write(1, "\n", 1);
	return (1);
}

int		get_address(char *map, int c)
{
	int i;

	i = 0;
	if (c == 3)
		return (3);
	while (map[i] != '.' && (map[i] < '0' || map[i] > '9'))
	{
		if (map[i] == '\0' || map[i] == '\n')
			return (0);
		i++;
	}
	if (c == 2)
		while (map[i] >= '0' && map[i] <= '9')
		{
			if (map[i] == '\0' || map[i] == '\n')
				return (0);
			i++;
		}
	while (map[i] == ' ')
				i++;
	return (i);
}

int 	say_index(int i, char *map, int c)
{
	if (i >= 0)
	{
		ft_printf("\033[0m  \u21E5 ");
		p_str(&(map[i]));
		ft_printf("  %*s ", get_address(&(map[i]), c) + 5, "\u21B3");
	}
	return (1);
}

void	say_error(char *e, int *i, char *map)
{
	(e[0] == '1' || e[1] == '1') ? p_str(M00) : 0;
	e[0] == '1' && say_index(i[0], map, 1) ? p_str(E00) : 0;
	e[1] == '1' && say_index(i[0], map, 2) ? p_str(E01) : 0;
	(e[2] == '1' || e[3] == '1') ? p_str(M01) : 0;
	e[2] == '1' && say_index(i[0], map, 1) ? p_str(E02) : 0;
	e[3] == '1' && say_index(i[0], map, 2) ? p_str(E03) : 0;
	(e[4] == '1' || e[5] == '1') && p_str(M02) ? say_index(-1, map, 1) : 0;
	e[4] == '1' ? p_str(E04) : 0;
	e[5] == '1' && say_index(i[0], map, 2) ? p_str(E05) : 0;
	e[6] == '1' ? p_str(E06) : 0;
	e[7] == '1' && say_index(i[7], map, 3)? p_str(E07) : 0;
	e[8] == '1' ? p_str(E08) : 0;
	e[9] == '1' && say_index(i[9], map, 3)? p_str(E09) : 0;
	e[10] == '1' ? p_str(E10) : 0;
	e[11] == '1' && say_index(i[11], map, 3)? p_str(E11) : 0;
	e[12] == '1' ? p_str(E12) : 0;
	e[13] == '1' && say_index(i[13], map, 3)? p_str(E13) : 0;
	e[14] == '1' ? p_str(E14) : 0;
	e[15] == '1' && say_index(i[15], map, 3)? p_str(E15) : 0;
	e[16] == '1' ? p_str(E16) : 0;
	e[17] == '1' && say_index(i[17], map, 1) ? p_str(E17) : 0;
	e[18] == '1' && say_index(i[18], map, 1) ? p_str(E18) : 0;
	e[19] == '1' ? p_str(E19) : 0;
	e[20] == '1' && say_index(i[20], map, 1) ? p_str(E20) : 0;
	e[21] == '1' && say_index(i[21], map, 1) ? p_str(E21) : 0;
}

void	map_error(char *map, t_cube cube)
{
	char *str_error;

	str_error = int_to_bin(cube.error);
	say_error(str_error, cube.error_index, map);
}