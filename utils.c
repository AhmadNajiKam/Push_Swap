/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:03:31 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/17 12:01:50 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <limits.h>

void print_stack(t_stack *stack) {
  if (!stack)
    return;
  while (stack->last) {
    ft_printf("%d", stack->last->content);
    stack->last = stack->last->prev;
  }
}

int find_max(t_stack *stack) {
  int max;
  t_list *node;

  max = INT_MIN;
  node = stack->first;
  while (node) {
    if (node->content > max)
      max = node->content;
    node = node->next;
  }
  return max;
}

int find_min(t_stack *stack) {
  int min;
  t_list *node;

  min = INT_MAX;
  node = stack->first;
  while (node) {
    if (node->content < min)
      min = node->content;
    node = node->next;
  }
  return min;
}
