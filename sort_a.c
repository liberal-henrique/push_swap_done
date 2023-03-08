/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:56:46 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/08 23:49:29 by lliberal         ###   ########.fr       */
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
		if (i > (*a)->x && cnt_rec(*a) > 0)
		{
			pa(a, b);
			sa(a);
		}
		else
			pa(a, b);
	}
}

void	part_sort_a(t_list **a, t_list **b, int ra_control, int pb_control)
{
	back_ra(a, ra_control);
	if (!(list_sorted(a)))
		sort_a(a, b, ra_control);
	back_pb(a, b, pb_control);
	if (!(list_sorted(a)))
		sort_a(a, b, pb_control);
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
		if ((*a)->x >= mid_pnt && !list_sorted(a))
		{
			ra(a);
			ra_control++;
			if (list_sorted(a))
				ra_control--;
		}
		else if ((*a)->x < mid_pnt)
		{
			pb(b, a);
			pb_control++;
		}
	}
	part_sort_a(a, b, ra_control, pb_control);
}
