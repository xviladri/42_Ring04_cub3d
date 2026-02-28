/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  xviladri < xviladri@student.42barcelona.c +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:07:39 by xviladri          #+#    #+#             */
/*   Updated: 2024/10/16 12:57:11 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen((char *)s);
	if (c == '\0')
		return ((char *)&s[len]);
	while (s[i] != '\0')
	{
		if (s[i] != ((unsigned char) c))
			i++;
		else
			return ((char *) &s[i]);
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char str[] = "Hol,a qu,e tal  ,   como,";
	int	c = 'o';
	char	*r;

	r = ft_strchr(str, c);
//	r = strchr(str, c);
	printf("%s\n", r);
	return (0);
}
*/
