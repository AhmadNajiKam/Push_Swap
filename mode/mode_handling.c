/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:41:16 by akamamji          #+#    #+#             */
/*   Updated: 2026/03/02 01:21:56 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	resolve_mode(const char *arg)
{
	if (!ft_strcmp(arg, "--simple"))
		return (SIMPLE);
	if (!ft_strcmp(arg, "--medium"))
		return (MEDIUM);
	if (!ft_strcmp(arg, "--complex"))
		return (COMPLEX);
	if (!ft_strcmp(arg, "--adaptive"))
		return (ADAPTIVE);
	return (-1);
}

static int	handle_cli_flag(const char *arg, int *mode_selected, int *bench,
		int *mode)
{
	int	resolved;

	if (is_valid_number((char *)arg))
		return (1);
	if (!ft_strcmp(arg, "--bench"))
	{
		if (*bench)
			return (-1);
		*bench = 1;
		return (1);
	}
	resolved = resolve_mode(arg);
	if (resolved == -1 || *mode_selected)
		return (-1);
	*mode = resolved;
	*mode_selected = 1;
	return (1);
}

int	get_mode(int argc, char **argv, int *bench)
{
	int	i;
	int	mode;
	int	mode_selected;

	mode = ADAPTIVE;
	mode_selected = 0;
	*bench = 0;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
			if (handle_cli_flag(argv[i], &mode_selected, bench, &mode) == -1)
				return (-1);
		i++;
	}
	return (mode);
}
