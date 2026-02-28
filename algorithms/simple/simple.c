/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:11:42 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/28 03:49:01 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../push_swap.h"

int cost_calc(int pos, int size) {
  if (pos <= size / 2)
    return (pos);
  else
    return (pos - size);
}

void rotate_stack(t_stack *stack, int cost, char c, t_bench_stats *bench) {
  if (cost > 0) {
    while (cost--) {
      shift_up(c, stack);
      if (c == 'a')
        bench->ops[RA]++;
      else if (c == 'b')
        bench->ops[RB]++;
    }
  } else {
    while (cost++) {
      shift_down(c, stack);
      if (c == 'a')
        bench->ops[RRA]++;
      else if (c == 'b')
        bench->ops[RRB]++;
    }
  }
}

void handle_simple(t_stack *stack_a, t_stack *stack_b, t_bench_stats *bench) {
  t_list *min;

  while (stack_a->size > 0) {
    min = find_min(stack_a);
    rotate_stack(stack_a, cost_calc(min->pos, stack_a->size), 'a', bench);
    push_b(stack_a, stack_b);
    bench->ops[PB]++;
  }
  while (stack_b->size > 0) {
    push_a(stack_a, stack_b);
    bench->ops[PA]++;
  }
}
