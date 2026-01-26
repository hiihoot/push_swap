/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-mou <sait-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 10:10:00 by sait-mou          #+#    #+#             */
/*   Updated: 2026/01/26 14:41:37 by sait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static long ft_atoi_ps(const char *str, t_node **stack, char **args)
{
    long    res;
    int     sign;
    int     i;

    res = 0;
    sign = 1;
    i = 0;
    if (!str || str[i] == '\0')
        return (0);
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
            exit_err(stack, args, 1);
        i++;
    }
    return (res * sign);
}


static int is_valid_num(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

void add_node_back(t_node **stack, int value)
{
    t_node *new_node;
    t_node *last;

    new_node = malloc(sizeof(t_node));
    if (!new_node)
        return ;
    new_node->value = value;
    if (!*stack)
    {
        *stack = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    }
    else
    {
        last = (*stack)->prev;
        last->next = new_node;
        new_node->prev = last;
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }
}

int parse_to_list(t_node **stack, char **args)
{
    int i;
    long    nb;

    i = 0;
    if (!args || !args[i])
        return (0);
    while (args[i]) 
    {
        if (!is_valid_num(args[i]))
            exit_err(stack, args, 1);
        nb = ft_atoi_ps(args[i], stack, args);
        add_node_back(stack, (int)nb);
        i++;
    }
    return (1);
}

// 3 3
int check_dup(t_node *stack)
{
    t_node *curr;
    t_node *check;

    if (!stack)
        return (0);
    curr = stack;
    while (1)
    {
        check = curr->next;
        while (check != stack)
        {
            if (curr->value == check->value)
                return (1);
            check = check->next;
        }
        curr = curr->next;
        if (curr == stack)
            break;
    }
    return (0);
}



