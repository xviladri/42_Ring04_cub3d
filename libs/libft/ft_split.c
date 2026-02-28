/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  xviladri < xviladri@student.42barcelona.c +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:24:05 by xviladri          #+#    #+#             */
/*   Updated: 2024/10/13 20:45:54 by  xviladri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static int	count_words(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static char	*get_next_word(char const **s, char c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)*s;
	while (str[i] && str[i] != c)
		i++;
	*s += i;
	return (ft_substr(str, 0, i));
}

char	**ft_split(char const *s, char c)
{
	int		j;
	char	**new;
	int		y;

	y = 0;
	j = count_words((char *)s, c);
	new = (char **)malloc((j + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	while (*s != '\0')
	{
		if (*s != c)
		{
			new[y] = get_next_word(&s, c);
			if (!new[y++])
			{
				free_array(new);
				return (NULL);
			}
		}
		else
			s++;
	}
	new[y] = NULL;
	return (new);
}
/*
int	main(void)
{
	char	str[];
	char	c;
	char	**res;
	int		i;

	str[] = "     hola  que  tal";
	c = ' ';
	res = ft_split(str, c);
	i = 0;
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
	free_array(res);
	return (0);
}
*/
