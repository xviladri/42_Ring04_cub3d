/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  xviladri < xviladri@student.42barcelona.c +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:08:33 by xviladri          #+#    #+#             */
/*   Updated: 2024/10/16 12:01:33 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (!d && !s)
		return (dest);
	while (n)
	{
		*d++ = *s++;
		n--;
	}
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
#include <unistd.h>
	char	src[] = "Adeu";
	char	dest[14] = "Hola que tal";
	void	*r;
	
	r = ft_memcpy(dest, src, 4*sizeof(char));
	printf("dest = %s\n", (char *)r);
	return (0);
}*/
