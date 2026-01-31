/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:08:50 by akamamji          #+#    #+#             */
/*   Updated: 2026/01/07 18:22:02 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static int	ft_putptr_hex(uintptr_t n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		count += ft_putptr_hex(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_putmem(void *p)
{
	size_t	count;

	if (!p)
		return (ft_putstr("(nil)"));
	count = 0;
	count += ft_putstr("0x");
	count += ft_putptr_hex((uintptr_t)p);
	return (count);
}
