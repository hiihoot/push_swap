/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-mou <sait-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 08:49:13 by sait-mou          #+#    #+#             */
/*   Updated: 2026/01/25 10:46:43 by sait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include "unistd.h"
#include <stdio.h>


typedef struct s_node
{
    int             value;
    int             index; // Very useful for later!
    struct s_node   *next;
    struct s_node   *prev;
} t_node;

//libft helpers:
char	**ft_split(const char *s, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t n, size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void free_stack(t_node **stack);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);

//free
void free_stack(t_node **stack);
void exit_err(t_node **stack, char **args, int print);
void free_table(char **str);

//parsing
int parse_to_list(t_node **stack, char **args);
int check_dup(t_node *stack);
void add_node_back(t_node **stack, int value);
int check_dup(t_node *stack);

//operations
void pa(t_node **stack_a, t_node **stack_b);
void pb(t_node **stack_a, t_node **stack_b);

void ra(t_node **stack_a, int print);
void rb(t_node **stack_b, int print);
void rr(t_node **stack_a, t_node **stack_b);

void rra(t_node **stack_a, int print);
void rrb(t_node **stack_b, int print);
void rrr(t_node **stack_a, t_node **stack_b);

void	sa(t_node **stack_a, int print);
void	sb(t_node **stack_b, int print);
void	ss(t_node **stack_a, t_node **stack_b);


//helpers
int is_sorted(t_node *stack);
int stack_len(t_node *stack);
void sort_three(t_node **stack_a);
int get_pos(t_node *stack, t_node *target);
t_node	*find_min(t_node *stack);


void sort_five(t_node **stack_a, t_node **stack_b);




#endif
