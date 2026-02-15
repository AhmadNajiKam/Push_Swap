/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 10:30:34 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/14 10:40:52 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void	shift_up(char c, t_stack **stack)
{
	t_list	*first_next_saved;

	if ((*stack)->size < 2)
		return ;
	if (c == 'a')
		ft_printf("ra ");
	else if (c == 'b')
		ft_printf("rb ");
	first_next_saved = (*stack)->first->next;
	ft_lstadd_back(&(*stack)->first, (*stack)->first);
	(*stack)->last = (*stack)->last->next;
	(*stack)->last->next = NULL;
	(*stack)->first = first_next_saved;
	(*stack)->first->prev = NULL;
}

void	shift_down(char c, t_stack **stack)
{
	t_list	*last_prev_saved;

	if ((*stack)->size < 2)
		return ;
	if (c == 'a')
		ft_printf("rra ");
	else if (c == 'b')
		ft_printf("rrb ");
	last_prev_saved = (*stack)->last->prev;
	ft_lstadd_front(&(*stack)->first, (*stack)->last);
	(*stack)->first->prev = NULL;
	(*stack)->last = last_prev_saved;
	(*stack)->last->next = NULL;
}

void	shift_up_both(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("rr ");
	shift_up('x', stack_a);
	shift_up('x', stack_b);
}

void	shift_down_both(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("rrr ");
	shift_down('x', stack_a);
	shift_down('x', stack_b);
}
