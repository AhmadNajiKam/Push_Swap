/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:13:53 by akamamji          #+#    #+#             */
/*   Updated: 2026/01/03 18:13:54 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		count;

	if (!lst)
		return (0);
	tmp = lst;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
