/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 21:21:10 by cclarice          #+#    #+#             */
/*   Updated: 2021/01/23 21:57:43 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int		get_file_size(char *file)
{
	int		i;
	int		n;
	char	c;

	c = '\0';
	i = 0;
	if ((n = open(file, O_RDONLY)) == -1)
		return (-1);
	while (read(n, &c, 1) == 1)
		i++;
	close(n);
	return (i + 1);
}
