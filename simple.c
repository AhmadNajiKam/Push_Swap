/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:11:42 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/16 08:20:21 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
static int index_not_sorted(t_stack *stack_a) {
  int i;
  int temp;
  t_list *iter;
  i = 1;
  temp = stack_a->last->content;
  iter = stack_a->last->prev;
  while (iter) {
    if (iter->content < temp)
      break;
    i++;
    temp = iter->content;
    iter = iter->prev;
  }
  return i;
}
static int find_insertion_pos(t_stack *stack_a, int number) {
  int i;
  t_list *iter;
  i = 0;
  iter = stack_a->last;
  while (iter) {
    if (iter->content > number)
      break;
    i++;
    iter = iter->prev;
  }
  if ((stack_a->size - 1) - i <= i)
    return ((stack_a->size - 1) - i);
  else
    return -1 * i;
}
static void rotate_stack(t_stack *stack_a, int rotates) {
  if (rotates > 0) {
    while (rotates > 0) {
      shift_up('a', stack_a);
      rotates--;
    }
  } else if (rotates < 0) {
    while (rotates < 0) {
      shift_down('a', stack_a);
      rotates++;
    }
  }
}
int handle_simple(t_stack *stack_a, t_stack *stack_b) {
  int sorted_idx;
  int rotates;
  sorted_idx = index_not_sorted(stack_a);
  while (stack_a->size > sorted_idx && stack_a->size > 1)
    push_b(stack_a, stack_b);
  while (stack_b->size > 0) {
    rotates = find_insertion_pos(stack_a, stack_b->first->content);
    if (rotates == 0 && stack_a->first->content > stack_b->first->content) {
      push_a(stack_a, stack_b);
      rotate_stack(stack_a, 1);
    } else if (rotates == 0 &&
               stack_a->first->content < stack_b->first->content)
      push_a(stack_a, stack_b);
    else {
      rotate_stack(stack_a, rotates);
      push_a(stack_a, stack_b);
      rotate_stack(stack_a, 2 * rotates * -1);
    }
  }
  return 1;
}
