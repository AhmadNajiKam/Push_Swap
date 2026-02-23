/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 10:29:21 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/23 17:19:25 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void push_a(t_stack *stack_a, t_stack *stack_b) {
  t_list *b_top_next;

  if (stack_b->size < 1)
    return;
  ft_printf("pa\n");
  b_top_next = stack_b->first->next;
  if (b_top_next)
    b_top_next->prev = NULL;
  stack_addfront(stack_a, stack_b->first);
  stack_b->first = b_top_next;
  stack_b->size--;
}

void push_b(t_stack *stack_a, t_stack *stack_b) {
  t_list *a_top_next;

  if (stack_a->size < 1)
    return;
  ft_printf("pb\n");
  a_top_next = stack_a->first->next;
  if (a_top_next)
    a_top_next->prev = NULL;
  stack_addfront(stack_b, stack_a->first);
  stack_a->first = a_top_next;
  stack_a->size--;
}

void swap(char c, t_stack *stack) {
  t_list *first;
  t_list *second;
  t_list *third;
  int temp_pos;

  if (stack->size <= 1)
    return;
  if (c == 'a' || c == 'b')
    ft_printf("s%c\n", c);
  first = stack->first;
  second = first->next;
  third = second->next;
  temp_pos = first->pos;
  first->pos = second->pos;
  second->pos = temp_pos;
  second->next = first;
  second->prev = NULL;
  first->prev = second;
  first->next = third;
  if (third)
    third->prev = first;
  stack->first = second;
  if (stack->size == 2)
    stack->last = first;
}

void swap_both(t_stack *stack_a, t_stack *stack_b) {
  ft_printf("ss\n");
  swap('x', stack_a);
  swap('x', stack_b);
}
