/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:04:04 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/08 16:57:28 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int main(int argc, char **argv) {
  t_list *stack_a;

  stack_a = NULL;
  if (argc > 1)
    parse_command_line(argc, argv, &stack_a);
  return (0);
}
