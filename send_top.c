/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:41:33 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/08 21:47:27 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	top_big(t_list *b)
{
	t_list	*temp;
	t_list	*last;
	int		big;
	int		i;

	temp = b;
	last = b;
	while (last->next != NULL)
		last = last->next;
	big = temp->x;
	i = 0;
	while (temp->x > last->x)
	{
		if (big < temp->x)
			big = temp->x;
		temp = temp->next;
		i++;
	}
	return (big);
}

int	top_small(t_list *b)
{
	t_list	*temp;
	t_list	*last;
	int		small;
	int		i;

	temp = b;
	last = b;
	while (last->next != NULL)
		last = last->next;
	small = temp->x ;
	i = 0;
	while (temp->x > last->x)
	{
		if (small > temp->x)
			small = temp->x;
		i++;
		temp = temp->next;
	}
	return (small);
}

void	part_send_top(t_list **a, t_list **b, t_list *last, int n)
{
	int	i;

	i = 0;
	while ((*b)->x > last->x)
	{
		pa(a, b);
		if (cnt_rec(*a) > 1 && (*a)->x > (*a)->next->x)
			sa(a);
		i++;
	}
	i = i + n;
	while (n-- != 0)
	{
		rrb(b);
		pa(a, b);
		if (cnt_rec(*a) > 1 && (*a)->x > (*a)->next->x)
			sa(a);
	}
	sort_a(a, b, i);
}

void	send_top_b(t_list **a, t_list **b)
{
	t_list	*last;
	int		i;
	int		r;
	int		n;
	int		md_pnt;

	last = *b;
	while (last->next != NULL)
		last = last->next;
	md_pnt = md_chunk(b, top_small(*b), top_big(*b));
	i = 0;
	n = 0;
	r = n_midpoint(b, md_pnt, top_big(*b));
	while (r != 0)
	{
		if ((*b)->x >= md_pnt && ++i && r--)
			pa(a, b);
		else if ((*b)->x < md_pnt && ++n)
			rb(b);
	}
	sort_a(a, b, i);
	part_send_top(a, b, last, n);
}
