/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:03:41 by akamamji          #+#    #+#             */
/*   Updated: 2026/03/01 18:29:00 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

static int	start_algo(int argc, char **argv, t_stack *stack_a,
		t_stack *stack_b)
{
	int				bench;
	t_bench_stats	bench_stats;
	int				mode;

	init_bench(&bench_stats);
	mode = get_mode(argc, argv, &bench);
	bench_stats.disorder = compute_disorder(stack_a);
	bench_stats.strategy = mode;
	if (mode == SIMPLE)
		handle_simple(stack_a, stack_b, &bench_stats);
	else if (mode == MEDIUM)
		handle_medium(stack_a, stack_b, &bench_stats);
	else if (mode == COMPLEX)
		handle_complex(stack_a, stack_b, &bench_stats);
	else if (mode == ADAPTIVE)
		handle_adaptive(stack_a, stack_b, &bench_stats);
	else
		return (-1);
	if (mode == ADAPTIVE)
		bench_stats.is_adaptive = 1;
	if (bench == 1)
		print_bench(&bench_stats);
	return (1);
}

int	parse_command_line(int argc, char **argv)
{
	t_list	*node;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		num;

	i = 1;
	init_stack(&stack_a);
	init_stack(&stack_b);
	while (i < argc)
	{
		if (is_valid_number(argv[i]) > 0)
		{
			if (ft_atoi_strict(argv[i], &num))
				node = ft_lstnew(num);
			else
				return (-1);
			stack_addback(stack_a, node);
		}
		i++;
	}
	fill_indices(stack_a);
	start_algo(argc, argv, stack_a, stack_b);
	return (0);
}
