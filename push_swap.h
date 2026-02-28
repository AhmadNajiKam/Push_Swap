/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:04:11 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/28 05:17:49 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "libft.h"
#include <limits.h>

typedef struct stack {
  t_list *first;
  t_list *last;
  int size;
} t_stack;
typedef enum strategies_enum {
  SIMPLE = 1,
  MEDIUM = 2,
  COMPLEX = 3,
  ADAPTIVE = 4,
} t_strategy;
typedef enum operations_enum {
  SA,
  SB,
  SS,
  PA,
  PB,
  RA,
  RB,
  RR,
  RRA,
  RRB,
  RRR,
  OP_COUNT
} t_op_codes;
typedef struct s_bench {
  long ops[OP_COUNT];
  double disorder;
  int is_adaptive;
  int strategy;
} t_bench_stats;
int parse_command_line(int argc, char **argv);
int ft_isnum(char *str);
void handle_simple(t_stack *stack_a, t_stack *stack_b, t_bench_stats *bench);
void handle_medium(t_stack *stack_a, t_stack *stack_b, t_bench_stats *bench);
void handle_complex(t_stack *stack_a, t_stack *stack_b, t_bench_stats *bench);
void handle_adaptive(t_stack *stack_a, t_stack *stack_b, t_bench_stats *bench);
void swap(char c, t_stack *stack);
void push_a(t_stack *stack_a, t_stack *stack_b);
void push_b(t_stack *stack_a, t_stack *stack_b);
void shift_up(char c, t_stack *stack);
void shift_down(char c, t_stack *stack);
void print_stack(t_stack *stack);
void shift_up_both(t_stack *stack_a, t_stack *stack_b);
void shift_down_both(t_stack *stack_a, t_stack *stack_b);
void swap_both(t_stack *stack_a, t_stack *stack_b);
void init_stack(t_stack **stack);
void stack_addback(t_stack *stack, t_list *node);
void stack_addfront(t_stack *stack, t_list *node);
t_list *find_max(t_stack *stack);
t_list *find_min(t_stack *stack);
void fill_indices(t_stack *stack);
int cost_calc(int pos, int size);
void rotate_stack(t_stack *stack, int cost, char c, t_bench_stats *bench);
int ft_strcmp(const char *s1, const char *s2);
int get_mode(int argc, char **argv, int *bench);
float compute_disorder(t_stack *stack_a);
void init_bench(t_bench_stats *bench);
void print_bench(t_bench_stats *bench);
void update_pos(t_stack *stack);
#endif
