/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 13:59:42 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/14 10:37:38 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

t_spr	*ft_newsprite(double x, double y)
{
	t_spr *ptr;

	if (!(ptr = malloc(sizeof(t_spr))))
		return (NULL);
	ptr->x = x;
	ptr->y = y;
	ptr->next = NULL;
	return (ptr);
}

t_spr	*ft_lstlast(t_spr *spr)
{
	if (!spr)
		return (NULL);
	while (spr->next != NULL)
		spr = spr->next;
	return (spr);
}

void	ft_lstadd_back(t_spr **lst, t_spr *new)
{
	t_spr *elem;

	if (*lst)
	{
		elem = ft_lstlast(*lst);
		elem->next = new;
	}
	else
		*lst = new;
}

void	ft_lstclear(t_spr **lst)
{
	t_spr *pointer;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		pointer = (*lst)->next;
		free(*lst);
		*lst = pointer;
	}
}
