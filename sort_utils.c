/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:09:50 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/08 22:58:25 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	i_last(t_list **root, int finish)
{
	t_list	*temp;
	int		index;

	temp = *root;
	index = 0;
	while (temp->next != NULL)
	{
		if (temp->x == finish)
			break ;
		index++;
		temp = temp->next;
	}
	return (index);
}

int	i_first(t_list **root, int start)
{
	t_list	*temp;
	int		index;

	temp = *root;
	index = 0;
	while (temp->next != NULL)
	{
		if (temp->x == start)
			break ;
		index++;
		temp = temp->next;
	}
	return (index);
}

int	md_chunk(t_list **root, int start, int finish)
{
	t_list	*temp;
	t_list	*clone;
	int		mid;
	int		result;

	clone = clone_list(root);
	temp = clone;
	sort_list(&temp);
	mid = (i_last(&temp, finish) - i_first(&temp, start)) / 2;
	while (temp->next != NULL)
	{
		if (temp->x == start)
			break ;
		temp = temp->next;
	}
	while (mid-- != 0)
		temp = temp->next;
	result = temp->x;
	deallocate(&clone, 0);
	return (result);
}
