/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:47:56 by xviladri          #+#    #+#             */
/*   Updated: 2025/01/03 16:42:12 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
/*
int	main(void)
{
	t_list	*node1 = malloc(sizeof(t_list));
	if(!node1)
		return (1);
	t_list	*node2 = malloc(sizeof(t_list));
	if(!node2)
		return (1);
	t_list	*node3 = malloc(sizeof(t_list));
	if(!node3)
		return (1);
	if (node1 && node2 && node3)
	{
		node1->content = "N";
		node1->next = node2;
		node2->content = "O";
		node2->next = node3;
		node3->content = "I";
		node3->next = NULL;
	}
	int	size;

	size = ft_lstsize(node1);
	printf("El tamanio de la lista es de %d\n", size);

	free(node1);
	free(node2);
	free(node3);
	return (0);
}*/
