/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:46:17 by xviladri          #+#    #+#             */
/*   Updated: 2024/11/10 16:00:29 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero_1(void *s, size_t n)
{
	char	*i;

	i = s;
	while (n--)
		*i++ = '\0';
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*copy;

	copy = malloc(nmemb * size);
	if (!copy)
		return (NULL);
	ft_bzero_1(copy, nmemb * size);
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen_1((char *)s);
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

char	*ft_strjoin_1(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (s1);
		*s1 = '\0';
	}
	j = ft_strlen_1((char *)s1) + ft_strlen((char *)s2);
	new = (char *)malloc((j + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		new[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		new[i + j] = s2[j];
	free (s1);
	new[i + j] = '\0';
	return (new);
}

size_t	ft_strlen_1(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
