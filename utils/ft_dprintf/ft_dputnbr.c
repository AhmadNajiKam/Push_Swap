/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 04:03:00 by akamamji          #+#    #+#             */
/*   Updated: 2026/03/01 01:02:20 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/ft_dprintf.h"

int	ft_dputnbr(int fd, int n)
{
	long	nb;
	int		count;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		count += ft_dputchar(fd, '-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		count += ft_dputnbr(fd, nb / 10);
	}
	count += ft_dputchar(fd, (nb % 10) + '0');
	return (count);
}
