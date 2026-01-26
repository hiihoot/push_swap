/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-mou <sait-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 09:54:16 by sait-mou          #+#    #+#             */
/*   Updated: 2026/01/26 14:41:37 by sait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_table(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_stack(t_node **stack)
{
	t_node	*curr;
	t_node	*tmp;

	if (!stack || !*stack)
		return ;
	curr = *stack;
	if (curr->prev)
		curr->prev->next = NULL;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	*stack = NULL;
}

void	exit_err(t_node **stack, char **args, int print)
{
	if (stack && *stack)
		free_stack(stack);
	if (args)
		free_table(args);
	if (print)
		write(2, "Error\n", 6);
	exit(1);
}
