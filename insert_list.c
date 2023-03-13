/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:36:29 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/13 14:10:09 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_sorted(t_list **root)
{
	t_list	*curr;

	if (!root)
		return (0);
	curr = *root;
	while (curr->next)
	{
		if (curr->x > curr->next->x)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
	printf("rr\n");
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
	printf("rrr\n");
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
	printf("ss\n");
}

void	sort_4_elements(t_list **a, t_list **b)
{
	if (small_i(a) == 0 || big_i(a) == 0)
		pb(b, a);
	else if (small_i(a) == 1 || big_i(a) == 1)
	{
		sa(a);
		if (list_sorted(a))
			return ;
		pb(b, a);
	}
	else if (small_i(a) == 3 || big_i(a) == 3)
	{
		rra(a);
		if (list_sorted(a))
			return ;
		pb(b, a);
	}
	sort_3(a);
	pa(a, b);
	if (!(list_sorted(a)))
		ra(a);
}
