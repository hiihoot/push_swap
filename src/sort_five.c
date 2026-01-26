#include "push_swap.h"


void sort_five(t_node **stack_a, t_node **stack_b)
{
    t_node *min;
    int len;

    while (stack_len(*stack_a) > 3)
    {
        min = find_min(*stack_a);
        len = stack_len(*stack_a);
        // Optimization: if min is in the bottom half, use rra
        if (get_pos(*stack_a, min) <= len / 2)
        {
            while (*stack_a != min)
                ra(stack_a, 1);
        }
        else
        {
            while (*stack_a != min)
                rra(stack_a, 1);
        }
        pb(stack_a, stack_b);
    }
    sort_three(stack_a);
    while (*stack_b)
        pa(stack_a, stack_b);
}