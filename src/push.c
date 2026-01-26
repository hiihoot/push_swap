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

static t_node	*detach_node(t_node **src)
{
	t_node	*node;

	node = *src;
	if (node->next == node)
		*src = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		*src = node->next;
	}
	node->next = node;
	node->prev = node;
	return (node);
}

static void	push(t_node **src, t_node **dst)
{
	t_node	*node;

	if (!src || !*src)
		return ;
	node = detach_node(src);
	if (!*dst)
		*dst = node;
	else
	{
		node->next = *dst;
		node->prev = (*dst)->prev;
		node->prev->next = node;
		(*dst)->prev = node;
		*dst = node;
	}
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
