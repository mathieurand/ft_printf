
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 08:25:51 by tokyrand          #+#    #+#             */
/*   Updated: 2026/02/08 08:26:46 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_print_X_or_x(int X, int choice)
{
	int		count;

	count = 0;
	if (choice == 1)
		ft_putnbr_base(X, "0123456789ABCDEF", &count, 16);
	if (choice == 2)
		ft_putnbr_base(X, "0123456789abcdef", &count, 16);
	return (count);
}
static int ft_print_ptr(void *ptr)
{
	int		count;

	if (!ptr)
		return (write(1, "(nil)", 5));
	count = 0;
	write(1, "0x", 2);
	count += 2;
	ft_putnbr_base((uintptr_t)ptr, "0123456789abcdef", &count, 16);
	return (count);
}

static void ft_aff_cent(va_list arg_copy, const char *f, int *count, int i)
{
	if (f[i] == 's')
	{	
		ft_putstr(va_arg(arg_copy, char *), count);
	}
	if (f[i] == 'd' || f[i] == 'i')
		(*count) += ft_putnbr(va_arg(arg_copy, int));
	if (f[i] == 'c')
		ft_putchar(va_arg(arg_copy, int), count);
	if (f[i] == 'u')
		(*count) += ft_put_unsigned_int(va_arg(arg_copy, unsigned int));
	if (f[i] == '%')
		ft_putchar(f[i], count);
	if (f[i] == 'p')
		(*count) += ft_print_ptr(va_arg(arg_copy, void *));
	if (f[i] == 'x')
		(*count) += ft_print_X_or_x(va_arg(arg_copy, int), 2);
	if (f[i] == 'X')
		(*count) += ft_print_X_or_x(va_arg(arg_copy, int), 1);
}

int	ft_printf(const char *f, ...)
{
	va_list	arg;
	va_list	arg_copy;
	int		count;
	int		i;

	if (!f)
		return (-1);
	va_start(arg, f);
	va_copy(arg_copy, arg);
	count = 0;
	i = 0;
	while (f[i])
	{
		if (f[i] == '%' && f[i + 1])
		{
			i++;
			ft_aff_cent(arg_copy, f, &count, i);
		}
		else if (f[i])
			ft_putchar(f[i], &count);
		i++;
	}
	va_end(arg_copy);
	va_end(arg);
	return (count);
}
#include <stdio.h>
#include "ft_printf.h"
#include <stdlib.h>

int main(void)
{
	ft_printf("\n%d",ft_printf("%u", -1));
	return (0);
}

