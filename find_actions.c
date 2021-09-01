/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:22:37 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/31 17:19:45 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	values_overwriting(t_act *min_act, t_act *lst_act)
{
	min_act->ra = lst_act->ra;
	min_act->rb = lst_act->rb;
	min_act->rra = lst_act->rra;
	min_act->rrb = lst_act->rrb;
	min_act->total = lst_act->total;
	min_act->mode = lst_act->mode;
}

int	find_best_place_in_a(t_list *a, t_list *b)
{
	int	best_value;
	int	best_ind;
	int	it;

	best_value = a->value;
	best_ind = 0;
	it = 1;
	a = a->next;
	while (a)
	{
		if ((best_value > a->value && best_value < b->value) \
		|| (a->value > b->value && (best_value < b->value \
		|| best_value > a->value)))
		{
			best_ind = it;
			best_value = a->value;
		}
		a = a->next;
		it++;
	}
	return (best_ind);
}

void	find_best_mode(t_act *cur_act)
{
	cur_act->total = INT_MAX;
	if (cur_act->total > ft_find_max(cur_act->ra, cur_act->rb))
	{
		cur_act->total = ft_find_max(cur_act->ra, cur_act->rb);
		cur_act->mode = 1;
	}
	if (cur_act->total > ft_find_max(cur_act->rra, cur_act->rrb))
	{
		cur_act->total = ft_find_max(cur_act->rra, cur_act->rrb);
		cur_act->mode = 2;
	}
	if (cur_act->total > cur_act->ra + cur_act->rrb)
	{
		cur_act->total = cur_act->rra + cur_act->rrb;
		cur_act->mode = 3;
	}
	if (cur_act->total > cur_act->rra + cur_act->rb)
	{
		cur_act->total = cur_act->rra + cur_act->rb;
		cur_act->mode = 4;
	}
}

void	find_best_action(t_list **a, t_list **b, t_act *min_act)
{
	int		index;
	t_list	*tmp;
	t_act	cur_act;

	index = 0;
	tmp = *b;
	min_act->total = INT_MAX;
	while (tmp)
	{
		cur_act.ra = find_best_place_in_a(*a, tmp);
		cur_act.rb = index;
		cur_act.rra = ft_lstsize(*a) - cur_act.ra;
		cur_act.rrb = ft_lstsize(*b) - cur_act.rb;
		find_best_mode(&cur_act);
		if (cur_act.total < min_act->total)
			values_overwriting(min_act, &cur_act);
		index++;
		tmp = tmp->next;
	}
}
