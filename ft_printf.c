/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:10:00 by abouchfa          #+#    #+#             */
/*   Updated: 2021/11/20 11:35:49 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_format(char format, va_list valist)
{
	if (format == 'c')
		ft_putchar(va_arg(valist, int));
	else if (format == 's')
		ft_putstr(va_arg(valist, char*));
	else if (format == 'd' || format == 'i')
		ft_putsnbr(va_arg(valist, int));
	else if (format == 'u')
		ft_putunbr(va_arg(valist, unsigned int));
	else if (format == 'x')
		ft_putnbrhex(va_arg(valist, unsigned long int), 1);
	else if (format == 'X')
		ft_putnbrhex(va_arg(valist, unsigned long int), 0);
	else if (format == '%')
		ft_putchar('%');
	else if (format == 'p')
	{
		counter += write (1, "0x", 2);
		ft_putnbrhex(va_arg(valist, unsigned long int), 1);
	}
}


int ft_printf(const char *str, ...)
{
	int		i;
	va_list valist;
	
	i = 0;
	va_start(valist, str);
	counter = 0;
	while (str[i])
	{
		if (str[i] == '%')
			print_format(str[++i], valist);
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(valist);
	return (counter);
}

// int main()
// {
// 	void *p1 = "Hello";
// 	void *p2 = "Hello";
// 	// char *s = NULL;
// 	int pc = printf("%p", p1);
// 	printf("\n");
// 	int fc = ft_printf("%p", p2);
// 	printf("\n");
// 	printf ("thier %d| mine %d", pc, fc);
// }