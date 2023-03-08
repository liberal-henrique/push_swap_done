/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:56:46 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/08 16:03:32 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	back_ra(t_list **a, int n_control)
{
	int	i;

	i = n_control;
	if (list_sorted(a))
		return ;
	while (n_control-- != 0 && !list_sorted(a))
		rra(a);
	if (i == 2 && !list_sorted(a))
		sa(a);
}

void	back_pb(t_list **a, t_list **b, int n_control)
{
	int	i;

	while (n_control-- != 0)
	{
		i = (*b)->x;
		if (i > (*a)->x)
		{
			pa(a, b);
			sa(a);
		}
		else
			pa(a, b);
	}
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

void	sort_a(t_list **a, t_list **b, int n_moviments)
{
	int	mid_pnt;
	int	ra_control;
	int	pb_control;

	ra_control = 0;
	pb_control = 0;
	if (list_sorted(a))
		return ;
	mid_pnt = md_chunk(a, find_smll(a), find_bigg_in_a(a, n_moviments));
	while (n_moviments-- > 0)
	{
		if ((*a)->x >= mid_pnt && !list_sorted(a) && ++ra_control)
			ra(a);
		else if ((*a)->x < mid_pnt && ++pb_control)
			pb(b, a);
	}
	back_ra(a, ra_control);
	if (!(list_sorted(a)))
		sort_a(a, b, ra_control);
	back_pb(a, b, pb_control);
	if (!(list_sorted(a)))
		sort_a(a, b, pb_control);
}
