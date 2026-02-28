/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  xviladri < xviladri@student.42barcelona.c +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:36:42 by xviladri          #+#    #+#             */
/*   Updated: 2024/10/15 20:25:53 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*a;

	a = s;
	while (n--)
	{
		*a++ = c;
	}
	return (s);
}
/*
#include <stdio.h>
int	main(void)
{
	char str[] = "Hola";
	printf("\nBefore memset(): %s\n", str);
	
	ft_memset(str + 2, 'o', 2*sizeof(char));
	printf("After memset():  %s\n", str);
	return (0);
}*/
