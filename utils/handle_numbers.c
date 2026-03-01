/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:16:52 by akamamji          #+#    #+#             */
/*   Updated: 2026/03/01 18:25:58 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	get_sign(char *str, int *index)
{
	int	sign;

	sign = 1;
	*index = 0;
	if (str[*index] == '+' || str[*index] == '-')
	{
		if (str[*index] == '-')
			sign = -1;
		(*index)++;
	}
	return (sign);
}

int	accumulate_number(char *str, int index, int sign, int *out)
{
	long	result;
	long	limit;
	int		digit;

	result = 0;
	if (sign == 1)
		limit = INT_MAX;
	else
		limit = -(long)INT_MIN;
	while (str[index])
	{
		digit = str[index] - '0';
		if (result > (limit - digit) / 10)
			return (0);
		result = result * 10 + digit;
		index++;
	}
	*out = (int)(result * sign);
	return (1);
}

int	ft_atoi_strict(char *str, int *out)
{
	int	sign;
	int	index;

	if (!is_valid_number(str))
		return (0);
	sign = get_sign(str, &index);
	if (!accumulate_number(str, index, sign, out))
		return (0);
	return (1);
}
