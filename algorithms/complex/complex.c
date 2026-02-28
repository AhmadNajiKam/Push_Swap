/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 01:55:37 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/28 01:52:20 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int find_max_index(t_stack *stack_a) {
  int max;
  t_list *iter;

  max = INT_MIN;
  iter = stack_a->first;
  while (iter) {
    if (iter->index > max)
      max = iter->index;
    iter = iter->next;
  }
  return (max);
}

static int find_max_bits(t_stack *stack_a) {
  int max;
  int bits;

  max = find_max_index(stack_a);
  bits = 0;
  while ((max >> bits) != 0)
    bits++;
  return (bits);
}

static void process_bit(t_stack *a, t_stack *b, t_bench_stats *bench, int bit) {
  int j;
  int size;

  size = a->size;
  j = 0;
  while (j < size) {
    if (((a->first->index >> bit) & 1) == 1) {
      shift_up('a', a);
      bench->ops[RA]++;
    } else {
      push_b(a, b);
      bench->ops[PB]++;
    }
    j++;
  }
}

static void restore_from_b(t_stack *a, t_stack *b, t_bench_stats *bench) {
  while (b->size > 0) {
    push_a(a, b);
    bench->ops[PA]++;
  }
}

void handle_complex(t_stack *stack_a, t_stack *stack_b, t_bench_stats *bench) {
  int max_bits;
  int i;

  max_bits = find_max_bits(stack_a);
  i = 0;
  while (i < max_bits) {
    process_bit(stack_a, stack_b, bench, i);
    restore_from_b(stack_a, stack_b, bench);
    i++;
  }
}
