/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 02:40:38 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/28 18:28:20 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_dprintf.h"
#include "../include/push_swap.h"

void	init_bench(t_bench_stats *bench)
{
	int	i;

	i = 0;
	while (i < OP_COUNT)
	{
		bench->ops[i] = 0;
		i++;
	}
	bench->disorder = 0;
	bench->strategy = ADAPTIVE;
	bench->is_adaptive = 0;
}

int	get_total_ops(t_bench_stats *bench)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < OP_COUNT)
	{
		total += bench->ops[i];
		i++;
	}
	return (total);
}

static void	print_strategy(t_bench_stats *bench)
{
	const char	*prefix;
	static char	*g_strategy_names[3];

	g_strategy_names[SIMPLE] = "O(n^2)";
	g_strategy_names[MEDIUM] = "O(n√n)";
	g_strategy_names[COMPLEX] = "O(nlogn)";
	if (bench->is_adaptive)
		prefix = "Adaptive";
	else if (bench->strategy == SIMPLE)
		prefix = "Simple";
	else if (bench->strategy == MEDIUM)
		prefix = "Medium";
	else
		prefix = "Complex";
	ft_dprintf(2, "[bench] strategy: %s / %s\n", prefix,
		g_strategy_names[bench->strategy]);
}

void	print_bench(t_bench_stats *bench)
{
	ft_dprintf(2, "[bench] disorder: %f%%\n", bench->disorder);
	ft_dprintf(2, "[bench] total_ops: %d\n", get_total_ops(bench));
	print_strategy(bench);
	ft_dprintf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", 0, 0, 0,
		bench->ops[PA], bench->ops[PB]);
	ft_dprintf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d",
		bench->ops[RA], bench->ops[RB], 0, bench->ops[RRA], bench->ops[RRB], 0);
}
