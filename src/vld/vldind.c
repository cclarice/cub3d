/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vldind.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 11:01:04 by cclarice          #+#    #+#             */
/*   Updated: 2021/02/09 08:38:49 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int		check_resol(char *m, int b)
{
	int i;

	i = 1;
	if (m[i] != ' ')
		return (b);
	while (m[i] == ' ')
		i++;
	if (!ft_isdigit(m[i]) || m[i] == '0')
		return (b);
	while (ft_isdigit(m[i]))
		i++;
	if (m[i] != ' ')
		return (b);
	while (m[i] == ' ')
		i++;
	if (!ft_isdigit(m[i]) || m[i] == '0')
		return (b);
	while (ft_isdigit(m[i]))
		i++;
	if (m[i] == '\n' || m[i] == '\0')
		return (-1);
	return (b);
}

int		check_addre(char *m, int b)
{
	int i;

	i = 1;
	if (m[i] != ' ')
		return (b);
	while (m[i] == ' ')
		i++;
	while (m[i] != '\n' && m[i] != '\0')
		i++;
	if (i >= 4 && m[i - 4] == '.' &&
	m[i - 3] == 'x' && m[i - 2] == 'p' && m[i - 1] == 'm')
		return (-1);
	return (b);
}

int		check_color(char *m, int b, int i)
{
	if (m[i] != ' ')
		return (b);
	while (m[i] == ' ')
		i++;
	if (!ft_isdigit(m[i]) || (m[i] != '\0' && m[i] == '0' && m[i + 1] == '0'))
		return (b);
	while (ft_isdigit(m[i]) || m[i] == ' ')
		i++;
	if (m[i++] != ',')
		return (b);
	while (m[i] == ' ')
		i++;
	if (!ft_isdigit(m[i]) || (m[i] != '\0' && m[i] == '0' && m[i + 1] == '0'))
		return (b);
	while (ft_isdigit(m[i]) || m[i] == ' ')
		i++;
	if (m[i++] != ',')
		return (b);
	while (m[i] == ' ')
		i++;
	if (!ft_isdigit(m[i]) || (m[i] != '\0' && m[i] == '0' && m[i + 1] == '0'))
		return (b);
	while (ft_isdigit(m[i]))
		i++;
	return (m[i] == '\n' || m[i] == '\0' ? -1 : b);
}

void	map_bad_idn(char *m, int *e)
{
	int i;

	i = 0;
	while (m[i] != '\0' && m[i + 1] != '\0')
	{
		m[i] == 'R' ? e[10] = check_resol(&m[i], i) : 0;
		m[i] == 'F' ? e[16] = check_color(&m[i], i, 1) : 0;
		m[i] == 'C' ? e[17] = check_color(&m[i], i, 1) : 0;
		m[i] == 'N' && m[i + 1] == 'O' ? e[11] = check_addre(&m[i + 1], i) : 0;
		m[i] == 'S' && m[i + 1] == 'O' ? e[12] = check_addre(&m[i + 1], i) : 0;
		m[i] == 'W' && m[i + 1] == 'E' ? e[13] = check_addre(&m[i + 1], i) : 0;
		m[i] == 'E' && m[i + 1] == 'A' ? e[14] = check_addre(&m[i + 1], i) : 0;
		m[i] == 'S' && m[i + 1] != 'O' ? e[15] = check_addre(&m[i], i) : 0;
		e[18] = (m[i] == 'R' || (m[i] == 'N' && m[i + 1] == 'O') ||
		(m[i] == 'S' && m[i + 1] == 'O') ||
		(m[i] == 'W' && m[i + 1] == 'E') ||
		(m[i] == 'E' && m[i + 1] == 'A') ||
		(m[i] == 'S' && m[i + 1] != 'O') ||
		m[i] == 'F' || m[i] == 'C' ? e[18] : i);
		while (m[i] != '\n' && m[i] != '\0')
			i++;
		while (m[i] == '\n')
			i++;
	}
}

void	vldidn(char *m, int *e)
{
	int i;

	i = 0;
	e[1] = 0;
	while (m[i] != '\0')
	{
		m[i] == 'R' ? e[2]++ : 0;
		m[i] == 'F' ? e[8]++ : 0;
		m[i] == 'C' ? e[9]++ : 0;
		m[i] == 'N' && m[i + 1] == 'O' ? e[3]++ : 0;
		m[i] == 'S' && m[i + 1] == 'O' ? e[4]++ : 0;
		m[i] == 'W' && m[i + 1] == 'E' ? e[5]++ : 0;
		m[i] == 'E' && m[i + 1] == 'A' ? e[6]++ : 0;
		m[i] == 'S' && m[i + 1] != 'O' ? e[7]++ : 0;
		e[1] == 0 && (e[2] >= 1 || e[3] >= 1 || e[4] >= 1 || e[5] >= 1 ||
		e[6] >= 1 || e[7] >= 1 || e[8] >= 1 || e[9] >= 1) ? e[1] = i : 0;
		while (m[i] != '\n' && m[i] != '\0')
			i++;
		while (m[i] == '\n')
			i++;
	}
	e[2] + e[3] + e[4] + e[5] + e[6] + e[7] + e[8] + e[9] > -8 ? e[0]++ : 0;
	map_bad_idn(m, e);
	free(m);
}
