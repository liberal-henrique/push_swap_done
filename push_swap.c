/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:55:36 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/08 23:45:57 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	a = initialize_list(argv + 1, a);
	if (!a)
		return (0);
	if (list_sorted(&a) == 1 && count_items(a) >= 1)
		deallocate(&a, 0);
	else if (cnt_rec(a) == 2)
		sa(&a);
	else if (cnt_rec(a) <= 3)
		sort_3(&a);
	else if (cnt_rec(a) == 4)
		sort_4_elements(&a, &b);
	else if (cnt_rec(a) == 5)
		sort_5_elements(&a, &b);
	else
		sort_biggest(&a, &b);
	deallocate(&a, 0);
	return (0);
}
