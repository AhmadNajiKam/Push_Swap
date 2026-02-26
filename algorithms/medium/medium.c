/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:26:38 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/27 02:43:19 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../push_swap.h"

static void	push_chunks_to_b(t_stack *a, t_stack *b, int chunk_size)
{
	int	counter;

	counter = 0;
	while (a->size > 0)
	{
		if (a->first->index < counter)
		{
			push_b(a, b);
			counter++;
		}
		else if (a->first->index < counter + chunk_size)
		{
			push_b(a, b);
			shift_up('b', b);
			counter++;
		}
		else
			shift_up('a', a);
	}
}

static void	push_back_sorted(t_stack *a, t_stack *b)
{
	t_list	*max;

	while (b->size > 0)
	{
		max = find_max(b);
		rotate_stack(b, cost_calc(max->pos, b->size));
		push_a(a, b);
	}
}

void	handle_medium(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;

	if (stack_a->size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	push_chunks_to_b(stack_a, stack_b, chunk_size);
	push_back_sorted(stack_a, stack_b);
}
