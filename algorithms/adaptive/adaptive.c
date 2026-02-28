/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 02:41:43 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/27 04:40:08 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../push_swap.h"

void	handle_adaptive(t_stack *stack_a, t_stack *stack_b,
		t_bench_stats *bench)
{
	float	disorder;

	disorder = compute_disorder(stack_a);
	if (disorder < 0.2f && disorder >= 0.0f)
		handle_simple(stack_a, stack_b, bench);
	else if (disorder >= 0.2f && disorder < 0.5f)
		handle_medium(stack_a, stack_b, bench);
	else if (disorder >= 0.5f)
		handle_complex(stack_a, stack_b, bench);
}
