/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  xviladri < xviladri@student.42barcelona.c +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:03:28 by xviladri          #+#    #+#             */
/*   Updated: 2024/10/16 12:40:19 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	length;

	i = 0;
	length = 0;
	while (src[length])
		length++;
	if (size == 0)
		return (length);
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (length);
}
/*
#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	size_t	i;
	size_t  y;
	char	src[]= "Hola mundo!";
	char	dest[] = "";

	i = ft_strlcpy(dest, src, 30);
//	y = strlcpy(dest, src, 30);
	printf("New string: %s\n", dest);	
	printf("Size: %zu\n", i);
//	printf("Size: %zu\n", y);
	return (0);
}
*/
