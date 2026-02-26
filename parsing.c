/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:03:41 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/26 02:46:37 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	multiplexer(int mode, t_stack *stack_a, t_stack *stack_b)
{
	if (mode < 0)
	{
		handle_bench(stack_a, stack_b);
		mode *= -1;
	}
	if (mode == SIMPLE)
		handle_simple(stack_a, stack_b);
	else if (mode == MEDIUM)
		handle_medium(stack_a, stack_b);
	else if (mode == COMPLEX)
		handle_complex(stack_a, stack_b);
	else if (mode == ADAPTIVE)
		handle_adaptive(stack_a, stack_b);
}

static int	check_mode(int argc, char **argv)
{
	int	i;
	int	algo_mode;
	int	bench_multiplier;

	i = 1;
	algo_mode = 0;
	bench_multiplier = 1;
	while (i < argc)
	{
		if (!ft_strncmp(argv[i], "--bench", 8))
			bench_multiplier = -1;
		else if (!ft_strncmp(argv[i], "--simple", 9))
		{
			if (algo_mode != 0)
				return (0);
			algo_mode = SIMPLE;
		}
		else if (!ft_strncmp(argv[i], "--medium", 9))
		{
			if (algo_mode != 0)
				return (0);
			algo_mode = MEDIUM;
		}
		else if (!ft_strncmp(argv[i], "--complex", 10))
		{
			if (algo_mode != 0)
				return (0);
			algo_mode = COMPLEX;
		}
		else if (!ft_strncmp(argv[i], "--adaptive", 11))
		{
			if (algo_mode != 0)
				return (0);
			algo_mode = ADAPTIVE;
		}
		i++;
	}
	if (algo_mode == 0)
		algo_mode = ADAPTIVE;
	return (algo_mode * bench_multiplier);
}

int	parse_command_line(int argc, char **argv)
{
	t_list	*node;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	i = 1;
	init_stack(&stack_a);
	init_stack(&stack_b);
	while (i < argc)
	{
		if (ft_isnum(argv[i]))
		{
			node = ft_lstnew(ft_atoi(argv[i]));
			stack_addfront(stack_a, node);
		}
		i++;
	}
	fill_indices(stack_a);
	// multiplexer(check_mode(argc, argv), stack_a, stack_b);
	handle_complex(stack_a, stack_b);
	return (0);
}
