/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:23:06 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/08 16:25:06 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	start(t_list **a)
{
	t_list	*temp;
	t_list	*clone;
	int		start;

	clone = clone_list(a);
	temp = clone;
	sort_list(&temp);
	start = temp->x;
	deallocate(&clone, 0);
	return (start);
}

int	end(t_list **a)
{
	t_list	*temp;
	t_list	*clone;
	int		end;

	clone = clone_list(a);
	temp = clone;
	sort_list(&temp);
	end = 0;
	while (temp->next != NULL && end != 29)
	{
		end++;
		temp = temp->next;
	}
	end = temp->x;
	deallocate(&clone, 0);
	return (end);
}

int	small_i(t_list **a)
{
	t_list	*temp;
	int		temp_menor;
	int		index_smallest;

	temp = (*a);
	index_smallest = 0;
	temp_menor = (*a)->x;
	while (temp)
	{
		if (temp_menor > temp->x)
			temp_menor = temp->x;
		temp = temp->next;
	}
	temp = (*a);
	while (temp != NULL)
	{
		if (temp->x == temp_menor)
			break ;
		temp = temp->next;
		index_smallest++;
	}
	return (index_smallest);
}

int	big_i(t_list **a)
{
	t_list	*temp;
	int		temp_maior;
	int		index_biggest;

	temp = (*a);
	index_biggest = 0;
	temp_maior = (*a)->x;
	while (temp)
	{
		if (temp_maior < temp->x)
			temp_maior = temp->x;
		temp = temp->next;
	}
	temp = (*a);
	while (temp != NULL)
	{
		if (temp->x == temp_maior)
			break ;
		temp = temp->next;
		index_biggest++;
	}
	return (index_biggest);
}

int	give_value_mid(t_list **a)
{
	t_list	*temp;
	t_list	*clone;
	int		mid_value;
	int		index_mid;

	mid_value = 0;
	clone = clone_list(a);
	temp = clone;
	index_mid = gv_i_mid(a);
	sort_list(&temp);
	while (index_mid >= 0 && temp != NULL)
	{
		if (index_mid == 0)
			mid_value = temp->x;
		index_mid--;
		temp = temp->next;
	}
	deallocate(&clone, 0);
	return (mid_value);
}
