/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-mou <sait-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 08:47:37 by sait-mou          #+#    #+#             */
/*   Updated: 2026/01/26 14:41:37 by sait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	check_sort(t_node **stack, t_node **stack2)
{
	int	len;

	len = stack_len(*stack);
	if (len == 2)
		sa(stack, 1);
	else if (all_sort_except_one(*stack))
		rra(stack, 1);
	else if (len == 3)
		sort_three(stack);
	else if (len <= 5)
		sort_five(stack, stack2);
	else
	{
		index_stack(*stack);
		if (len <= 100)
			butterfly_sort(stack, stack2, 15);
		else
			butterfly_sort(stack, stack2, 35);
		push_back_to_a(stack, stack2);
	}
}

static int	is_only_spaces(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (str[i] != ' ' && (str[i] < 9 || str[i] > 13))
			return (0);
		i++;
	}
	return (1);
}

char	**get_input(int ac, char **av)
{
	char	*str;
	char	*tmp;
	char	**res;
	int		i;

	i = 0;
	str = ft_strdup("");
	while (++i < ac)
	{
		if (av[i][0] == '\0' || is_only_spaces(av[i]))
		{
			free(str);
			exit_err(NULL, NULL, 1);
		}
		tmp = ft_strjoin(str, av[i]);
		free(str);
		str = ft_strjoin(tmp, " ");
		free(tmp);
	}
	res = ft_split(str, ' ');
	free(str);
	return (res);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**args;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	args = get_input(ac, av);
	if (!parse_to_list(&stack_a, args))
		exit_err(&stack_a, args, 1);
	if (check_dup(stack_a))
		exit_err(&stack_a, args, 1);
	if (!is_sorted(stack_a))
		check_sort(&stack_a, &stack_b);
	free_table(args);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
