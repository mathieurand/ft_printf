/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 10:45:25 by tokyrand          #+#    #+#             */
/*   Updated: 2026/02/15 17:26:50 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
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
