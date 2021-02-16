/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:38:43 by cclarice          #+#    #+#             */
/*   Updated: 2021/01/22 07:51:27 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		get_map(char *name, int debug)
{
	int		n;
	char	*map;
 
	if (!(map = (char *)malloc(sizeof(char) * 64001)))
		return (1);
	n = open(name, O_RDONLY);
	read(n, map, 64000);
	close(n);
	if (n != -1)
		cube_init(map, debug);
	else
		write(1, "Error\n\033[31mMap is not found\n", 29);
	free(map);
	return (1);
}

int		main(int c, char **v)
{
	int debug;

	debug = 0;
	if (c >= 3 && v[2][0] == '-' && v[2][1] == 'd' && v[2][2] == 'e'
		&& v[2][3] == 'b' && v[2][4] == 'u' && v[2][5] == 'g' && v[2][6] == '\0')
		debug = 1;
	if (c >= 2)
		get_map(v[1], debug);
	else
		write(1, "Error\n\033[31mNeed a map in format *.cub\n", 40);
	return (0);
}
