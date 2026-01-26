/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-mou <sait-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:17:49 by sait-mou          #+#    #+#             */
/*   Updated: 2026/01/25 17:17:53 by sait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rev_rotate(t_node **stack)
{
    if (*stack && (*stack)->next != *stack)
        *stack = (*stack)->prev;
}



void rra(t_node **stack_a, int print)
{
    rev_rotate(stack_a);
    if (print)
        write(1, "rra\n", 4);
}


void rrb(t_node **stack_b, int print)
{
    rev_rotate(stack_b);
    if (print)
        write(1, "rrb\n", 4);
}


void rrr(t_node **stack_a, t_node **stack_b)
{
    rra(stack_a, 0);
    rrb(stack_b, 0);
    write(1, "rrr\n", 4);
}