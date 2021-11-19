all:
	@gcc -c ft_printf_utils.c
	@gcc ft_printf.c ft_printf_utils.o
	./a.out
fclean:
	@rm -f a.out
	@rm -f *.o

re: fclean all