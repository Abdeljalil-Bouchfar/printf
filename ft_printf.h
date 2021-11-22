/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:25:19 by abouchfa          #+#    #+#             */
/*   Updated: 2021/11/22 19:25:26 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	g_counter;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbrhex(unsigned long int nb, int lower);
void	ft_putsnbr(int nb);
void	ft_putunbr(unsigned int unb);

#endif