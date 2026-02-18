/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:49:21 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/18 12:26:30 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(int content) {
  t_list *node;

  node = malloc(sizeof(t_list));
  if (!node)
    return (NULL);
  node->content = content;
  node->next = NULL;
  node->prev = NULL;
  node->index = 0;
  node->pos = 0;
  return (node);
}
