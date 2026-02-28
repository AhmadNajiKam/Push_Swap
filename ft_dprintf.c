/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 22:01:01 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/28 01:53:15 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
static int parser(char c, va_list args) {
  int count;

  count = 0;
  if (c == 'c')
    count += ft_putchar(va_arg(args, int));
  else if (c == 's')
    count += ft_putstr(va_arg(args, char *));
  else if (c == 'd' || c == 'i')
    count += ft_putnbr(va_arg(args, int));
  else if (c == '%')
    count += ft_putchar('%');
  return (count);
  return (-1);
}

static int loop(const char *format, va_list *param_list, int i) {
  size_t count;
  int return_value;

  count = 0;
  return_value = -1;
  while (format[i]) {
    if (format[i] == '%') {
      return_value = parser(format[++i], *param_list);
      count += return_value;
    } else {
      return_value = ft_putchar(format[i]);
      count += return_value;
    }
    if (return_value == -1)
      return (-1);
    i++;
  }
  return (count);
}

int ft_dprintf(const char *format, ...) {
  size_t count;
  va_list param_list;

  if (!format)
    return (-1);
  va_start(param_list, format);
  count = loop(format, &param_list, 0);
  va_end(param_list);
  return (count);
}
