/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-mou <sait-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:29:10 by sait-mou          #+#    #+#             */
/*   Updated: 2026/01/26 14:41:37 by sait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_node **src, t_node **dst)
{
	t_node	*node_to_push;

	if (!src || !*src)
		return ;
	node_to_push = *src;
	if (node_to_push->next == node_to_push)
		*src = NULL;
	else
	{
		*src = node_to_push->next;
		node_to_push->prev->next = node_to_push->next;
		node_to_push->next->prev = node_to_push->prev;
	}
	if (!*dst)
	{
		*dst = node_to_push;
		node_to_push->next = node_to_push;
		node_to_push->prev = node_to_push;
	}
	else
	{
		node_to_push->next = *dst;
		node_to_push->prev = (*dst)->prev;
		(*dst)->prev->next = node_to_push;
		(*dst)->prev = node_to_push;
		*dst = node_to_push;
	}
}

void pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
