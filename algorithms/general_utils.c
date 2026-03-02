/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 21:32:17 by akamamji          #+#    #+#             */
/*   Updated: 2026/03/01 22:46:48 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack *stack_a, t_bench_stats *bench)
{
	t_list	*max;

	if (stack_a->size == 3)
	{
		max = find_max(stack_a);
		if (max->pos == 0)
		{
			shift_up('a', stack_a);
			bench->ops[RA]++;
		}
		else if (max->pos == 1)
		{
			shift_down('a', stack_a);
			bench->ops[RRA]++;
		}
	}
	if (stack_a->first->content > stack_a->first->next->content)
	{
		swap('a', stack_a);
		bench->ops[SA]++;
	}
}

void	sort_five(t_stack *a, t_stack *b, t_bench_stats *bench)
{
	t_list	*min;

	while (a->size > 3)
	{
		min = find_min(a);
		rotate_stack(a, cost_calc(min->pos, a->size), 'a', bench);
		push_b(a, b);
		bench->ops[PB]++;
	}
	sort_three(a, bench);
	while (b->size > 0)
	{
		push_a(a, b);
		bench->ops[PA]++;
	}
}
