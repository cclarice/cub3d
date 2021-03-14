/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 13:59:03 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/14 10:37:18 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

/*
**	Struct Sprites
*/

# include <stdlib.h>

typedef struct		s_spr
{
	struct s_spr	*next;
	double			x;
	double			y;
	double			len;
}					t_spr;

t_spr				*ft_newsprite(double x, double y);
void				ft_lstadd_back(t_spr **lst, t_spr *new);

#endif
