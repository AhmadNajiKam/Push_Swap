/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 06:30:54 by akamamji          #+#    #+#             */
/*   Updated: 2026/03/02 04:42:39 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

void	init_stack(t_stack **stack)
{
	*stack = malloc(sizeof(t_stack));
	if (!*stack)
		return ;
	(*stack)->first = NULL;
	(*stack)->last = NULL;
	(*stack)->size = 0;
}

int	free_stack(t_stack **stack)
{
	t_list	*current;
	t_list	*next;

	if (!stack || !*stack)
		return (-1);
	current = (*stack)->first;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(*stack);
	*stack = NULL;
	return (1);
}

void	stack_addfront(t_stack *stack, t_list *node)
{
	if (!stack || !node)
		return ;
	node->prev = NULL;
	node->next = stack->first;
	if (stack->first)
	{
		stack->first->prev = node;
		node->pos = stack->first->pos + 1;
	}
	else
	{
		stack->last = node;
		node->pos = 0;
	}
	stack->first = node;
	stack->size++;
}

void	stack_addback(t_stack *stack, t_list *node)
{
	if (!stack || !node)
		return ;
	node->next = NULL;
	node->prev = stack->last;
	if (stack->last)
	{
		stack->last->next = node;
		node->pos = stack->last->pos + 1;
	}
	else
	{
		stack->first = node;
		node->pos = 0;
	}
	stack->last = node;
	stack->size++;
}
