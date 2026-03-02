/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:03:31 by akamamji          #+#    #+#             */
/*   Updated: 2026/03/02 05:17:54 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

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

double	compute_disorder(t_stack *stack_a)
{
	int		mistakes;
	int		total_pairs;
	t_list	*iter;

	if (!stack_a || stack_a->size < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = stack_a->size - 1;
	iter = stack_a->first;
	while (iter && iter->next)
	{
		if (iter->content > iter->next->content)
			mistakes++;
		iter = iter->next;
	}
	return ((mistakes * 100.0) / total_pairs);
}

int	is_sorted(t_stack *stack)
{
	t_list	*current;

	if (!stack || !stack->first)
		return (1);
	current = stack->first;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}
