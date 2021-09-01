/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:48:44 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/30 18:48:45 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	double_swap_stk(t_list **a, t_list **b)
{
	swap_stk(a);
	swap_stk(b);
}

void	double_rotate_stk(t_list **a, t_list **b)
{
	rotate_stk(a);
	rotate_stk(b);
}

void	double_rev_rotate_stk(t_list **a, t_list **b)
{
	rev_rotate_stk(a);
	rev_rotate_stk(b);
}
