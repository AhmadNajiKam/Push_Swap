/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:03:31 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/14 10:23:47 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

void print_stack(t_stack *stack) {
  while (stack->last) {
    ft_printf("%d", stack->last->content);
    stack->last = stack->last->prev;
  }
}

void swap(char c, t_stack **stack) {
  int content;

  if ((*stack)->size <= 1)
    return;
  if (c == 'a')
    ft_printf("sa ");
  else if (c == 'b')
    ft_printf("sb ");
  content = (*stack)->first->content;
  (*stack)->first->content = (*stack)->first->next->content;
  (*stack)->first->next->content = content;
}

void swap_both(t_stack **stack_a, t_stack **stack_b) {
  swap('a', stack_a);
  swap('b', stack_b);
}

void push_a(t_stack **stack_a, t_stack **stack_b) {
  t_list *b_top_next;

  if ((*stack_b)->size < 1)
    return;
  ft_printf("pa ");
  b_top_next = (*stack_b)->first->next;
  (*stack_b)->first->next = NULL;
  (*stack_b)->first->prev = NULL;
  ft_lstadd_front(&(*stack_a)->first, (*stack_b)->first);
  (*stack_b)->first = b_top_next;
  (*stack_a)->size++;
  (*stack_b)->size--;
}

void push_b(t_stack **stack_a, t_stack **stack_b) {
  t_list *a_top_next;

  if ((*stack_a)->size < 1)
    return;
  ft_printf("pb ");
  a_top_next = (*stack_a)->first->next;
  (*stack_a)->first->next = NULL;
  (*stack_a)->first->prev = NULL;
  ft_lstadd_front(&(*stack_b)->first, (*stack_a)->first);
  (*stack_b)->first = a_top_next;
  (*stack_b)->size++;
  (*stack_a)->size--;
}

void shift_up(char c, t_stack **stack) {
  t_list *first_next_saved;
  if ((*stack)->size < 2)
    return;
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

void shift_down(char c, t_stack **stack) {
  t_list *last_prev_saved;
  if ((*stack)->size < 2)
    return;
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
