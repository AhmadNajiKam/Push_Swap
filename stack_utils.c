/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 06:30:54 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/11 07:59:45 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"

t_stack	*init_stack(t_list **stack)
{
	t_stack	*stack_a;

	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	stack_a->first = *stack;
	stack_a->last = ft_lstlast(*stack);
	stack_a->size = ft_lstsize(stack_a->first);
	return (stack_a);
}
