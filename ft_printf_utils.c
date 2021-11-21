/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:34:03 by abouchfa          #+#    #+#             */
/*   Updated: 2021/11/20 11:32:54 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	if (write(1, &c, 1) == 1)
		counter++;
}

void	ft_putstr(char *str)
{
	char *null;

	null  = "(null)";
	if (str)
	{
		if (*str)
		{
			ft_putchar(*str);
			ft_putstr(++str);
		}
	}
	else
		ft_putstr(null);
}

void	ft_putsnbr(int nb)
{
	unsigned int	unb;

	if (nb < 0)
	{
		ft_putchar('-');
		unb = -nb;
	}
	else
		unb = nb;
	if (unb / 10)
		ft_putsnbr(unb / 10);
	ft_putchar((unb % 10) + '0');
}

void	ft_putunbr(unsigned int unb)
{
	if (unb / 10)
		ft_putunbr(unb / 10);
	ft_putchar((unb % 10) + '0');
}

void	ft_putnbrhex(unsigned long int nb, int lower)
{
	char *hex;
	if (lower)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (nb < 16)
	{
		ft_putchar(hex[nb]);
		return ;
	}
	ft_putnbrhex(nb / 16, lower);
	ft_putchar(hex[nb % 16]);
}