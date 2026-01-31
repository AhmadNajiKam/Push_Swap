/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:58:25 by akamamji          #+#    #+#             */
/*   Updated: 2026/01/11 17:46:53 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	int	count;

	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	count = ft_strlen(s);
	if (write(1, s, count) == -1)
		return (-1);
	return (count);
}
