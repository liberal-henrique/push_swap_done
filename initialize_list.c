/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:32:07 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/13 14:12:14 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_items(t_list	*root)
{
	t_list	*curr;
	int		i;

	i = 0;
	curr = root;
	while (curr != NULL)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if ((unsigned char )s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if ((unsigned char )s1[i] == '\0')
			break ;
		i++;
	}
	return (1);
}

int	ft_isnum_compare(const char *str)
{
	int	i;
	int flag;

	i = -1;
	flag = 1;
	while (str[++i])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if ((str[i] > '9' || str[i] < '0'))
			flag = 0;
	}
	return (flag);
}

void	deallocate(t_list **root, int message)
{
	t_list	*temp;

	while (*root)
	{
		temp = (*root)->next;
		free(*root);
		*root = temp;
	}
	if (message == 1)
		exit (write(1, "Error\n", 6));
}

void	sort_list(t_list **a)
{
	t_list	*current;
	t_list	*index;
	int		temp;

	temp = 0;
	index = NULL;
	current = *a;
	if (!*a)
		return ;
	while (current != NULL)
	{
		index = current->next;
		while (index != NULL)
		{
			if (current->x > index->x)
			{
				temp = current->x;
				current->x = index->x;
				index->x = temp;
			}
			index = index->next;
		}
		current = current->next;
	}
}
