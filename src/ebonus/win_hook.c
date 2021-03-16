/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:31:08 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/15 22:41:08 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	destroyer(void)
{
	ft_printf("\033[92mGame closed \U0001f918\n");
	exit(0);
}

int		expose(int hook, t_eng *e)
{
	int use;

	use = hook + e->msx;
	return (0);
}

int		destroy_notify(int hook, t_eng *e)
{
	int use;

	use = hook + e->msx;
	destroyer();
	return (0);
}
