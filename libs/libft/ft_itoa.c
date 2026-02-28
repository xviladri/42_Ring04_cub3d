/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  xviladri < xviladri@student.42barcelona.c +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:46:16 by xviladri          #+#    #+#             */
/*   Updated: 2024/10/14 05:54:56 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(int num)
{
	int				i;

	i = 0;
	if (num <= 0)
		i++;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				len;
	unsigned int	p;
	char			*new;

	len = digit_count(n);
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	new[0] = '0';
	p = (unsigned int)n;
	if (n < 0)
	{
		new[0] = '-';
		p = -n;
	}
	new[len] = '\0';
	while (p > 0)
	{
		new[--len] = p % 10 + '0';
		p = p / 10;
	}
	return (new);
}
/*
int	main(void)
{
	int		n;
	char	*r;
	
	n = -9;
	r = ft_itoa(n);
	printf("%s", r);
	return (0);
}*/
