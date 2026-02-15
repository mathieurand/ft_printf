/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:38:20 by tokyrand          #+#    #+#             */
/*   Updated: 2026/02/15 16:50:26 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_aff(const char *format, va_list copy, int *count, int i);

static int	ft_tohex(unsigned int n, char *base)
{
	int		count;

	count = 0;
	if (n >= 16)
		count += ft_tohex(n / 16, base);
	count += ft_putchar(base[n % 16]);
	return (count);
}

static int	ft_put_hex(unsigned int n, char c)
{
	int		count;
	char	base1[17];
	char	base2[17];

	ft_strlcpy(base1, "0123456789abcdef", 17);
	ft_strlcpy(base2, "0123456789ABCDEF", 17);
	count = 0;
	if (c == 'x')
		count += ft_tohex(n, base1);
	if (c == 'X')
		count += ft_tohex(n, base2);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	va_list	arg_copy;
	int		i;
	int		count;

	if (!format)
		return (-1);
	count = 0;
	i = 0;
	va_start(arg, format);
	va_copy(arg_copy, arg);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i ++;
			ft_aff(format, arg_copy, &count, i);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	return (count);
}

static void	ft_aff(const char *format, va_list arg_copy, int *count, int i)
{
	if (format[i] == 'c')
		(*count) += ft_putchar(va_arg(arg_copy, int));
	if (format[i] == 's')
		(*count) += ft_print_str(va_arg(arg_copy, char *));
	if (format[i] == 'd' || format[i] == 'i')
		(*count) += ft_putnbr(va_arg(arg_copy, int));
	if (format[i] == 'u')
		(*count) += ft_print_u(va_arg(arg_copy, unsigned int));
	if (format[i] == 'x')
		(*count) += ft_put_hex(va_arg(arg_copy, unsigned int), 'x');
	if (format[i] == 'X')
		(*count) += ft_put_hex(va_arg(arg_copy, unsigned int), 'X');
	if (format[i] == 'p')
		(*count) += ft_print_ptr(va_arg(arg_copy, void *));
	if (format[i] == '%')
		(*count) += ft_putchar('%');
}
