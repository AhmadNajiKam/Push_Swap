/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:11:42 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/17 15:57:20 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <limits.h>

static void rotate_stack(t_stack *stack_b, int number) {
  if (number > 0)
    while (number > 0) {
      shift_up('b', stack_b);
      number--;
    }
  else
    while (number < 0) {
      shift_down('b', stack_b);
      number++;
    }
}

static int cost_to_insert(t_stack *stack_b, int number, int cmp) {
  t_list *iter;
  int i;
  int temp;
  int min_diff;

  iter = stack_b->last;
  i = 0;
  temp = 0;
  min_diff = INT_MAX;
  while (iter) {
    if (number > cmp && iter->content == cmp)
      temp = i;
    else if (number < cmp && iter->content == cmp)
      temp = i;
    else if (iter->content > number && iter->content - number < min_diff &&
             cmp == 0) {
      temp = i;
      min_diff = iter->content - number;
    }
    i++;
    iter = iter->prev;
  }
  if (stack_b->size - temp <= temp)
    return (stack_b->size - temp);
  else
    return (-temp);
}

int handle_simple(t_stack *stack_a, t_stack *stack_b) {
  int max;
  int min;
  int cost;
  int val;

  if (stack_a->size > 0)
    push_b(stack_a, stack_b);
  while (stack_a->size > 0) {
    max = find_max(stack_b);
    min = find_min(stack_b);
    val = stack_a->first->content;
    cost = 0;
    if (val > max && stack_b->first->content != max)
      cost = cost_to_insert(stack_b, stack_a->first->content, max);
    else if (val < min && stack_b->last->content != min)
      cost = cost_to_insert(stack_b, val, min);
    else
      cost = cost_to_insert(stack_b, val, 0);
    rotate_stack(stack_b, cost);
    push_b(stack_a, stack_b);
  }
  while (stack_b->size > 0) {
    min = find_min(stack_b);
    while (stack_b->first->content != min)
      shift_down('b', stack_b);
    push_a(stack_a, stack_b);
  }
  return (1);
}
