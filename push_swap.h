/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:25:31 by taredfor          #+#    #+#             */
/*   Updated: 2021/09/01 10:40:17 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include "limits.h" 
# include "libft/libft.h"

typedef struct s_actions
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	mode;
	int	total;
}	t_act;

int		main(int argc, char **argv);
void	ft_parsing(t_list **a, char **argv, int len);
void	ft_checker(char *str);
void	push_swap(int argc, char **argv);

int		stk_sorted(t_list *stack);
void	small_sort_stack(t_list **stack);
void	stack_sorting(t_list **a, t_list **b);
void	swap_stk(t_list **stack, char stack_name);
void	rotate_stk(t_list **stack, char stk_name);
void	rev_rotate_stk(t_list **stack, char stk_name);
void	push_on_stk(t_list **to, t_list **from, char stk_name);

//sorting
void	lets_sort_any_stk(t_list **stk, char stk_name);
void	lets_sort(t_list **a, t_list **b);
//double

void	double_swap_stk(t_list **a, t_list **b);
void	double_rotate_stk(t_list **a, t_list **b);
void	double_rev_rotate_stk(t_list **a, t_list **b);
//find_action
void	values_overwriting(t_act *min_act, t_act *lst_act);
int		find_best_place_in_a(t_list *a, t_list *b);
void	find_best_mode(t_act *cur_act);
void	find_best_action(t_list **a, t_list **b, t_act *min_act);

void	rr_mode(t_list **a, t_list **b, t_act min_quan_act);
void	rrr_mode(t_list **a, t_list **b, t_act min_quan_act);
void	ra_and_rrb_mode(t_list **a, t_list **b, t_act min_quan_act);
void	rb_and_rra_mode(t_list **a, t_list **b, t_act min_quan_act);

void	find_best_mode(t_act *cur_act);
void	find_best_action(t_list **a, t_list **b, t_act *min_act);
int		find_best_place_in_a(t_list *a, t_list *b);
void	overwriting_values(t_act *min_quan_act, t_act *cur_act);

#endif
