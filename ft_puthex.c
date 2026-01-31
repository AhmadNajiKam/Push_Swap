/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:56:54 by akamamji          #+#    #+#             */
/*   Updated: 2026/01/07 17:24:22 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char type)
{
	char	*base;
	int		count;

	count = 0;
	if (type == 'x')
		base = "0123456789abcdef\0";
	else if (type == 'X')
		base = "0123456789ABCDEF\0";
	if (n >= 16)
		count += ft_puthex(n / 16, type);
	count += ft_putchar(base[n % 16]);
	return (count);
}
