/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 13:15:34 by cclarice          #+#    #+#             */
/*   Updated: 2021/02/24 00:31:29 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	p = str;
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	while (*s1)
	{
		*p = *s1;
		p++;
		s1++;
	}
	while (*s2)
	{
		*p = *s2;
		p++;
		s2++;
	}
	return (str);
}
int main(int argc, char **argv)
{
	int i;
	char *args;
	char *args2;

	args = NULL;
	args2 = NULL;
	if (argc >= 3)
		argv[2] = ft_strjoin(" ", argv[2]);
	if (argc >= 2)
	{
		args = ft_strjoin("./cub3d ", argv[1]);
		if (argc >= 3)
			args2 = ft_strjoin(args, argv[2]);
	}
	i = system("make re");
	if (i == 0)
	{
		system("clear");
		if (argc >= 3)
		{
			printf("\033[31mRun: [%s]\033[0m\n", args2);
			system(args2);
		}
		else if (argc >= 2)
		{
			printf("\033[31mRun: [%s]\033[0m\n", args);
			system(args);
		}
		else
		{
			printf("\033[31mRun: [%s]\033[0m\n", "./cub3D my_map.cub --debug");
			system("./cub3D my_map.cub -debug");
		}
	}
	free(args);
	if (args2)
		free(args2);
	while (read(0, NULL, 1))
	{
		
	}
	return (0);
}
