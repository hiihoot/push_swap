/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-mou <sait-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:27:41 by sait-mou          #+#    #+#             */
/*   Updated: 2025/12/01 16:08:37 by sait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>


typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//gnl functions
char	*get_next_line(int fd);

//helpers

char	**ft_split(const char *s, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t n, size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char  *s1, char  *s2);
char	*ft_strdup(const char *str);
int	ft_strcmp(const char *s1, const char *s2);
char *ft_strchr(char *s, int c);

/* free */
void	free_stack(t_node **stack);
void	exit_err(t_node **stack, char **args, int print);
void	free_table(char **str);

/* parsing */
int		parse_to_list(t_node **stack, char **args);
int		check_dup(t_node *stack);
void	add_node_back(t_node **stack, int value);

/* operations */
void	pa(t_node **stack_a, t_node **stack_b, int print);
void	pb(t_node **stack_a, t_node **stack_b, int print);
void	ra(t_node **stack_a, int print);
void	rb(t_node **stack_b, int print);
void	rr(t_node **stack_a, t_node **stack_b, int print);
void	rra(t_node **stack_a, int print);
void	rrb(t_node **stack_b, int print);
void	rrr(t_node **stack_a, t_node **stack_b, int print);
void	sa(t_node **stack_a, int print);
void	sb(t_node **stack_b, int print);
void	ss(t_node **stack_a, t_node **stack_b, int print);

/* helpers */
int		is_sorted(t_node *stack);
int		stack_len(t_node *stack);
int		get_pos(t_node *stack, t_node *target);
t_node	*find_min(t_node *stack);
void	index_stack(t_node *stack);
int		all_sort_except_one(t_node *stack_a);
char	**get_input(int ac, char **av);
#endif