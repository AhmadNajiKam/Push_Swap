/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:03:31 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/08 17:15:57 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void print_stack(t_list *stack) {
  while (stack) {
    ft_printf("%d", stack->content);
    stack = stack->next;
  }
}

void swap(char c, t_list **stack) {
  t_list *current;
  t_list *current_prev;
  int content;

  current = *stack;
  current_prev = *stack;
  if (c == 'a')
    ft_printf("sa ");
  else if (c == 'b')
    ft_printf("sb ");
  while (current->next) {
    current_prev = current;
    current = current->next;
  }
  content = current->content;
  current->content = current_prev->content;
  current_prev->content = content;
}

void swap_both(t_list **stack_a, t_list **stack_b) {
  swap('a', stack_a);
  swap('b', stack_b);
}
void push(char c, t_list **stack_a, t_list **stack_b) {}
