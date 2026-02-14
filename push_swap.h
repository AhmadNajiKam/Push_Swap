/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:04:11 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/14 10:14:12 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "libft.h"
typedef struct stack {
  t_list *first;
  t_list *last;
  int size;
} t_stack;
int parse_command_line(int argc, char **argv, t_list **stackA);
int ft_isnum(char *str);
int handle_bench(t_list **stack_a);
int handle_simple(t_list **stack_a);
int handle_medium(t_list **stack_a);
int handle_complex(t_list **stack_a);
int handle_adaptive(t_list **stack_a);
void swap(char c, t_stack **stack);
void push_a(t_stack **stack_a, t_stack **stack_b);
void push_b(t_stack **stack_a, t_stack **stack_b);
void shift_up(char c, t_stack **stack);
void shift_down(char c, t_stack **stack);
void print_stack(t_stack *stack);
t_stack *init_stack(t_list **stack);
#endif
