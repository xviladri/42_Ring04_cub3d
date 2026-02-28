/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  xviladri < xviladri@student.42barcelona.c +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:32:42 by xviladri          #+#    #+#             */
/*   Updated: 2024/10/13 20:57:18 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	a_toupper(unsigned int i, char *s)
{
	if (*s >= 'a' && *s <= 'z')
		*s = *s - 32;
}

int	main(void)
{
	char	s[] = "Hola que tal";
	ft_striteri(s, a_toupper);
	printf("%s\n", s);
	return (0);
}
*/
