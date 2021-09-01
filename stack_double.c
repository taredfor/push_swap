/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:43:52 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/30 18:31:55 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_swap_stk(t_list **a, t_list **b)
{
	swap_stk(a, 'n');
	swap_stk(b, 'n');
	ft_putendl_fd("ss", 1);
}

void	double_rotate_stk(t_list **a, t_list **b)
{
	rotate_stk(a, 'n');
	rotate_stk(b, 'n');
	ft_putendl_fd("rr", 1);
}

void	double_rev_rotate_stk(t_list **a, t_list **b)
{
	rev_rotate_stk(a, 'n');
	rev_rotate_stk(b, 'n');
	ft_putendl_fd("rrr", 1);
}
