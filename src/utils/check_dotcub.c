/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dotcub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 22:13:23 by cclarice          #+#    #+#             */
/*   Updated: 2021/01/27 06:30:41 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int		check_dotcub(char *name)
{
	int i;

	i = 0;
	if (!name)
	{
		ft_printf("Error\n\033[31mSpecify path to * .cub file!\n");
		return (1);
	}
	while (name[i] != '\0')
		i++;
	if (i >= 4 && name[i - 4] == '.' && name[i - 3] == 'c' && name[i - 2] == 'u' &&
														name[i - 1] == 'b')
		return (0);
	ft_printf("Error\n\033[31mThe file is not in .cub format!\n");
	return (1);
}