/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:05:26 by xviladri          #+#    #+#             */
/*   Updated: 2025/01/03 16:25:44 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list	*root = NULL;
	t_list	*node1 = malloc(sizeof(t_list));
	node1->content = "Primer nodo";
	node1->next = NULL;

	ft_lstadd_front(&root, node1);
	printf("%s\n", (char *)node1->content);
}*/
