/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 08:02:11 by tokyrand          #+#    #+#             */
/*   Updated: 2026/02/15 16:39:17 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	const char	*t;

	t = str;
	while (*t)
		t++;
	return ((size_t)(t - str));
}

int	ft_putchar(char c)
{
	int	count;

	count = 1;
	write(1, &c, 1);
	return (count);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;

	if (!s)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	count_int(int n)
{
	int		len;

	len = 0;
	while (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr_base(unsigned long long nbr, char *base, int *count, int b)
{
	if (nbr >= (unsigned long long)b)
		ft_putnbr_base(nbr / b, base, count, b);
	(*count) += ft_putchar(base[nbr % b]);
}
