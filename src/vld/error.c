/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 21:04:37 by cclarice          #+#    #+#             */
/*   Updated: 2021/02/09 10:08:22 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

#define E00 "  Cub has no identifiers"
#define E01 "  Cub has duplicated identifier"
#define E02 "  Cub has no Resolution identifier"
#define E03 "  Cub has no North texture identifier"
#define E04 "  Cub has no South texture identifier"
#define E05 "  Cub has no West texture identifier"
#define E06 "  Cub has no East texture identifier"
#define E07 "  Cub has no Sprite texture identifier"
#define E08 "  Cub has no Floor color identifier"
#define E09 "  Cub has no Ceilling color identifier"
#define E10 "  Cub has bad Resolution"
#define E11 "  Cub has bad North texture path"
#define E12 "  Cub has bad South texture path"
#define E13 "  Cub has bad West texture path"
#define E14 "  Cub has bad East texture path"
#define E15 "  Cub has bad Sprite texture path"
#define E16 "  Cub has bad Floor color"
#define E17 "  Cub has bad Ceilling color"
#define E18 "  Cub has some trash"
#define E19 "  Cub has no map"
#define E20 "  The map must be closed"
#define E21 "  The map has no player’s start position"
#define E22 "  The map has more than one player’s start position"
#define	E23 "  The map has too high Floor color"
#define	E24 "  The map has too high Ceilling color"
#define	E25 "  The map has has a double line break"
#define	E26 "  The map has line break at the end"

int		len(char *map)
{
	int i;

	i = 0;
	while (map[i] != '\n' && map[i] != '\0')
		i++;
	return (i);
}

void	put_error(char *map, int *e)
{
	e[2] == -1 ? ft_printf("\033[31m%s\n", E02) : 0;
	e[3] == -1 ? ft_printf("\033[31m%s\n", E03) : 0;
	e[4] == -1 ? ft_printf("\033[31m%s\n", E04) : 0;
	e[5] == -1 ? ft_printf("\033[31m%s\n", E05) : 0;
	e[6] == -1 ? ft_printf("\033[31m%s\n", E06) : 0;
	e[7] == -1 ? ft_printf("\033[31m%s\n", E07) : 0;
	e[8] == -1 ? ft_printf("\033[31m%s\n", E08) : 0;
	e[9] == -1 ? ft_printf("\033[31m%s\n", E09) : 0;
	e[10] != -1 ? ft_printf("\033[0m  [%.*s]\n\033[31m^   %s\n", len(&map[e[10]]), &map[e[10]], E10) : 0;
	e[11] != -1 ? ft_printf("\033[0m  [%.*s]\n\033[31m^   %s\n", len(&map[e[11]]), &map[e[11]], E11) : 0;
	e[12] != -1 ? ft_printf("\033[0m  [%.*s]\n\033[31m^   %s\n", len(&map[e[12]]), &map[e[12]], E12) : 0;
	e[13] != -1 ? ft_printf("\033[0m  [%.*s]\n\033[31m^   %s\n", len(&map[e[13]]), &map[e[13]], E13) : 0;
	e[14] != -1 ? ft_printf("\033[0m  [%.*s]\n\033[31m^   %s\n", len(&map[e[14]]), &map[e[14]], E14) : 0;
	e[15] != -1 ? ft_printf("\033[0m  [%.*s]\n\033[31m^   %s\n", len(&map[e[15]]), &map[e[15]], E15) : 0;
	e[16] != -1 ? ft_printf("\033[0m  [%.*s]\n\033[31m^   %s\n", len(&map[e[16]]), &map[e[16]], E16) : 0;
	e[17] != -1 ? ft_printf("\033[0m  [%.*s]\n\033[31m^   %s\n", len(&map[e[17]]), &map[e[17]], E17) : 0;
	e[18] != -1 ? ft_printf("\033[0m  [%.*s]\n\033[31m^   %s\n", len(&map[e[18]]), &map[e[18]], E18) : 0;
	e[19] != -1 ? ft_printf("\033[31m%s\n", E19) : 0;
	e[20] != -1 ? ft_printf("\033[31m%s\n", E20) : 0;
	e[21] != -1 ? ft_printf("\033[31m%s\n", E21) : 0;
	e[22] != -1 ? ft_printf("\033[31m%s\n", E22) : 0;
}

void	put_errors(char *map, int *e)
{
	e[0] == -1 ? ft_printf("\033[31m%s\n", E00) : 0;
	e[1] >= 1 ? ft_printf("%.*s\n\033[31m^   %s\n", len(&map[e[1]]), &map[e[1]] , E01) : 0;
	if (e[0] != -1 && e[1] != -1)
		put_error(map, e);
}

int		color_error(char *map, int *e)
{
	e[23] != -1 ? ft_printf("\033[0m  [%.*s]\n\033[31m^   %s\n", len(&map[e[23]]), &map[e[23]], E23) : 0;
	e[24] != -1 ? ft_printf("\033[0m  [%.*s]\n\033[31m^   %s\n", len(&map[e[24]]), &map[e[24]], E24) : 0;
	e[25] != -1 ? ft_printf("\033[0m  \033[31m%s\n", E25) : 0;
	e[26] != -1 ? ft_printf("\033[0m  \033[31m%s\n", E26) : 0;
	return (e[23] != -1 && e[23] != -1 ? 1 : 0);
}
