/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:32:07 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/08 16:36:37 by lliberal         ###   ########.fr       */
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

void	free_all(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free (result);
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

int	ft_isnum_compare(const char *str, t_list *a)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if ((str[i] > '9' || str[i] < '0'))
			deallocate(&a, 1);
	}
	if (ft_strncmp("-2147483648", str, 11) == 1)
		return (1);
	return (0);
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
