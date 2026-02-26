/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:03:41 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/27 02:42:00 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int start_algo(int argc, char **argv, t_stack *stack_a,
                      t_stack *stack_b) {
  int bench;

  if (get_mode(argc, argv, &bench) == SIMPLE)
    handle_simple(stack_a, stack_b);
  else if (get_mode(argc, argv, &bench) == MEDIUM)
    handle_medium(stack_a, stack_b);
  else if (get_mode(argc, argv, &bench) == COMPLEX)
    handle_complex(stack_a, stack_b);
  else if (get_mode(argc, argv, &bench) == ADAPTIVE)
    handle_adaptive(stack_a, stack_b);
  else
    return (-1);
  return (bench);
}

int parse_command_line(int argc, char **argv) {
  t_list *node;
  t_stack *stack_a;
  t_stack *stack_b;
  int i;

  i = 1;
  init_stack(&stack_a);
  init_stack(&stack_b);
  while (i < argc) {
    if (ft_isnum(argv[i])) {
      node = ft_lstnew(ft_atoi(argv[i]));
      stack_addfront(stack_a, node);
    }
    i++;
  }
  fill_indices(stack_a);
  start_algo(argc, argv, stack_a, stack_b);
  return (0);
}
