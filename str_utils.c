/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:04:30 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/28 02:21:04 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isnum(char *str) {
  int i = 0;

  if (!str)
    return (0);
  if (str[i] == '-' || str[i] == '+')
    i++;
  if (!str[i])
    return (0);
  while (str[i]) {
    if (!ft_isdigit(str[i]))
      return (0);
    i++;
  }
  return (1);
}
