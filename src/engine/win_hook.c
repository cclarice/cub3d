/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:31:08 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/14 10:31:17 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	destroyer(void)
{
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
	return (0);
}
