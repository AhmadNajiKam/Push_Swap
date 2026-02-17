/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 10:30:34 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/17 14:26:36 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void	shift_up(char c, t_stack *stack)
{
	t_list	*node;

	if (stack->size < 2)
		return ;
	if (c == 'a')
		ft_printf("ra ");
	else if (c == 'b')
		ft_printf("rb ");
	node = stack->first;
	stack->first = node->next;
	stack->first->prev = NULL;
	node->prev = stack->last;
	node->next = NULL;
	stack->last->next = node;
	stack->last = node;
}

void	shift_down(char c, t_stack *stack)
{
	t_list	*node;

	if (stack->size < 2)
		return ;
	if (c == 'a')
		ft_printf("rra ");
	else if (c == 'b')
		ft_printf("rrb ");
	node = stack->last;
	stack->last = node->prev;
	stack->last->next = NULL;
	node->next = stack->first;
	node->prev = NULL;
	stack->first->prev = node;
	stack->first = node;
}

void	shift_up_both(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("rr ");
	shift_up('x', stack_a);
	shift_up('x', stack_b);
}

void	shift_down_both(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("rrr ");
	shift_down('x', stack_a);
	shift_down('x', stack_b);
}
