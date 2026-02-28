/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:38:50 by xviladri          #+#    #+#             */
/*   Updated: 2024/11/30 19:39:43 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
			count += conditionals(str[++i], args);
		else if (str[i])
		{
			if (str[i] == '%')
				return (-1);
			ft_putchr(str[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int	conditionals(char str, va_list args)
{
	int	count;

	count = 0;
	if (str == 'c')
		count += ft_putchr(va_arg(args, int));
	else if (str == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (str == 'p')
		count += ft_putpointer(va_arg(args, size_t));
	else if (str == 'd')
		ft_putnbr(va_arg(args, int), &count);
	else if (str == 'i')
		ft_putnbr(va_arg(args, int), &count);
	else if (str == 'u')
		ft_unsigned(va_arg(args, unsigned int), &count);
	else if (str == 'x')
		count += ft_hexadecimal(va_arg(args, unsigned int), "0123456789abcdef");
	else if (str == 'X')
		count += ft_hexadecimal(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (str == '%')
		count += ft_putchr((int)str);
	return (count);
}

int	ft_putpointer(size_t str)
{
	int	count;

	if (!str || str == 0)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	count = 2;
	count += ft_hexadecimal(str, "0123456789abcdef");
	return (count);
}

int	ft_hexadecimal(size_t str, char *base)
{
	int	count;		

	count = 0;
	if (str < 16)
		count += ft_putchr(base[str]);
	if (str >= 16)
	{
		count += ft_hexadecimal(str / 16, base);
		count += ft_hexadecimal(str % 16, base);
	}
	return (count);
}
/*
int	main(void)
{
	int	m;
	int	o;

	m = ft_printf("hola mundo %s\n %%", "que tal");
	ft_printf("%i\n", m);
	o = printf("hola mundo %s\n %%", "que tal");
	printf("%i\n", o);
}*/
