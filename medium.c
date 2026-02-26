/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:26:38 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/24 15:52:20 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	handle_medium(t_stack *stack_a, t_stack *stack_b)
{
	int		counter;
	int		chunk_size;
	t_list	*max;

	if (stack_a->size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	counter = 0;
	while (stack_a->size > 0)
	{
		if (stack_a->first->index < counter)
		{
			push_b(stack_a, stack_b);
			counter++;
		}
		else if (stack_a->first->index < counter + chunk_size)
		{
			push_b(stack_a, stack_b);
			shift_up('b', stack_b);
			counter++;
		}
		else
			shift_up('a', stack_a);
	}
	while (stack_b->size > 0)
	{
		max = find_max(stack_b);
		rotate_stack(stack_b, cost_calc(max->pos, stack_b->size));
		push_a(stack_a, stack_b);
	}
}
