/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 06:30:54 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/15 13:11:54 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void init_stack(t_stack **stack) {
  *stack = malloc(sizeof(t_stack));
  if (!*stack)
    return;
  (*stack)->first = NULL;
  (*stack)->last = NULL;
  (*stack)->size = 0;
}

void stack_addfront(t_stack *stack, t_list *node) {
  if (!stack || !node)
    return;
  node->prev = NULL;
  node->next = stack->first;
  if (stack->first)
    stack->first->prev = node;
  else
    stack->last = node;
  stack->first = node;
  stack->size++;
}

void stack_addback(t_stack *stack, t_list *node) {
  if (!stack || !node) {
    return;
  }
  node->next = NULL;
  node->prev = stack->last;
  if (stack->last)
    stack->last->next = node;
  else
    stack->first = node;
  stack->last = node;
  stack->size++;
}
