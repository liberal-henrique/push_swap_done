/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:07:28 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/08 17:47:55 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **a)
{
	t_list	*tmp;
	int		topo;

	tmp = *a;
	topo = (*a)->x;
	while (tmp->next)
		tmp = tmp->next;
	if (topo > (*a)->next->x && topo > tmp->x && (*a)->next->x < tmp->x)
		ra(a);
	else if (topo > (*a)->next->x && topo > tmp->x && (*a)->next->x > tmp->x)
	{
		sa(a);
		rra(a);
	}
	else if (topo > (*a)->next->x && topo < tmp->x)
		sa(a);
	else if (topo < (*a)->next->x && topo > tmp->x)
		rra(a);
	else if (topo < (*a)->next->x && topo < tmp->x)
	{
		sa(a);
		ra(a);
	}
	return ;
}

int	ft_pultimo(t_list **a)
{
	t_list	*list_temp;
	t_list	*clone;
	int		pultimo;

	clone = clone_list(a);
	list_temp = clone;
	sort_list(&list_temp);
	pultimo = list_temp->next->next->next->x;
	deallocate(&clone, 0);
	return (pultimo);
}

int	ft_meio(t_list **a)
{
	t_list	*list_temp;
	t_list	*clone;
	int		meio;

	clone = clone_list(a);
	list_temp = clone;
	sort_list(&list_temp);
	meio = list_temp->next->next->x;
	deallocate(&clone, 0);
	return (meio);
}

void	send_desire(t_list **a, t_list **b, int meio, int pnultimo)
{
	if ((*a)->x == meio || (*a)->x == pnultimo)
		ra(a);
	else
		pb(b, a);
}

void	sort_5_elements(t_list **a, t_list **b)
{
	int	meio;
	int	pnultimo;

	meio = ft_meio(a);
	pnultimo = ft_pultimo(a);
	while (cnt_rec(*a) != 3)
		send_desire(a, b, meio, pnultimo);
	if (!list_sorted(a))
		sort_3(a);
	if ((*b)->x < (*b)->next->x)
		sb(b);
	pa(a, b);
	if (!(list_sorted(a)))
		ra(a);
	pa(a, b);
	if (!(list_sorted(a)))
		sa(a);
}
