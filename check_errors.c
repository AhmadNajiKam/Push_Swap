/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 05:52:29 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/28 05:56:21 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"

int is_sorted(int argc, char **argv) {
  int i;
  int sorted;

  i = 1;
  sorted = 1;
  while (i < argc - 1) {
    if (ft_isnum(argv[i]) && ft_isnum(argv[i + 1]) &&
        ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
      sorted = 0;
    i++;
  }
  return sorted;
}
