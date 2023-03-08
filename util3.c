/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:26:16 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/08 22:08:10 by lliberal         ###   ########.fr       */
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

int	find_bigg_in_a(t_list **root, int n_moviments)
{
	t_list	*temp;
	int		biggest;

	temp = (*root);
	biggest = temp->x;
	while (--n_moviments > 0)
	{
		if (biggest < temp->next->x)
			biggest = temp->next->x;
		temp = temp->next;
	}
	return (biggest);
}

int	find_smll(t_list **root)
{
	t_list	*temp;
	int		smallest;

	temp = *root;
	smallest = 0;
	while (temp->next != NULL)
	{
		if (temp->x > temp->next->x)
			smallest = temp->next->x;
		temp = temp->next;
	}
	return (smallest);
}
