/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:11:42 by akamamji          #+#    #+#             */
/*   Updated: 2026/03/02 16:32:49 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

int	cost_calc(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	else
		return (pos - size);
}

void	rotate_stack(t_stack *stack, int cost, char c, t_bench_stats *bench)
{
	if (cost > 0)
	{
		while (cost--)
		{
			shift_up(c, stack);
			if (c == 'a')
				bench->ops[RA]++;
			else if (c == 'b')
				bench->ops[RB]++;
		}
	}
	else
	{
		while (cost++)
		{
			shift_down(c, stack);
			if (c == 'a')
				bench->ops[RRA]++;
			else if (c == 'b')
				bench->ops[RRB]++;
		}
	}
}

static void	simple_selection_sort(t_stack *a, t_stack *b, t_bench_stats *bench)
{
	t_list	*min;

	while (a->size > 0)
	{
		min = find_min(a);
		rotate_stack(a, cost_calc(min->pos, a->size), 'a', bench);
		push_b(a, b);
		bench->ops[PB]++;
	}
	while (b->size > 0)
	{
		push_a(a, b);
		bench->ops[PA]++;
	}
}

void	handle_simple(t_stack *a, t_stack *b, t_bench_stats *bench)
{
	if (is_sorted(a))
		return ;
	if (a->size <= 3)
	{
		sort_three(a, bench);
		return ;
	}
	if (a->size <= 5)
	{
		sort_five(a, b, bench);
		return ;
	}
	simple_selection_sort(a, b, bench);
}
