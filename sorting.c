/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:32:10 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/31 17:08:50 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stk_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ft_find_ind_of_max_value(t_list *lst)
{
	int	max_value;
	int	max_ind;
	int	i;

	max_ind = 0;
	max_value = lst->value;
	lst = lst->next;
	i = 1;
	while (lst)
	{
		if (lst->value > max_value)
		{	
			max_ind = i;
			max_value = lst->value;
		}
		lst = lst->next;
		i++;
	}
	return (max_ind);
}

void	small_sort_stack(t_list **stack)
{
	int	max_index;

	max_index = 0;
	if (ft_lstsize(*stack) == 2 && (*stack)->value > (*stack)->next->value)
		swap_stk(stack, 'a');
	else
	{
		max_index = ft_find_ind_of_max_value(*stack);
		if (max_index == 0)
			rotate_stk(stack, 'a');
		else if (max_index == 1)
			rev_rotate_stk(stack, 'a');
		if ((*stack)->value > (*stack)->next->value)
			swap_stk(stack, 'a');
	}
}

void	stack_sorting(t_list **a, t_list **b)
{
	int	lst_len;
	int	med_len;
	int	med_value;

	if (stk_sorted(*a) == 0)
		exit (EXIT_SUCCESS);
	lst_len = ft_lstsize(*a);
	med_len = lst_len / 2;
	med_value = (ft_lstfindmax_val(*a) + \
	ft_lstfindmin_val(*a)) / 2;
	while (lst_len > 3)
	{
		if (med_value < (*a)->value && lst_len > med_len && med_len > 100)
			rotate_stk(a, 'a');
		else
		{
			push_on_stk(b, a, 'b');
			lst_len--;
		}
	}
	small_sort_stack(a);
	lets_sort(a, b);
}
