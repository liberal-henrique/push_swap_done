/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:24:11 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/08 23:38:22 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *a)
{
	size_t	i;

	i = 0;
	while (a[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	length;
	char	*dest;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = -1;
	j = -1;
	length = (ft_strlen(s1) + ft_strlen(s2));
	dest = malloc(sizeof(char) * length + 1);
	if (!dest)
		return (NULL);
	while (s1[++i] != '\0')
		dest[i] = s1[i];
	while (s2[++j] != '\0')
		dest[i++] = s2[j];
	dest[i] = '\0';
	return (dest);
}

int	ft_atoi(const char *str)
{
	long	res;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

int	gv_i_mid(t_list **a)
{
	int		mid;
	int		size;

	mid = 0;
	size = cnt_rec(*a);
	if (size % 2 != 0)
		mid = (size / 2) + 1;
	else
		mid = (size / 2);
	return (mid);
}

t_list	*clone_list(t_list **head)
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*prev;
	t_list	*current;

	prev = NULL;
	new_list = NULL;
	current = *head;
	while (current != NULL)
	{
		new_node = malloc(sizeof(t_list));
		if (!new_node)
			return (NULL);
		new_node->x = current->x;
		new_node->next = NULL;
		if (prev != NULL)
			prev->next = new_node;
		else
			new_list = new_node;
		prev = new_node;
		current = current->next;
	}
	return (new_list);
}
