#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int counter;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbrhex(unsigned long int nb, int lower);
void	ft_putsnbr(int nb);
void	ft_putunbr(unsigned int unb);

#endif