/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:04:04 by akamamji          #+#    #+#             */
/*   Updated: 2026/03/01 21:29:19 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_dprintf.h"
#include "include/push_swap.h"

int	main(int argc, char **argv)
{
	if (is_sorted(argc, argv))
		return (0);
	if (check_args(argc, argv))
		parse_command_line(argc, argv);
	else
		ft_dprintf(2, "Error\n");
}
