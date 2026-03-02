/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 05:52:29 by akamamji          #+#    #+#             */
/*   Updated: 2026/03/02 00:27:47 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

static void	sort_int_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	while (i < size)
	{
		tmp = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > tmp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = tmp;
		i++;
	}
}

static int	is_there_duplicates(int argc, char **argv)
{
	int	*arr;
	int	count;
	int	result;

	count = count_numbers(argc, argv);
	if (count == 0)
		return (0);
	arr = malloc(sizeof(int) * count);
	if (!arr)
		return (-1);
	if (fill_numbers(argc, argv, arr) == -1)
		return (free(arr), -1);
	sort_int_array(arr, count);
	result = has_duplicates(arr, count);
	free(arr);
	return (result);
}

static int	validate_numbers(int argc, char **argv)
{
	int	i;
	int	number_started;

	i = 1;
	number_started = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (number_started)
				return (-1);
		}
		else if (handle_number(argv[i], &number_started) == -1)
			return (-1);
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	int	bench;

	if (argc < 2)
		return (-1);
	if (get_mode(argc, argv, &bench) == -1)
		return (-1);
	if (validate_numbers(argc, argv) == -1)
		return (-1);
	if (is_there_duplicates(argc, argv) != 0)
		return (-1);
	return (1);
}
