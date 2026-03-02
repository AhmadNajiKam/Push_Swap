/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 21:13:28 by akamamji          #+#    #+#             */
/*   Updated: 2026/03/02 00:27:29 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	handle_flag(const char *arg, int *mode_used, int number_started)
{
	if (resolve_mode(arg) == -1)
		return (0);
	if (resolve_mode(arg) != -1)
	{
		if (number_started)
			return (-1);
		if (*mode_used)
			return (-1);
		*mode_used = 1;
	}
	return (1);
}

int	handle_number(const char *arg, int *number_started)
{
	int	num;

	*number_started = 1;
	if (!ft_atoi_strict((char *)arg, &num))
		return (-1);
	return (1);
}

int	count_numbers(int argc, char **argv)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		if (!(argv[i][0] == '-' && argv[i][1] == '-'))
			count++;
		i++;
	}
	return (count);
}

int	has_duplicates(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] == arr[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	fill_numbers(int argc, char **argv, int *arr)
{
	int	i;
	int	index;

	i = 1;
	index = 0;
	while (i < argc)
	{
		if (!(argv[i][0] == '-' && argv[i][1] == '-'))
		{
			if (!ft_atoi_strict(argv[i], &arr[index]))
				return (-1);
			index++;
		}
		i++;
	}
	return (1);
}
