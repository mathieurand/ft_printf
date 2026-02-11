/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:39:16 by tokyrand          #+#    #+#             */
/*   Updated: 2026/02/11 15:02:29 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned_int(unsigned int n)
{
	char	c;

	if (n == 0)
	{
		return(write(1, "0", 1));
	}
	if (n >= 10)
	{
		ft_put_unsigned_int(n / 10);
	}
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (count_n(n));
}