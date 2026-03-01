/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 05:52:29 by akamamji          #+#    #+#             */
/*   Updated: 2026/03/01 21:19:55 by akamamji         ###   ########.fr       */
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

static int	check_non_integers(int argc, char **argv)
{
	int	i;
	int	flag_count;
	int	number_started;
	int	status;

	i = 1;
	flag_count = 0;
	number_started = 0;
	while (i < argc)
	{
		status = handle_flag(argv[i], &flag_count, number_started);
		if (status == -1)
			return (-1);
		if (status == 0)
			if (handle_number(argv[i], &number_started) == -1)
				return (-1);
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	if (argc < 2)
		return (-1);
	if (check_non_integers(argc, argv) == -1)
		return (-1);
	if (is_there_duplicates(argc, argv) != 0)
		return (-1);
	return (1);
}

int	is_sorted(int argc, char **argv)
{
	int	i;
	int	sorted;
	int	num;
	int	next_num;

	i = 1;
	sorted = 1;
	while (i < argc - 1)
	{
		if (is_valid_number(argv[i]) && is_valid_number(argv[i + 1]))
		{
			ft_atoi_strict(argv[i], &num);
			ft_atoi_strict(argv[i + 1], &next_num);
			if (num > next_num)
			{
				sorted = 0;
				break ;
			}
		}
		i++;
	}
	return (sorted);
}
