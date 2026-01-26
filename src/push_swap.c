/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-mou <sait-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 08:47:37 by sait-mou          #+#    #+#             */
/*   Updated: 2026/01/25 10:46:43 by sait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int is_only_spaces(char *str)
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


void print_stack(t_node *stack, char *w)
{
    t_node *curr;

    if (!stack)
    {
        printf("Stack is empty!\n");
        return;
    }
    curr = stack;
    printf("--- Stack %s ---\n", w);
    while (1)
    {
        printf("Val: %d\n", curr->value);
        curr = curr->next;
        if (curr == stack)
            break;
    }
    printf("---------------\n");
}


char **get_input(int ac, char **av)
{
    char *str;
    char *tmp;
    char **res;
    int i;

    i = 1;
    str = ft_strdup("");
    while (i < ac)
    {
        if (av[i][0] == '\0' || is_only_spaces(av[i]))
        {
            free(str);
            exit_err(NULL, NULL, 1);
        }
        tmp = str;
        str = ft_strjoin(tmp, av[i]);
        free(tmp);
        tmp = str;
        str = ft_strjoin(tmp, " ");
        free(tmp);
        i++;
    }
    res = ft_split(str, ' ');
    free(str);
    return (res);
}


int main(int ac, char **av)
{
    t_node *stack_a;
    // t_node *stack_b;
    char **args;

    stack_a = NULL;
    // stack_b = NULL;

    if (ac == 1)
        return 0;
    args = get_input(ac, av);
    if (!args)
        exit_err(NULL, NULL, 1);
    if (!parse_to_list(&stack_a, args))
        exit_err(&stack_a, args, 1);
    if (check_dup(stack_a))
        exit_err(&stack_a, args, 1);
    if (is_sorted(stack_a))
        exit_err(&stack_a, args, 0);
   
    free_table(args);
    free_stack(&stack_a);
}

