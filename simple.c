/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:11:42 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/18 12:35:01 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int cost_calc(int pos, int size) {
  int top_pos;

  top_pos = size - 1 - pos;
  if (top_pos <= size / 2)
    return (top_pos);
  else
    return (top_pos - size);
}

static void rotate_stack(t_stack *stack, int cost) {
  if (cost > 0) {
    while (cost--)
      shift_up('a', stack);
  } else {
    while (cost++)
      shift_down('a', stack);
  }
}

void handle_simple(t_stack *stack_a, t_stack *stack_b) {
  t_list *max;
  int pos;

  while (stack_a->size > 0) {
    max = find_max(stack_a);
    rotate_stack(stack_a, cost_calc(max->pos, stack_a->size));
    push_b(stack_a, stack_b);
  }
  while (stack_b->size > 0)
    push_a(stack_a, stack_b);
}
