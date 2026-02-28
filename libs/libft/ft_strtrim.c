/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  xviladri < xviladri@student.42barcelona.c +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:04:27 by xviladri          #+#    #+#             */
/*   Updated: 2024/10/16 19:00:18 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*new;
	size_t	k;

	if (!s1 || !set)
		return (0);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen((char *)s1) - 1;
	while (j >= i && ft_strchr(set, s1[j]))
		j--;
	new = (char *)malloc((j - i + 2) * sizeof(char));
	if (!new)
		return (NULL);
	k = 0;
	while (i <= j)
		new[k++] = s1[i++];
	new[k] = '\0';
	return (new);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	char const	s1[] = "acddddHola que talcabcdca";
	char const	set[] = "abcd";
	char	*r;

	r = ft_strtrim(s1, set);
	printf("%s\n", r);
	return (0);
}
*/
