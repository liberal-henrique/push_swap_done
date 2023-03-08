/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:04:57 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/08 18:28:07 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	n_midpoint(t_list **b, int midpoint, int end)
{
	t_list	*temp;
	t_list	*clone;
	int		i;

	clone = clone_list(b);
	temp = clone;
	sort_list(&temp);
	i = 1;
	while (temp->next != NULL && temp->x != midpoint)
		temp = temp->next;
	while (temp->next != NULL && temp->x != end)
	{
		i++;
		temp = temp->next;
	}
	deallocate(&clone, 0);
	return (i);
}

void	rest(t_list **a, t_list **b, int i)
{
	int	n;

	n = 0;
	sort_a(a, b, i);
	n = cnt_rec(*b);
	while (cnt_rec(*b) > 0)
		pa(a, b);
	sort_a(a, b, n);
}

void	send_rest(t_list **a, t_list **b)
{
	t_list	*last;
	int		md_pnt;
	int		small;
	int		big;
	int		i;

	last = *b;
	small = give_small(b);
	big = give_big(b);
	i = 0;
	md_pnt = md_chunk(b, small, big);
	small = n_midpoint(b, md_pnt, big);
	while (small != 0)
	{
		if ((*b)->x >= md_pnt && ++i && small--)
		{
			pa(a, b);
			if (cnt_rec(*a) > 1 && (*a)->x > (*a)->next->x && (*a)->x != big)
				sa(a);
		}
		else if ((*b)->x < md_pnt)
			rb(b);
	}
	rest(a, b, i);
}

void	sort_biggest(t_list **a, t_list **b)
{
	t_list	*temp;

	while (cnt_rec(*a) != 0)
		best_move(a, b, start(a), end(a));
	while (cnt_rec(*b) > 30)
	{
		temp = (*b);
		while (temp->next != NULL)
			temp = temp->next;
		if ((*b)->x > temp->x)
			send_top_b(a, b);
		else if ((*b)->x < temp->x)
			send_bot_b(a, b);
	}
	send_rest(a, b);
}
