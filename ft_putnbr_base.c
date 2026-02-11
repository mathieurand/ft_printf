/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:33:11 by tokyrand          #+#    #+#             */
/*   Updated: 2026/02/10 00:24:34 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long long nbr, char *base, int *count, int b)
{
	if (nbr >= (unsigned long long)b)
		ft_putnbr_base(nbr / b, base, count, b);
	ft_putchar(base[nbr % b], count);
}
