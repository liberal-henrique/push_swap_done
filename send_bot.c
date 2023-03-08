/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_bot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:38:04 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/08 15:40:56 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_last(t_list **b)
{
	t_list	*temp;
	t_list	*last;
	int		iterate;
	int		n;

	temp = (*b);
	last = (*b);
	iterate = 0;
	n = 0;
	while (last->next != NULL)
	{
		last = last->next;
		iterate++;
		if (last->x > (*b)->x)
			n++;
		else
			n = 0;
	}
	while (temp->next != NULL && iterate-- >= n)
		temp = temp->next;
	return (temp);
}

int	bot_small(t_list *b)
{
	t_list	*temp;
	int		small;

	temp = b;
	small = temp->x;
	while (temp->next != NULL)
	{
		if (small > temp->x)
			small = temp->x;
		temp = temp->next;
	}
	return (small);
}

int	bot_big(t_list *b)
{
	t_list	*temp;
	int		big;

	temp = b;
	big = temp->x;
	while (temp->next != NULL)
	{
		if (big < temp->x)
			big = temp->x;
		temp = temp->next;
	}
	return (big);
}

void	sort_back(t_list **a, t_list **b, int i, int n)
{
	sort_a(a, b, i);
	i = n;
	while (n-- != 0)
		pa(a, b);
	sort_a(a, b, i);
}

void	send_bot_b(t_list **a, t_list **b)
{
	t_mid	usable;

	usable.temp = *b;
	usable.last = find_last(b);
	usable.md_pnt = md_chunk(b, bot_small(usable.last), bot_big(usable.last));
	usable.n = 0;
	usable.i = 0;
	while (usable.temp->x != usable.last->x)
	{
		usable.temp = *b;
		while (usable.temp->next != NULL)
			usable.temp = usable.temp->next;
		rrb(b);
		if ((*b)->x >= usable.md_pnt && ++usable.i)
			pa(a, b);
		else
			usable.n++;
	}
	sort_back(a, b, usable.i, usable.n);
}
