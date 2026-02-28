/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 10:30:34 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/28 03:50:01 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void update_pos(t_stack *stack) {
  t_list *current;
  int i;

  if (!stack || !stack->first)
    return;
  current = stack->first;
  i = 0;
  while (current) {
    current->pos = i;
    i++;
    current = current->next;
  }
}

void shift_up(char c, t_stack *stack) {
  t_list *node;

  if (stack->size < 2)
    return;
  if (c == 'a')
    ft_printf("ra\n");
  else if (c == 'b')
    ft_printf("rb\n");
  node = stack->first;
  stack->first = node->next;
  stack->first->prev = NULL;
  node->prev = stack->last;
  node->next = NULL;
  stack->last->next = node;
  stack->last = node;
  update_pos(stack);
}

void shift_down(char c, t_stack *stack) {
  t_list *node;

  if (stack->size < 2)
    return;
  if (c == 'a')
    ft_printf("rra\n");
  else if (c == 'b')
    ft_printf("rrb\n");
  node = stack->last;
  stack->last = node->prev;
  stack->last->next = NULL;
  node->next = stack->first;
  node->prev = NULL;
  stack->first->prev = node;
  stack->first = node;
  update_pos(stack);
}

void shift_up_both(t_stack *stack_a, t_stack *stack_b) {
  ft_printf("rr\n");
  shift_up('x', stack_a);
  shift_up('x', stack_b);
}

void shift_down_both(t_stack *stack_a, t_stack *stack_b) {
  ft_printf("rrr\n");
  shift_down('x', stack_a);
  shift_down('x', stack_b);
}
