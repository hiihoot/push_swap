
#include "checker_bonus.h"

static int   do_op(char *s, t_node **stack_a, t_node **stack_b)
{
    if (ft_strcmp(s, "pa\n"))
        pa(stack_a, stack_b, 0);
    else if (ft_strcmp(s, "pb\n"))
        pb(stack_a, stack_b, 0);
    else if (ft_strcmp(s, "ra\n"))
        ra(stack_a, 0);
    else if (ft_strcmp(s, "rb\n"))
        rb(stack_b, 0);
    else if (ft_strcmp(s, "rr\n"))
        rr(stack_a, stack_b, 0);
    else if (ft_strcmp(s, "rra\n"))
        rra(stack_a, 0);
    else if (ft_strcmp(s, "rrb\n"))
        rrb(stack_b, 0);
    else if (ft_strcmp(s, "rrr\n"))
        rrr(stack_a, stack_b, 0);
    else if (ft_strcmp(s, "sa\n"))
        sa(stack_a, 0);
    else if (ft_strcmp(s, "sb\n"))
        sb(stack_b, 0);
    else if (ft_strcmp(s, "ss\n"))
        ss(stack_a, stack_b, 0);
    else
        return (0);
    return (1);
}




int main(int ac, char **av)
{
    t_node *stack_a;
    t_node *stack_b;
    char **args;
    char *line;

    stack_a = NULL;
    stack_b = NULL;
    if (ac == 1)
        return (0);
    args = get_input(ac, av);
    if (!args || !parse_to_list(&stack_a, args) || check_dup(stack_a))
		exit_err(&stack_a, args, 1);
    line = get_next_line(0);
    while (line)
	    {
		    if (!do_op(line, &stack_a, &stack_b))
		    {
			    free(line);
			    exit_err(&stack_a, args, 1);
		    }
		    free(line);
		    line = get_next_line(0);
	    }
	    if (is_sorted(stack_a) && !stack_b)
		    write(1, "OK\n", 3);
	    else
		    write(1, "KO\n", 3);

}