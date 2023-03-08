/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:32:24 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/08 16:26:11 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a)
{
	t_list	*curr;
	t_list	*temp;

	if (!*a || cnt_rec(*a) <= 1)
		return ;
	curr = *a;
	temp = *a;
	*a = curr->next;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = temp;
	temp->next = NULL;
	printf("ra\n");
}

void	rb(t_list **b)
{
	t_list	*curr;
	t_list	*temp;

	if (!*b || cnt_rec(*b) <= 1)
		return ;
	curr = *b;
	temp = *b;
	*b = curr->next;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = temp;
	temp->next = NULL;
	printf("rb\n");
}

void	rra(t_list **a)
{
	t_list	*curr;
	t_list	*before_last;

	if (cnt_rec(*a) <= 1)
		return ;
	curr = *a;
	before_last = *a;
	while (curr->next != NULL)
		curr = curr->next;
	while (before_last->next != curr)
		before_last = before_last->next;
	curr->next = *a;
	*a = curr;
	before_last->next = NULL;
	printf("rra\n");
}

void	rrb(t_list **b)
{
	t_list	*curr;
	t_list	*before_last;

	if (cnt_rec(*b) <= 1)
		return ;
	curr = *b;
	before_last = *b;
	while (curr->next != NULL)
		curr = curr->next;
	while (before_last->next != curr)
		before_last = before_last->next;
	curr->next = *b;
	*b = curr;
	before_last->next = NULL;
	printf("rrb\n");
}
