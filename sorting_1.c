/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:27:57 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/31 16:58:38 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lets_sort_any_stk(t_list **stk, char stk_name)
{
	int	max_index;
	int	half_size;

	max_index = ft_find_ind_of_max_value(*stk);
	half_size = ft_lstsize(*stk) / 2;
	if (max_index > half_size)
	{
		while (stk_sorted(*stk) != 0)
			rev_rotate_stk(stk, stk_name);
	}
	else
	{
		while (stk_sorted(*stk) != 0)
			rotate_stk(stk, stk_name);
	}
}

void	lets_sort(t_list **a, t_list **b)
{
	t_act	*min_act;

	min_act = (t_act *)malloc(sizeof(t_act));
	while (*b)
	{
		find_best_action(a, b, min_act);
		if (min_act->mode == 1)
			rr_mode(a, b, *min_act);
		if (min_act->mode == 2)
			rrr_mode(a, b, *min_act);
		if (min_act->mode == 3)
			ra_and_rrb_mode(a, b, *min_act);
		if (min_act->mode == 4)
			rb_and_rra_mode(a, b, *min_act);
		push_on_stk(a, b, 'a');
	}
	free(min_act);
	lets_sort_any_stk(a, 'a');
}
