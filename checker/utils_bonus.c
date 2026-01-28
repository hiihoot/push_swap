/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-mou <sait-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:55:23 by sait-mou          #+#    #+#             */
/*   Updated: 2026/01/26 14:41:37 by sait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_sorted(t_node *stack)
{
	t_node	*tmp;

	if (!stack)
		return (1);
	tmp = stack;
	while (tmp->next != stack && tmp)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	stack_len(t_node *stack)
{
	int		i;
	t_node	*node;

	if (!stack)
		return (0);
	i = 0;
	node = stack;
	while (1)
	{
		i++;
		node = node->next;
		if (node == stack)
			break ;
	}
	return (i);
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

int	get_pos(t_node *stack, t_node *target)
{
	int		i;
	t_node	*curr;

	i = 0;
	curr = stack;
	while (curr != target)
	{
		i++;
		curr = curr->next;
		if (curr == stack)
			break ;
	}
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}