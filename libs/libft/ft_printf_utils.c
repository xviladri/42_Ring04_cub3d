/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:34:20 by xviladri          #+#    #+#             */
/*   Updated: 2024/11/30 18:55:27 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchr(int c)
{
	int	count;

	count = 0;
	if (write(1, &c, 1) == -1)
		return (-1);
	count++;
	return (count);
}

int	ft_putstr(char *s)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (s[i])
	{
		count += ft_putchr((int)s[i]);
		i++;
	}
	return (count);
}

void	ft_putnbr(int n, int *count)
{
	char	nb;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*count += 11);
		return ;
	}
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return ;
		n = -n;
		(*count)++;
	}
	if (n > 9)
		ft_putnbr(n / 10, count);
	nb = (n % 10) + '0';
	write(1, &nb, 1);
	(*count)++;
}

void	ft_unsigned(unsigned int n, int *count)
{
	char	nb;

	if (n > 9)
		ft_unsigned(n / 10, count);
	nb = (n % 10) + '0';
	write(1, &nb, 1);
	(*count)++;
}
