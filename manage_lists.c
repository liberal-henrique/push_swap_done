/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:30:33 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/13 14:27:02 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cnt_rec(t_list *node)
{
	if (node == NULL)
		return (0);
	return (1 + cnt_rec(node->next));
}

void	insert_end(t_list **root, int value)
{
	t_list	*new_node;
	t_list	*curr;

	curr = *root;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->x = value;
	if (*root == NULL)
	{
		*root = new_node;
		return ;
	}
	curr = *root;
	while (curr->next != NULL)
	{
		if (curr->x == value)
		{
			free(new_node);
			deallocate(root, 1);
		}
		curr = curr->next;
	}
	curr->next = new_node;
}

static int	ft_isspace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

long int	ft_atoi_str(char **str, t_list *a)
{
	long int	res;
	long int	sign;

	res = 0;
	sign = 1;
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign *= -1;
		(*str)++;
	}
	if (!(**str >= '0' && **str <= '9'))
		deallocate(&a, 1);
	while (**str >= '0' && **str <= '9' && **str)
	{
		res = res * 10 + **str - '0';
		(*str)++;
	}
	res *= sign;
	if (res > 2147483647 || res < -2147483648 || \
	(**str && !ft_isspace(**str)))
		deallocate(&a, 1);
	return (res);
}

t_list	*initialize_list(char **argv, t_list *a)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		insert_end(&a, ft_atoi_str(&argv[i], a));
		i += !(*argv[i]);
	}
	return (a);
}
