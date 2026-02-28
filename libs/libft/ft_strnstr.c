/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  xviladri < xviladri@student.42barcelona.c +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:12:11 by xviladri          #+#    #+#             */
/*   Updated: 2024/10/14 05:05:38 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n;

	if (!big)
		return (0);
	if (*little == '\0')
		return ((char *)big);
	i = 0;
	n = ft_strlen(little);
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] == big[i + j] && (i + j) < len)
		{
			j++;
			if (n == j)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
    char big[] = "que hola tal";
    char little[] = "hola";
    size_t n = 10;
    char *ptr = ft_strnstr(big, little, n); 

    printf("%s\n", ptr);
    return 0;
}
*/
