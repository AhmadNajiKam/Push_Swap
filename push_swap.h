/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:04:11 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/26 16:04:30 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct stack
{
	t_list		*first;
	t_list		*last;
	int			size;
}				t_stack;
typedef struct s_bench
{
	long		total_ops;
	long		sa;
	long		sb;
	long		ss;
	long		pa;
	long		pb;
	long		ra;
	long		rb;
	long		rr;
	long		rra;
	long		rrb;
	long		rrr;
}				t_bench_stats;
typedef enum strategies_enum
{
	SIMPLE = 1,
	MEDIUM = 2,
	COMPLEX = 3,
	ADAPTIVE = 4,
}				t_strategy;
typedef struct s_algo_entry
{
	const char	*flag;
	int			mode;
	void		(*handler)(t_stack *, t_stack *);
}				t_algo_entry;
typedef enum operations_enum
{
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
	RRR
}				t_op_codes;
int				parse_command_line(int argc, char **argv);
int				ft_isnum(char *str);
void			handle_bench(t_stack *stack_a, t_stack *stack_b);
void			handle_simple(t_stack *stack_a, t_stack *stack_b);
void			handle_medium(t_stack *stack_a, t_stack *stack_b);
void			handle_complex(t_stack *stack_a, t_stack *stack_b);
void			handle_adaptive(t_stack *stack_a, t_stack *stack_b);
void			swap(char c, t_stack *stack);
void			push_a(t_stack *stack_a, t_stack *stack_b);
void			push_b(t_stack *stack_a, t_stack *stack_b);
void			shift_up(char c, t_stack *stack);
void			shift_down(char c, t_stack *stack);
void			print_stack(t_stack *stack);
void			shift_up_both(t_stack *stack_a, t_stack *stack_b);
void			shift_down_both(t_stack *stack_a, t_stack *stack_b);
void			swap_both(t_stack *stack_a, t_stack *stack_b);
void			init_stack(t_stack **stack);
void			stack_addfront(t_stack *stack, t_list *node);
void			stack_addback(t_stack *stack, t_list *node);
t_list			*find_max(t_stack *stack);
t_list			*find_min(t_stack *stack);
void			fill_indices(t_stack *stack);
int				cost_calc(int pos, int size);
void			rotate_stack(t_stack *stack, int cost);
#endif
