/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 03:01:26 by cclarice          #+#    #+#             */
/*   Updated: 2021/01/22 07:51:41 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		skip_s(char *str)
{
	int n;

	n = 0;
	while (str[n] == ' ')
		n++;
	return (n);
}

char *int_to_bin(int k)
{
   	char *bin;
   	int n;
	
   	n = 0;
   	bin = (char *)malloc(sizeof(char) * 25);
   	while(n != 25)
   	{
   	  	if (k%2)
			bin[n] = '1';
		else
			bin[n] = '0';
   	  	k = k/2;
   	  	n++;
   	}
   	bin[24] = '\0';
	
   	return (bin);
}

int		ft_atoi(const char *str)
{
	long	r;
	int		n;

	n = 1;
	r = 0;
	while (*str == ' ' || *str == ',')
		++str;
	if (*str == '\n')
		++str;
	if (*str == '-')
		n = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str >= '0' && *str <= '9' && r <= 2147483648)
	{
		r = r * 10;
		r += *str - 48;
		++str;
	}
	if (r >= 2147483648 && n == 1)
		return (-1);
	if (r > 2147483648 && n == -1)
		return (0);
	if (r == 0 && str[-1] != '0')
		return (-1);
	return (n * r);
}

int		ft_atoit(const char *str)
{
	while (*str == ' ' || *str == ',')
		++str;
	while (*str >= '0' && *str <= '9')
		++str;
	return (ft_atois(str));
}

int		ft_atois(const char *str)
{
	while (*str == ' ' || *str == ',')
		++str;
	while (*str >= '0' && *str <= '9')
		++str;
	return (ft_atoi(str));
}

int		ft_pthlen(char *pth)
{
	int i;

	i = 0;
	while (pth[i] != '\n' && pth[i] != '\0')
		i++;
	return (i);
}

int		ft_isempty(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (0);
		++i;
	}
	return (1);
}

int		ft_ftr(char *str)
{
	str++;
	if (*str != ' ')
		return (1);
	while (*str == ' ')
		++str;
	while (*str >= '0' && *str <= '9')
		++str;
	while (*str == ' ')
		++str;
	while (*str >= '0' && *str <= '9')
		++str;
	if (*str == '\0' || *str == '\n')
		return (0);
	return (1);
}

int		ft_ftc(char *str)
{
	if (*str != ' ')
		return (1);
	while (*str == ' ')
		++str;
	while (*str >= '0' && *str <= '9')
		++str;
	while (*str == ' ')
		++str;
	if (*str == ',')
		++str;
	while (*str == ' ')
		++str;
	while (*str >= '0' && *str <= '9')
		++str;
	while (*str == ' ')
		++str;
	if (*str == ',')
		++str;
	while (*str == ' ')
		++str;
	while (*str >= '0' && *str <= '9')
		++str;
	if (*str == '\0' || *str == '\n')
		return (0);
	return (1);
}