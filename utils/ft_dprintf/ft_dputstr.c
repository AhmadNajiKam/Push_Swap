/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 04:14:12 by akamamji          #+#    #+#             */
/*   Updated: 2026/03/01 01:02:30 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_dprintf.h"

int	ft_dputstr(int fd, char *s)
{
	int	count;

	if (!s)
	{
		if (write(fd, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	count = ft_strlen(s);
	if (write(fd, s, count) == -1)
		return (-1);
	return (count);
}
