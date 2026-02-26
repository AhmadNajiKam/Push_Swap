/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 01:55:37 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/26 16:05:00 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	find_max_index(t_stack *stack_a)
{
	int		max;
	t_list	*iter;

	max = INT_MIN;
	iter = stack_a->first;
	while (iter)
	{
		if (iter->index > max)
			max = iter->index;
		iter = iter->next;
	}
	return (max);
}

static int	find_max_bits(t_stack *stack_a)
{
	int	max;
	int	bits;

	max = find_max_index(stack_a);
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	handle_complex(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	i = 0;
	size = stack_a->size;
	max_bits = find_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((stack_a->first->index >> i) & 1) == 1)
				shift_up('a', stack_a);
			else
				push_b(stack_a, stack_b);
			j++;
		}
		while (stack_b->size > 0)
			push_a(stack_a, stack_b);
		i++;
	}
}
