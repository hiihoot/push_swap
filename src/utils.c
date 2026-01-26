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