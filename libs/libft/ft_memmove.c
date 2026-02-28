/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  xviladri < xviladri@student.42barcelona.c +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:33:45 by xviladri          #+#    #+#             */
/*   Updated: 2024/10/16 12:03:07 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*destiny;
	unsigned const char	*source;

	destiny = dest;
	source = src;
	if (source < destiny)
	{
		i = n;
		while (i > 0)
		{
			i--;
			destiny[i] = source[i];
		}
	}
	else if (destiny < source)
	{
		i = 0;
		while (i < n)
		{
			destiny[i] = source[i];
			i++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	char	src[100] = "Hola que tal";
	char	*dest = src; 

	ft_memmove(dest + 4, dest, 20);
//	memmove(dest + 4, dest, 20); // original  
	write(1, &src, 25);
	write(1, "\n", 1); 
	return (0);
}*/
