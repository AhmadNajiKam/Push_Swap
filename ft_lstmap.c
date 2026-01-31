/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:07:24 by akamamji          #+#    #+#             */
/*   Updated: 2026/01/03 19:07:26 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	void	*new_content;
	t_list	*head;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_list = ft_lstnew(new_content);
		if (!new_list)
		{
			del(new_content);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new_list);
		lst = lst->next;
	}
	return (head);
}
