/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:03:31 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/26 02:39:27 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <limits.h>

t_list	*find_max(t_stack *stack)
{
	int		max;
	t_list	*node;
	t_list	*node_pos;

	max = INT_MIN;
	node = stack->first;
	while (node)
	{
		if (node->content > max)
		{
			max = node->content;
			node_pos = node;
		}
		node = node->next;
	}
	return (node_pos);
}

t_list	*find_min(t_stack *stack)
{
	int		min;
	t_list	*node;
	t_list	*node_pos;

	min = INT_MAX;
	node = stack->first;
	while (node)
	{
		if (node->content < min)
		{
			min = node->content;
			node_pos = node;
		}
		node = node->next;
	}
	return (node_pos);
}

void	fill_indices(t_stack *stack)
{
	t_list	*node;
	t_list	*target;
	int		i;

	i = 0;
	while (i < stack->size)
	{
		target = NULL;
		node = stack->last;
		while (node)
		{
			if (node->index == -1)
			{
				if (target == NULL || node->content < target->content)
					target = node;
			}
			node = node->prev;
		}
		if (target)
			target->index = i;
		i++;
	}
}

void	print_stack(t_stack *stack)
{
	t_list	*iter;

	if (!stack)
		return ;
	iter = stack->first;
	while (iter)
	{
		ft_printf("%d ", iter->content);
		iter = iter->next;
	}
}

float	compute_disorder(t_stack *stack_a)
{
	int		mistakes;
	int		total_pairs;
	t_list	*iter;
	t_list	*iter_prev;

	mistakes = 0;
	total_pairs = 0;
	iter = stack_a->last;
	while (iter)
	{
		iter_prev = iter->prev;
		while (iter_prev)
		{
			total_pairs++;
			if (iter->content > iter_prev->content)
				mistakes++;
			iter_prev = iter_prev->prev;
		}
		iter = iter->prev;
	}
	return (mistakes * 1.0 / total_pairs);
}
