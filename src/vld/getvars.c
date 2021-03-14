/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getvars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 01:11:40 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/14 09:05:48 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int		get_path_len(char *m)
{
	int i;

	i = 0;
	while (m[i] != '\n' && m[i] != '\0')
		i++;
	return (i);
}

int		get_resol(char *m, int *x, int *y, int b)
{
	int i;

	i = 0;
	while (m[i] == ' ')
		i++;
	if ((x[0] = ft_atoi(&m[i])) > 16384)
		return (b);
	while (ft_isdigit(m[i]))
		i++;
	while (m[i] == ' ')
		i++;
	if ((y[0] = ft_atoi(&m[i])) > 16384)
		return (b);
	return (-1);
}

int		get_path(char *m, char **path)
{
	int i;
	int l;

	i = 0;
	while (m[i] == ' ')
		i++;
	l = get_path_len(&m[i]);
	path[0] = (char *)malloc(sizeof(char) * l + 1);
	path[0][l] = '\0';
	l = 0;
	while (m[i] != '\n' && m[i] != '\0')
		path[0][l++] = m[i++];
	return (0);
}

int		get_color(char *m, int *c, int e)
{
	int r;
	int g;
	int b;
	int i;

	i = 0;
	r = ft_atoi(&m[i]);
	while (m[i] == ' ' || ft_isdigit(m[i]))
		i++;
	while (m[i] == ' ' || m[i] == ',')
		i++;
	g = ft_atoi(&m[i]);
	while (m[i] == ' ' || ft_isdigit(m[i]))
		i++;
	while (m[i] == ' ' || m[i] == ',')
		i++;
	b = ft_atoi(&m[i]);
	c[0] = create_rgb(r, g, b);
	return (r <= 255 && g <= 255 && b <= 255 ? -1 : e);
}

void	getvars(char *m, t_path *pt, t_vars *vr, int *er)
{
	int i;

	i = 0;
	while (m[i] != '\0' && m[i + 1] != '\0')
	{
		m[i] == 'R' ? er[10] = get_resol(&m[i + 1], &vr->rx, &vr->ry, i) : 0;
		m[i] == 'F' ? er[23] = get_color(&m[i + 1], &vr->fc, i) : 0;
		m[i] == 'C' ? er[24] = get_color(&m[i + 1], &vr->cc, i) : 0;
		m[i] == 'N' && m[i + 1] == 'O' ? get_path(&m[i + 2], &pt->no) : 0;
		m[i] == 'S' && m[i + 1] == 'O' ? get_path(&m[i + 2], &pt->so) : 0;
		m[i] == 'W' && m[i + 1] == 'E' ? get_path(&m[i + 2], &pt->we) : 0;
		m[i] == 'E' && m[i + 1] == 'A' ? get_path(&m[i + 2], &pt->ea) : 0;
		m[i] == 'S' && m[i + 1] != 'O' ? get_path(&m[i + 1], &pt->sp) : 0;
		while (m[i] != '\n' && m[i] != '\0')
			i++;
		while (m[i] == '\n')
			i++;
	}
}
