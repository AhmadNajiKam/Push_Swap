/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:03:41 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/18 14:13:20 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*static int multiplexer(int mode, t_list **stackA) {
  int error;

  error = 0;
  if (mode % 2 == 0) {
                                error = handle_bench(stackA);
                                mode /= 2;
  }
  if (mode == 1)
                                error = handle_simple(stackA);
  else if (mode == 3)
                                error = handle_medium(stackA);
  else if (mode == 5)
                                error = handle_complex(stackA);
  else if (mode == 7)
                                error = handle_adaptive(stackA);
  else
                                error = -1;
  return (error);
}
*/
static int check_mode(char **argv) {
  int i;
  int mode;

  i = 1;
  mode = 1;
  while (i < 3) {
    if (!ft_strncmp(argv[i], "--simple", 8))
      mode *= 1;
    else if (!ft_strncmp(argv[i], "--medium", 8))
      mode *= 3;
    else if (!ft_strncmp(argv[i], "--complex", 9))
      mode *= 5;
    else if (!ft_strncmp(argv[i], "--adaptive", 10))
      mode *= 7;
    else if (!ft_strncmp(argv[i], "--bench", 7))
      mode *= 2;
    else if (ft_isnum(argv[i]) && mode == 1)
      mode = 7;
    i++;
  }
  return (mode);
}

int parse_command_line(int argc, char **argv) {
  t_list *node;
  t_list *stack_b_lst;
  t_stack *stack_a;
  t_stack *stack_b;
  int i;

  stack_b_lst = NULL;
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
  handle_medium(stack_a, stack_b);
  return (1);
}
