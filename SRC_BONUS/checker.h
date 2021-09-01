/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 12:08:30 by taredfor          #+#    #+#             */
/*   Updated: 2021/09/01 10:35:57 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include "limits.h"
# include <stdarg.h>
# include "../libft/libft.h"

int		main(int argc, char **argv);
void	ft_parsing(t_list **A, char **argv, int len);
void	checker(int argc, char **argv);
void	duplicate_checker(t_list *stack);
int		stk_sorted(t_list *stack);
void	execute_command(t_list **A, t_list **B, char *line);

void	swap_stk(t_list **stack);
void	rotate_stk(t_list **stack);
void	rev_rotate_stk(t_list **stack);
void	push_on_stk(t_list **to, t_list **from);

void	double_swap_stk(t_list **a, t_list **b);
void	double_rotate_stk(t_list **a, t_list **b);
void	double_rev_rotate_stk(t_list **a, t_list **b);

#endif
