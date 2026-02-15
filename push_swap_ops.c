/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 10:29:21 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/14 10:38:34 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_list	*b_top_next;

	if ((*stack_b)->size < 1)
		return ;
	ft_printf("pa ");
	b_top_next = (*stack_b)->first->next;
	(*stack_b)->first->next = NULL;
	(*stack_b)->first->prev = NULL;
	ft_lstadd_front(&(*stack_a)->first, (*stack_b)->first);
	(*stack_b)->first = b_top_next;
	(*stack_a)->size++;
	(*stack_b)->size--;
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_list	*a_top_next;

	if ((*stack_a)->size < 1)
		return ;
	ft_printf("pb ");
	a_top_next = (*stack_a)->first->next;
	(*stack_a)->first->next = NULL;
	(*stack_a)->first->prev = NULL;
	ft_lstadd_front(&(*stack_b)->first, (*stack_a)->first);
	(*stack_b)->first = a_top_next;
	(*stack_b)->size++;
	(*stack_a)->size--;
}

void	swap(char c, t_stack **stack)
{
	int	content;

	if ((*stack)->size <= 1)
		return ;
	if (c == 'a')
		ft_printf("sa ");
	else if (c == 'b')
		ft_printf("sb ");
	content = (*stack)->first->content;
	(*stack)->first->content = (*stack)->first->next->content;
	(*stack)->first->next->content = content;
}

void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("ss ");
	swap('x', stack_a);
	swap('x', stack_b);
}
