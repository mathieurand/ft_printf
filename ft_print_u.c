/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 08:28:06 by tokyrand          #+#    #+#             */
/*   Updated: 2026/02/15 16:38:06 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(unsigned long u)
{
	int				count;
	unsigned int	nb;

	nb = (unsigned int)u;
	count = 0;
	if (nb > 9)
		count += ft_print_u(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}
