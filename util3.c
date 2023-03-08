/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:26:16 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/08 18:27:14 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	give_big(t_list **b)
{
	t_list	*last;
	int		big;

	last = (*b);
	while (last->next != NULL)
	{
		if (big < last->x)
			big = last->x;
		last = last->next;
	}
	return (big);
}

int	give_small(t_list **b)
{
	t_list	*last;
	int		small;

	last = (*b);
	while (last->next != NULL)
	{
		if (small > last->x)
			small = last->x;
		last = last->next;
	}
	return (small);
}
