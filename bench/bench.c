/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 02:40:38 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/27 21:52:24 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void init_bench(t_bench_stats *bench) {
  int i;

  i = 0;
  while (i < OP_COUNT) {
    bench->ops[i] = 0;
    i++;
  }
}

void print_bench(t_bench_stats *bench) {}
