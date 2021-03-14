/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 21:03:29 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/14 17:48:37 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int		is_map(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S' || c == 'E'
										|| c == 'W' || c == ' ' || c == '\n')
		return (1);
	return (0);
}

char	*get_idn(char *map)
{
	int i;

	i = 0;
	while (map[i] != '\0')
		i++;
	i--;
	while (i >= 0 && is_map(map[i]))
		i--;
	while (map[i] != '\n' && map[i] != '\0')
		i++;
	map[i] = '\0';
	return (map);
}

char	*get_map(char *map)
{
	char	*m;
	int		i;
	int		b;

	b = 0;
	i = 0;
	while (map[i] != '\0')
		i++;
	i--;
	while (i >= 0 && is_map(map[i]))
		i--;
	while (map[i] != '\n' && map[i] != '\0')
		i++;
	while (map[i] == '\n')
		i++;
	m = ft_strdup(&(map[i]));
	return (m);
}

int		has_errors(int *e)
{
	if (e[0] == 0 && e[1] == 0 && e[2] == 0 && e[3] == 0 &&
		e[4] == 0 && e[5] == 0 && e[6] == 0 && e[7] == 0 &&
		e[8] == 0 && e[9] == 0 && e[10] == -1 && e[11] == -1 &&
		e[12] == -1 && e[13] == -1 && e[14] == -1 && e[15] == -1 &&
		e[16] == -1 && e[17] == -1 && e[18] == -1 && e[19] == -1 &&
		e[20] == -1 && e[21] == -1 && e[22] == -1 && e[23] == -1 &&
		e[24] == -1 && e[25] == -1 && e[26] == -1)
		return (0);
	return (1);
}

int		vld(char *map, char ***m, t_path *pt, t_vars *vr)
{
	long	er;
	int		ei[27];

	er = 27;
	while (er > 0)
		ei[--er] = -1;
	vldidn(get_idn(ft_strdup(map)), ei);
	vldmap(get_map(map), ei, &m[0]);
	if (!has_errors(ei))
	{
		getvars(map, pt, vr, ei);
		if (!has_errors(ei))
			return (1);
	}
	ft_printf("Error\n");
	put_errors(map, ei);
	color_error(map, ei);
	return (0);
}
