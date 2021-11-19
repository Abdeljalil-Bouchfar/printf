#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

void	ft_putchar(char c, int *counter);
void	ft_putstr(char *str, int *counter);
void	ft_putnbrhex(unsigned int nb, int lower, int *counter);
void	ft_putsnbr(int nb, int *counter);
void	ft_putunbr(unsigned int unb, int *counter);

#endif