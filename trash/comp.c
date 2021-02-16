/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 13:15:34 by cclarice          #+#    #+#             */
/*   Updated: 2021/01/24 16:44:00 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int i;

	i = system("make re");
	system("killall cub3D");
	if (i == 0)
	{
		system("clear");
		system("./cub3D my_map.cub -debug");
	}
	return (0);
}
