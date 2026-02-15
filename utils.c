/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:03:31 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/15 13:02:03 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

void print_stack(t_stack *stack) {
  if (!stack)
    return;
  while (stack->last) {
    ft_printf("%d", stack->last->content);
    stack->last = stack->last->prev;
  }
}
