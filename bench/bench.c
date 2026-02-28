/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 02:40:38 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/28 05:48:08 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_dprintf/ft_dprintf.h"
#include "../push_swap.h"
void init_bench(t_bench_stats *bench) {
  int i;

  i = 0;
  while (i < OP_COUNT) {
    bench->ops[i] = 0;
    i++;
  }
  bench->disorder = 0;
  bench->strategy = ADAPTIVE;
  bench->is_adaptive = 0;
}
int get_total_ops(t_bench_stats *bench) {
  int i;
  int total;
  i = 0;
  total = 0;
  while (i < OP_COUNT) {
    total += bench->ops[i];
    i++;
  }
  return total;
}
void print_bench(t_bench_stats *bench) {
  ft_dprintf(2, "[bench] disorder:  %f%%\n", bench->disorder);
  ft_dprintf(2, "[bench] total_ops:  %d\n", get_total_ops(bench));
  ft_dprintf(2, "[bench] strategy: ");
  if (bench->is_adaptive) {
    ft_dprintf(2, "Adaptive / ");
    if (bench->strategy == SIMPLE)
      ft_dprintf(2, "O(n^2)\n");
    else if (bench->strategy == MEDIUM)
      ft_dprintf(2, "O(n√n)\n");
    else if (bench->strategy == COMPLEX)
      ft_dprintf(2, "O(nlogn)\n");
  } else {
    if (bench->strategy == SIMPLE)
      ft_dprintf(2, "Simple / O(n^2)\n");
    else if (bench->strategy == MEDIUM)
      ft_dprintf(2, "Medium / O(n√n)\n");
    else if (bench->strategy == COMPLEX)
      ft_dprintf(2, "Complex / O(nlogn)\n");
  }
  ft_dprintf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", 0, 0, 0,
             bench->ops[PA], bench->ops[PB]);
  ft_dprintf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d",
             bench->ops[RA], bench->ops[RB], 0, bench->ops[RRA],
             bench->ops[RRB], 0);
}
