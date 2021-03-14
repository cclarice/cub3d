/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:30:34 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/14 09:56:20 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

#define KEYW 13
#define KEYA 0
#define KEYS 1
#define KEYD 2
#define KEYR 124
#define KEYL 123
#define KEYM 46
#define KEYF3 99
#define KEYMM 10

void		keyboard_init(t_eng *e)
{
	e->cnt.kw = 0;
	e->cnt.ka = 0;
	e->cnt.ks = 0;
	e->cnt.kd = 0;
	e->cnt.kr = 0;
	e->cnt.kl = 0;
	e->cnt.kf3 = 0;
}

/*
**	void	console(t_eng *e)
**	{
**		char str[100];
**
**		str[0] = '\0';
**		str[read(0, &str, 100)] = 0;
**		if (str[0] == 't' && str[1] == 'p' && str[2])
**		{
**			write(1, "blya\n", 5);
**		}
**		else if (str[0] == 'a' && str[1])
**		{
**			str[1] == 'S' || str[1] == 's' ? e->pla = 0 : 0;
**	 		str[1] == 'W' || str[1] == 'w' ? e->pla = P / 0.5 : 0;
**	 		str[1] == 'N' || str[1] == 'n' ? e->pla = P : 0;
**	 		str[1] == 'E' || str[1] == 'e' ? e->pla = P * 1.5 : 0;
**		}
**		else if (str[0] == 'x' && str[1])
**			e->plx = (double)ft_atoi(&str[1]);
**		else if (str[0] == 'y' && str[1])
**			e->ply = (double)ft_atoi(&str[1]);
**		ft_printf("%s\n", str);
**		str[0] = '\0';
**	}
**
**	console(e);
*/

/*
**	if (KEY == KEYM && e->mmp.mode != -1)
**			e->mmp.mode++;
**		if (e->mmp.mode == 4)
**			e->mmp.mode = 0;
**	ft_printf("KEY: %d\n", KEY);
*/

int			key_press(int key, t_eng *e)
{
	if (key == 53)
		destroyer();
	if (key == 10)
		e->cnt.mm = e->cnt.mm == 0 ? 1 : 0;
	if (key == 47)
		e->fov += 0.174533;
	if (key == 43)
		e->fov -= 0.174533;
	key == KEYW ? e->cnt.kw = 1 : 0;
	key == KEYA ? e->cnt.ka = 1 : 0;
	key == KEYS ? e->cnt.ks = 1 : 0;
	key == KEYD ? e->cnt.kd = 1 : 0;
	key == KEYR || key == 8 ? e->cnt.kr = 1 : 0;
	key == KEYL || key == 6 ? e->cnt.kl = 1 : 0;
	if (key == KEYF3)
		e->cnt.kf3 = e->cnt.kf3 ? 0 : 1;
	return (0);
}

int			key_release(int key, t_eng *e)
{
	key == KEYW ? e->cnt.kw = 0 : 0;
	key == KEYA ? e->cnt.ka = 0 : 0;
	key == KEYS ? e->cnt.ks = 0 : 0;
	key == KEYD ? e->cnt.kd = 0 : 0;
	key == KEYR || key == 8 ? e->cnt.kr = 0 : 0;
	key == KEYL || key == 6 ? e->cnt.kl = 0 : 0;
	return (0);
}
