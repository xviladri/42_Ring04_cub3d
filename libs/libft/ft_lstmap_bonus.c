/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:05:50 by xviladri          #+#    #+#             */
/*   Updated: 2025/01/21 15:32:47 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	void	*content;
	t_list	*new_node;

	new_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst != NULL)
	{
		content = f((*lst).content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			free(content);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = (*lst).next;
	}
	return (new_list);
}
