/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:30:33 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/11 18:22:39 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printList(t_list *root)
{
	t_list	*curr;

	curr = root;
	while (curr != NULL)
	{
		if (curr->next == NULL)
		{
			printf("[*][%ld]", (long int)curr->x);
			break ;
		}
		printf("[*][%ld]->", (long int)curr->x);
		curr = curr->next;
	}
}

int	ft_isnum_compare(const char *str)
{
	int	i;
	int	flag;

	i = -1;
	flag = 1;
	while (str[++i])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (!(str[i] <= '9' && str[i] >= '0'))
			flag = 0;
	}
	// if (ft_strncmp("-2147483648", str, 11) != 1)
	// 	flag = 0;
	return (flag);
}

long int	ft_atoi_check_numbers(const char *str, t_list *a)
{
	int			i;
	int			sign;
	int			flag;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	flag = ft_isnum_compare(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if ((res >= 2147483648 && sign == -1) || flag != 1)
	{
		deallocate(&a, 1);
		exit (1);
	}
	return (res * sign);
}

t_list	*initialize_list(char **argv, t_list *a)
{
	int		i;
	int		j;
	int		flag;
	int		value;
	t_list	*new_node;

	i = -1;
	value = 0;
	new_node = NULL;
	(void)a;
	while (argv[++i])
	{
		j = 0;
		flag = 0;
		while (argv[i][j++])
		{
			if ((argv[i][j] >= 9 && argv[i][j] <= 13) || argv[i][j] == 32)
			{
				flag = 1;
				new_node = ft_split_create_str(new_node, argv[i], argv[i][j]);
				break ;
			}
		}
		if (flag == 0)
		{
			value =  ft_atoi_check_numbers(argv[i], new_node);
			insert_end(&new_node, value);
		}
	}
	return (new_node);
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

int	list_sorted(t_list **root)
{
	t_list	*curr;

	if (!root)
		return (0);
	curr = *root;
	while (curr->next)
	{
		if (curr->x > curr->next->x)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	cnt_rec(t_list *node)
{
	if (node == NULL)
		return (0);
	return (1 + cnt_rec(node->next));
}
