/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:10:00 by abouchfa          #+#    #+#             */
/*   Updated: 2021/11/26 17:53:23 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_format(char format, va_list valist)
{
	if (format == 'c')
		ft_putchar(va_arg(valist, int));
	else if (format == 's')
		ft_putstr(va_arg(valist, char *));
	else if (format == 'd' || format == 'i')
		ft_putsnbr(va_arg(valist, int));
	else if (format == 'u')
		ft_putunbr(va_arg(valist, unsigned int));
	else if (format == 'x' || format == 'X')
		ft_putnbrhex(va_arg(valist, unsigned int), format);
	else if (format == '%')
		ft_putchar('%');
	else if (format == 'p')
	{
		ft_putstr("0x");
		ft_putnbrhex(va_arg(valist, unsigned long int), 1);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	valist;

	va_start(valist, str);
	g_counter = 0;
	while (*str)
	{
		if (*str == '%')
			print_format(*++str, valist);
		else
			ft_putchar(*str);
		str++;
	}
	va_end(valist);
	return (g_counter);
}
