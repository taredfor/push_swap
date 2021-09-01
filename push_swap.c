/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:21:02 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/31 15:41:03 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	duplicate_checker(t_list *stk)
{
	t_list	*tmp;

	while (stk)
	{
		tmp = stk->next;
		while (tmp)
		{
			if (tmp->value == stk->value)
				ft_error("Error: double");
			tmp = tmp->next;
		}
		stk = stk->next;
	}
}

void	ft_parsing(t_list **a, char **argv, int len)
{
	int		i;
	int		num;
	int		it;
	char	**str;

	i = 1;
	while (i <= len)
	{
		it = 0;
		str = ft_split(argv[i], ' ');
		if (!str)
			ft_error("Error: not ");
		while (str[it])
		{
			num = ft_atoi_for_number(str[it]);
			ft_lstadd_back(a, ft_lstnew(num));
			free(str[it]);
			it++;
		}
		i++;
		free(str);
	}
}

void	push_swap(int argc, char **argv)
{
	int		len;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		ft_prompt("not enought argumnets");
	len = argc - 1;
	ft_parsing(&a, argv, len);
	duplicate_checker(a);
	stack_sorting(&a, &b);
}
