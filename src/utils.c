/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-mou <sait-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:55:23 by sait-mou          #+#    #+#             */
/*   Updated: 2026/01/25 17:55:25 by sait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_node *stack)
{
    t_node *tmp;

    if (!stack)
        return (1);

    tmp = stack;
    while(tmp->next != stack)
    { 
        if (tmp->value > tmp->next->value)
            return 0;
        tmp = tmp->next;
    }

    return 1;
}

int stack_len(t_node *stack)
{
    int i;
    t_node *node;

    i = 0;
    node = stack;
    while (1)
    {
        i++;
        node = node->next;
        if (node == stack)
            break;
    }
    return (i);
}

void sort_three(t_node **stack_a)
{
    int a = (*stack_a)->value;
    int b = (*stack_a)->next->value;
    int c = (*stack_a)->next->next->value;

    if (a > b && b < c && a < c)         // Case: 2 1 3
        sa(stack_a, 1);
    else if (a > b && b > c)             // Case: 3 2 1
    {
        sa(stack_a, 1);
        rra(stack_a, 1);
    }
    else if (a > b && b < c && a > c)    // Case: 3 1 2
        ra(stack_a, 1);
    else if (a < b && b > c && a < c)    // Case: 1 3 2
    {
        sa(stack_a, 1);
        ra(stack_a, 1);
    }
    else if (a < b && b > c && a > c)    // Case: 2 3 1
        rra(stack_a, 1);
}

t_node	*find_min(t_node *stack)
{
	t_node	*min_node;
	t_node	*curr;

	if (!stack)
		return (NULL);
	min_node = stack;
	curr = stack->next;
	while (curr != stack)
	{
		if (curr->value < min_node->value)
			min_node = curr;
		curr = curr->next;
	}
	return (min_node);
}

int get_pos(t_node *stack, t_node *target)
{
    int i;
    t_node *curr;

    i = 0;
    curr = stack;
    while (curr != target)
    {
        i++;
        curr = curr->next;
    }
    return (i);
}