/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:31:15 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/08 16:25:55 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{
	t_list	*second;

	if (!*a || cnt_rec(*a) <= 1)
		return ;
	second = (*a)->next;
	(*a)->next = second->next;
	second->next = *a;
	*a = second;
	printf("sa\n");
}

void	sb(t_list **b)
{
	t_list	*second;

	if (!*b || cnt_rec(*b) <= 1)
		return ;
	second = (*b)->next;
	(*b)->next = second->next;
	second->next = *b;
	*b = second;
	printf("sb\n");
}

void	pa(t_list **a, t_list **b)
{
	t_list	*curr;

	if (!*b)
		return ;
	curr = *b;
	*b = curr->next;
	curr->next = *a;
	*a = curr;
	printf("pa\n");
}

void	pb(t_list **b, t_list **a)
{
	t_list	*curr;

	if (!*a)
		return ;
	curr = *a;
	*a = curr->next;
	curr->next = *b;
	*b = curr;
	printf("pb\n");
}
