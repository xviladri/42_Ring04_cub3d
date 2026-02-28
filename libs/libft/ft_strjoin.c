/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  xviladri < xviladri@student.42barcelona.c +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:04:31 by xviladri          #+#    #+#             */
/*   Updated: 2024/10/13 20:57:29 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
#include <stdlib.h>
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	j = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	new = (char *)malloc((j + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}
/*
int	main(void)
{
	char	s1[] = "okfgnvokdfngvoida";
	char	s2[] = "que tal";
	char	*r = ft_strjoin(s1, s2);

	printf("%s\n", r);
	return (0);
}
*/
