/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:04:04 by akamamji          #+#    #+#             */
/*   Updated: 2026/03/02 05:17:29 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_dprintf.h"
#include "include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (check_args(argc, argv) > 0)
	{
		init_stack(&stack_a);
		init_stack(&stack_b);
		parse_command_line(argc, argv, stack_a, stack_b);
		free_stack(&stack_a);
		free_stack(&stack_b);
		exit(0);
	}
	else
	{
		ft_dprintf(2, "Error\n");
		exit(1);
	}
}
