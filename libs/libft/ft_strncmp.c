/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  xviladri < xviladri@student.42barcelona.c +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:37:20 by xviladri          #+#    #+#             */
/*   Updated: 2024/10/14 04:51:53 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (0);
	i = 0;
	while (i < (n - 1) && *s1 == *s2 && (*s1 || *s2))
	{
		s1++;
		s2++;
		i++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}
/*
int	main(void)
{
	char s1[] = "Hola";
	char s2[] = "Hala";
	size_t	n = 4;

	int	r = ft_strncmp(s1, s2, n);
	printf("%i\n", r);
	return (0);
}
*/
