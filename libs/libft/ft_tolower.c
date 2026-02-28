/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  xviladri < xviladri@student.42barcelona.c +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:46:29 by xviladri          #+#    #+#             */
/*   Updated: 2024/10/13 20:39:37 by  xviladri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
#include <ctype.h>
*/
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}
/*
int	main(void)
{
	int	c = 'B';
	printf("Antes: %c\n", c);
	printf("Despues: %c\n", ft_tolower(c));
	printf("Original: %c", tolower (c));
	return (0); 
}
*/
