/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:37:40 by tokyrand          #+#    #+#             */
/*   Updated: 2026/02/11 15:04:01 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	c;
	int		sign;

	sign = 0;
	if (n == -2147483648)
	{
		return(write(1, "-2147483648", 11));
	}
	else if (n == 0)
	{
		return(write(1, "0", 1));
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		sign = 1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (count_n(n) + sign);
}