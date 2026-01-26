/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-mou <sait-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 20:53:23 by sait-mou          #+#    #+#             */
/*   Updated: 2026/01/26 20:53:27 by sait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	butterfly_sort(t_node **stack_a, t_node **stack_b, int range)
{
	int	i;

	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			rb(stack_b, 1);
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a, 1);
	}
}

t_node	*find_max(t_node *stack)
{
	t_node	*max_node;
	t_node	*curr;

	if (!stack)
		return (NULL);
	max_node = stack;
	curr = stack->next;
	while (curr != stack)
	{
		if (curr->index > max_node->index)
			max_node = curr;
		curr = curr->next;
	}
	return (max_node);
}

void	push_back_to_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*max;
	int		len;
	int		pos;

	while (*stack_b)
	{
		max = find_max(*stack_b);
		len = stack_len(*stack_b);
		pos = get_pos(*stack_b, max);
		if (pos <= len / 2)
		{
			while (*stack_b != max)
				rb(stack_b, 1);
		}
		else
		{
			while (*stack_b != max)
				rrb(stack_b, 1);
		}
		pa(stack_a, stack_b);
	}
}
