/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 13:33:10 by cclarice          #+#    #+#             */
/*   Updated: 2021/02/26 02:08:59 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

#define SUCCESS ft_printf("\033[92mSuccesful End \U0001f918\n")
#define NO_MAP ft_printf("Error\n\033[31mMap is not found!\n")

void	info(t_map m)
{
	int i;

	i = 0;
	ft_printf("\033[93m[ ====== debug ====== ]\n");
	ft_printf("\033[33mno: %s\n", m.pt.no);
	ft_printf("\033[93mso: %s\n", m.pt.so);
	ft_printf("\033[33mwe: %s\n", m.pt.we);
	ft_printf("\033[93mea: %s\n", m.pt.ea);
	ft_printf("\033[33msp: %s\n", m.pt.sp);
	ft_printf("\033[93mrx: %d\n", m.vr.rx);
	ft_printf("\033[33mry: %d\n", m.vr.ry);
	ft_printf("\033[93mfc: #%.6X\n", m.vr.fc);
	ft_printf("\033[33mcc: #%.6X\n", m.vr.cc);
	ft_printf("\033[93mmp:\033[94m\n");
	while (m.map[i][0] != '\0')
		ft_printf("   %s\n", m.map[i++]);
	ft_printf("\033[93m[ =================== ]\n");
}

/*
**	if ((c >= 3 && ft_strstr(v[2], "--save") ||
**		(c >= 4 && ft_strstr(v[3], "--save"))))
**		ft_printf("--save ON\n");
**	if ((c >= 3 && ft_strstr(v[2], "--debug") ||
**		(c >= 3 && ft_strstr(v[3], "--debug"))))
**		ft_printf("--debug ON\n");
*/

int		main(int c, char **v)
{
	t_map	m;

	m = init_map();
	if (c >= 3 && ft_strstr(v[2], "--save"))
		m.vr.mode = 1;
	else if (c >= 3 && ft_strstr(v[2], "--debug"))
		m.vr.mode = 2;
	else
		m.vr.mode = 0;
	if (check_dotcub(v[1]))
		return (0);
	if (c >= 2 && (m.cub = file_to_str(v[1], get_file_size(v[1]))))
	{
	 	if (vld(m.cub, &m.map, &m.pt, &m.vr))
				initialization(m.pt, m.vr, m.map);
	}
	else
		return (NO_MAP);
	info(m);
	free(m.cub);
	return (SUCCESS);
}
