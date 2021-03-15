/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:40:19 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/15 21:33:47 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

char	*ft_strdup(char *src)
{
	int		l;
	char	*str;

	l = 0;
	while (src[l] != '\0')
		l++;
	str = (char*)malloc(sizeof(*str) * (l + 1));
	if (!str)
		exit((ft_printf("Error\n Malloc Error!")) * 0);
	str[l] = '\0';
	while (l >= 0)
	{
		str[l] = src[l];
		l--;
	}
	return (str);
}
