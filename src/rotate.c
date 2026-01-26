/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-mou <sait-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:23:30 by sait-mou          #+#    #+#             */
/*   Updated: 2026/01/25 13:23:46 by sait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void rotate(t_node **stack)
{
    if (*stack && (*stack)->next != *stack)
        *stack = (*stack)->next;
}

void ra(t_node **stack_a, int print)
{
    rotate(stack_a);
    if (print)
        write(1, "ra\n", 3);
}


void rb(t_node **stack_b, int print)
{
    rotate(stack_b);
    if (print)
        write(1, "ra\n", 3);
}

void rr(t_node **stack_a, t_node **stack_b)
{
    ra(stack_a, 0);
    rb(stack_b, 0);
    write(1, "rr\n", 3);
}

