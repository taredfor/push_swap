/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:44:07 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/31 16:19:15 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_mode(t_list **a, t_list **b, t_act min_act)
{
	while (min_act.ra && min_act.rb)
	{
		double_rotate_stk(a, b);
		min_act.ra--;
		min_act.rb--;
	}
	while (min_act.ra)
	{
		rotate_stk(a, 'a');
		min_act.ra--;
	}
	while (min_act.rb)
	{
		rotate_stk(b, 'b');
		min_act.rb--;
	}
}

void	rrr_mode(t_list **a, t_list **b, t_act min_act)
{
	while (min_act.rra && min_act.rrb)
	{
		double_rev_rotate_stk(a, b);
		min_act.rra--;
		min_act.rrb--;
	}
	while (min_act.rra)
	{
		rev_rotate_stk(a, 'a');
		min_act.rra--;
	}
	while (min_act.rrb)
	{
		rev_rotate_stk(b, 'b');
		min_act.rrb--;
	}
}

void	ra_and_rrb_mode(t_list **a, t_list **b, t_act min_act)
{
	while (min_act.ra)
	{
		rotate_stk(a, 'a');
		min_act.ra--;
	}
	while (min_act.rb)
	{
		rotate_stk(b, 'b');
		min_act.rrb--;
	}
}

void	rb_and_rra_mode(t_list **a, t_list **b, t_act min_act)
{
	while (min_act.rb)
	{
		rotate_stk(b, 'b');
		min_act.rb--;
	}
	while (min_act.rra)
	{
		rev_rotate_stk(a, 'a');
		min_act.rra--;
	}
}
