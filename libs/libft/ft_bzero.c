/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  xviladri < xviladri@student.42barcelona.c +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:54:31 by xviladri          #+#    #+#             */
/*   Updated: 2024/10/15 18:36:21 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*a;

	a = s;
	while (n--)
	{
		*a++ = '\0';
	}
	return (s);
}
/*
#include <stdio.h>
int	main(void)
{
	char str[] = "Hola que tal";
	
	printf("Before bzero(): %s\n", str);
	ft_bzero(str + 1, 8);
     	printf("After bzero(): %s\n", str);
	return (0);
}*/
