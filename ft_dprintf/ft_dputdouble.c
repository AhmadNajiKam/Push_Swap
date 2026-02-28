/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputdouble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 04:16:52 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/28 04:23:02 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
int ft_dputdouble(int fd, double number) {
  int upper;
  int lower;
  int count;

  count = 0;
  upper = number;
  lower = number * 100;
  lower %= 100;
  count += ft_dputnbr(fd, upper);
  count += ft_dputchar(fd, '.');
  count += ft_dputnbr(fd, lower);
  return count;
}
