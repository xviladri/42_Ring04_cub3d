/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  xviladri < xviladri@student.42barcelona.c +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:43:04 by xviladri          #+#    #+#             */
/*   Updated: 2024/10/13 20:58:21 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
#include <stdlib.h>
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;
	size_t	len;

	len = ft_strlen((char *)s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (!s || !f)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*

char	a_toupper(unsigned int i, char s)
{
	if (s >= 'a' && s <= 'z')
		s = s - 32;
		return (s);	
}

int	main(void)
{
	char	const s[] = "Hola que tal";
	char *r = ft_strmapi(s, a_toupper); 
	printf("%s\n", r);
	return (0);
}
*/
