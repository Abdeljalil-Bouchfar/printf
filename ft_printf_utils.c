/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:34:03 by abouchfa          #+#    #+#             */
/*   Updated: 2021/11/19 16:04:55 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *counter)
{
	counter += write(1, &c, 1);
}

void	ft_putstr(char *str, int *counter)
{
	ft_putchar(*str++, counter);
	if (*str)
		ft_putstr(str, counter);
}

void	ft_putsnbr(int nb, int *counter)
{
	unsigned int	unb;

	if (nb < 0)
	{
		ft_putchar('-', counter);
		unb = -nb;
	}
	else
		unb = nb;
	if (unb / 10)
		ft_putsnbr(unb / 10, counter);
	ft_putchar((unb % 10) + '0', counter);
}

void	ft_putunbr(unsigned int unb, int *counter)
{
	if (unb / 10)
		ft_putunbr(unb / 10, counter);
	ft_putchar((unb % 10) + '0', counter);
}

void	ft_putnbrhex(unsigned int nb, int lower, int *counter)
{
	char *hex;
	if (lower)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (nb < 16)
	{
		ft_putchar(hex[nb], counter);
		return ;
	}
	ft_putnbrhex(nb / 16, lower, counter);
	ft_putchar(hex[nb % 16], counter);
}