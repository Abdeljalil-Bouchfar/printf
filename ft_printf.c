/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:10:00 by abouchfa          #+#    #+#             */
/*   Updated: 2021/11/19 16:06:02 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_format(char format, va_list valist, int *counter)
{
	if (format == 'c')
		ft_putchar(va_arg(valist, int), counter);
	else if (format == 's')
		ft_putstr(va_arg(valist, char*), counter);
	else if (format == 'd' || format == 'i')
		ft_putsnbr(va_arg(valist, int), counter);
	else if (format == 'u')
		ft_putunbr(va_arg(valist, unsigned int), counter);
	else if (format == 'x')
		ft_putnbrhex(va_arg(valist, unsigned int), 1, counter);
	else if (format == 'X')
		ft_putnbrhex(va_arg(valist, unsigned int), 0, counter);
	else if (format == '%')
		write(1, "%", 1);
	else if (format == 'p')
	{
		write (1, "0x10", 4);
		ft_putnbrhex(va_arg(valist, unsigned int), 1, counter);
	}
}


int ft_printf(const char *str, ...)
{
	int		i;
	int		counter;
	va_list valist;
	
	counter = 0;
	i = 0;
	va_start(valist, str);
	while (str[i])
	{
		if (str[i] == '%')
			print_format(str[++i], valist, &counter);
		else
			ft_putchar(str[i], &counter);
		i++;
	}
	va_end(valist);
	return 0;
}

int main(int ac, char **av)
{
	void *p = "Hello";
	void *p2 = "Hello";
	int pc = printf("test %u", -10);
	printf("\n");
	int fc = ft_printf("test %u", -10);
	printf("\n");
	printf ("p %d, f %d", pc, fc);
}