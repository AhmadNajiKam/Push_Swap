/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:41:16 by akamamji          #+#    #+#             */
/*   Updated: 2026/03/01 18:41:30 by akamamji         ###   ########.fr       */
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

int	get_mode(int argc, char **argv, int *bench)
{
	int	i;
	int	mode;
	int	resolved;
	int	mode_selected;

	mode = ADAPTIVE;
	mode_selected = 0;
	*bench = 0;
	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "--bench"))
			*bench = 1;
		else if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			resolved = resolve_mode(argv[i]);
			if (resolved == -1 || mode_selected)
				return (-1);
			mode = resolved;
			mode_selected = 1;
		}
		i++;
	}
	return (mode);
}
