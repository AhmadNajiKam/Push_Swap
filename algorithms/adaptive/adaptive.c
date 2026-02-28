/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 02:41:43 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/28 05:20:26 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../push_swap.h"

void handle_adaptive(t_stack *stack_a, t_stack *stack_b, t_bench_stats *bench) {
  float disorder;

  disorder = compute_disorder(stack_a);
  if (disorder < 20.0f && disorder >= 0.0f) {
    handle_simple(stack_a, stack_b, bench);
    bench->strategy = SIMPLE;
  } else if (disorder >= 20.0f && disorder < 50.0f) {
    handle_medium(stack_a, stack_b, bench);
    bench->strategy = MEDIUM;
  } else if (disorder >= 50.0f) {
    handle_complex(stack_a, stack_b, bench);
    bench->strategy = COMPLEX;
  }
}
