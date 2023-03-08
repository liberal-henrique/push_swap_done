/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:56:40 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/08 15:26:39 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	gv_i(t_list **a, int element)
{
	t_list	*temp;
	int		index_a;

	temp = (*a);
	index_a = 0;
	while (temp->next != NULL && element != temp->x)
	{
		index_a++;
		temp = temp->next;
	}
	return (index_a);
}

int	midpoint(t_list **a, int i)
{
	t_list	*temp;
	t_list	*clone;
	int		value;

	clone = clone_list(a);
	temp = clone;
	sort_list(&temp);
	i = i / 2;
	while (i-- != 0 && temp->next != NULL)
		temp = temp->next;
	value = temp->x;
	deallocate(&clone, 0);
	return (value);
}

int	numero_movi(t_list **a, int end)
{
	t_list	*temp;
	t_list	*clone;
	int		i;

	clone = clone_list(a);
	temp = clone;
	sort_list(&temp);
	i = 1;
	while (temp->next != NULL && temp->x != end)
	{
		i++;
		temp = temp->next;
	}
	deallocate(&clone, 0);
	return (i);
}

void	send_pb(t_list **a, t_list **b, int top, int bottom)
{
	if (top <= bottom)
	{
		while (top-- != 0)
			ra(a);
		pb(b, a);
	}
	else if (top > bottom)
	{
		while (bottom-- != 0)
			rra(a);
		pb(b, a);
	}
}

void	best_move(t_list **a, t_list **b, int start, int end)
{
	t_mid	use;
	int		top;
	int		flag;

	use.i = numero_movi(a, end);
	use.md_pnt = midpoint(a, use.i);
	while (*a && use.i-- != 0)
	{
		flag = 0;
		use.temp = (*a);
		while (use.temp->next != NULL)
		{
			if ((use.temp->x >= start && use.temp->x <= end) && flag == 0)
			{
				top = use.temp->x;
				flag = 1;
			}
			if (use.temp->x >= start && use.temp->x <= end)
				use.bottom = use.temp->x;
			use.temp = use.temp->next;
		}
		send_pb(a, b, gv_i(a, top), (cnt_rec(*a) - gv_i(a, use.bottom)));
		if (cnt_rec(*b) > 1 && (*b)->x < use.md_pnt)
			rb(b);
	}
}
