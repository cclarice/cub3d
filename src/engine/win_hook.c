/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:31:08 by cclarice          #+#    #+#             */
/*   Updated: 2021/02/16 22:57:01 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	destroyer()
{
	exit(0);
}

int		expose(int hook, t_eng *e)
{
	return (0);
}

int		destroy_notify(int hook, t_eng *e)
{
	return (0);
}