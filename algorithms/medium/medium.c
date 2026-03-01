/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:26:38 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/28 16:24:22 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

static void	push_chunks_to_b(t_stack *a, t_stack *b, int chunk_size,
		t_bench_stats *bench)
{
	int	counter;

	counter = 0;
	while (a->size > 0)
	{
		if (a->first->index < counter)
		{
			push_b(a, b);
			bench->ops[PB]++;
			counter++;
		}
		else if (a->first->index < counter + chunk_size)
		{
			push_b(a, b);
			shift_up('b', b);
			bench->ops[RB]++;
			counter++;
		}
		else
		{
			shift_up('a', a);
			bench->ops[RA]++;
		}
	}
}

static void	push_back_sorted(t_stack *stack_a, t_stack *stack_b,
		t_bench_stats *bench)
{
	t_list	*max;

	while (stack_b->size > 0)
	{
		max = find_max(stack_b);
		rotate_stack(stack_b, cost_calc(max->pos, stack_b->size), 'b', bench);
		push_a(stack_a, stack_b);
		bench->ops[PA]++;
	}
}

void	handle_medium(t_stack *stack_a, t_stack *stack_b, t_bench_stats *bench)
{
	int	chunk_size;

	if (stack_a->size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	push_chunks_to_b(stack_a, stack_b, chunk_size, bench);
	push_back_sorted(stack_a, stack_b, bench);
}
