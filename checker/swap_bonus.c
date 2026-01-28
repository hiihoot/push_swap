/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-mou <sait-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:47:22 by sait-mou          #+#    #+#             */
/*   Updated: 2026/01/26 14:41:37 by sait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_node *stack)
{
	int	tmp;

	if (!stack || stack->next == stack)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

void	sa(t_node **stack_a, int print)
{
	swap(*stack_a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_node **stack_b, int print)
{
	swap(*stack_b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b, int print)
{
	swap(*stack_a);
	swap(*stack_b);
	if (print)
		write(1, "ss\n", 3);
}
