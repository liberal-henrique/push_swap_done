/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:10:04 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/08 22:09:35 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int				x;
	struct s_list	*next;
}					t_list;

typedef struct s_mid
{
	t_list			*temp;
	t_list			*last;
	int				n;
	int				i;
	int				md_pnt;
	int				bottom;
}					t_mid;

//--------------Initialize-----------------------//
//create_stack

int					gv_i(t_list **a, int element);
int					midpoint(t_list **a, int i);
int					numero_movi(t_list **a, int end);
void				send_pb(t_list **a, t_list **b, int top, int bottom);
void				best_move(t_list **a, t_list **b, int start, int end);
//initialize_list
int					count_items(t_list	*root);
void				free_all(char **result);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isnum_compare(const char *str, t_list *a);
void				deallocate(t_list **root, int message);
//Insert_list
void				insert_end(t_list **root, int value);
void				sort_4_elements(t_list **a, t_list **b);
//manage_list
long int			ft_atoi_check_numbers(const char *str, t_list *a);
void				sort_list(t_list **a);
int					list_sorted(t_list **root);
int					cnt_rec(t_list *node);
t_list				*initialize_list(char **argv, t_list *a);

//----------------Moviments---------------//
//swap
void				sa(t_list **a);
void				sb(t_list **b);
void				ss(t_list **a, t_list **b);
void				pa(t_list **a, t_list **b);
void				pb(t_list **b, t_list **a);
//Rotate
void				ra(t_list **a);
void				rb(t_list **b);
void				rr(t_list **a, t_list **b);
void				rra(t_list **a);
void				rrb(t_list **b);
void				rrr(t_list **a, t_list **b);

//--------moviments in Stacks---------------//
//Send_top
int					top_big(t_list *b);
int					top_small(t_list *b);
void				send_top_b(t_list **a, t_list **b);

//Send_bot
t_list				*find_last(t_list **b);
int					bot_small(t_list *b);
int					bot_big(t_list *b);
void				sort_back(t_list **a, t_list **b, int i, int n);
void				send_bot_b(t_list **a, t_list **b);

//------------------Sort------------------//
//Sort_big
int					n_midpoint(t_list **b, int midpoint, int end);
void				send_rest(t_list **a, t_list **b);
void				sort_biggest(t_list **a, t_list **b);

//Sort_utils
int					i_last(t_list **root, int finish);
int					i_first(t_list **root, int start);
int					md_chunk(t_list **root, int start, int finish);

//sort_small
void				sort_3(t_list **a);
int					ft_pultimo(t_list **a);
int					ft_meio(t_list **a);
void				sort_5_elements(t_list **a, t_list **b);
void				send_desire(t_list **a, t_list **b, int meio, int pnultimo);
//sort_a
void				back_ra(t_list **a, int n_control);
void				back_pb(t_list **a, t_list **b, int n_control);
int					find_bigg_in_a(t_list **root, int n_moviments);
int					find_smll(t_list **root);
void				sort_a(t_list **a, t_list **b, int n_moviments);

//-------Split-------//
char				write_word(char *dest, const char *from, char set);
int					word_count(const char *sr, char del);
void				add_split(char **dst, const char *string, char delimiter);
char				**ft_split(char const *s, char c);
t_list				*ft_split_create_str(t_list *a, char *argv, char delimiter);

//---------------util-----------------//
int					start(t_list **a);
int					end(t_list **a);
int					small_i(t_list **a);
int					big_i(t_list **a);
int					give_value_mid(t_list **a);

//-----------------util2--------------//
size_t				ft_strlen(const char *a);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_atoi(const char *str);
int					gv_i_mid(t_list **a);
t_list				*clone_list(t_list **head);
//-----------------util3--------------//
int					give_big(t_list **b);
int					give_small(t_list **b);
int					find_bigg_in_a(t_list **root, int n_moviments);
int					find_smll(t_list **root);

#endif
