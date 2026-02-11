/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 08:09:22 by tokyrand          #+#    #+#             */
/*   Updated: 2026/02/11 15:02:13 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *f, ...);
void	ft_putnbr_base(unsigned long long nbr, char *base, int *count, int b);
int		ft_putnbr(int n);
void	ft_putstr(char *str, int *count);
int		ft_put_unsigned_int(unsigned int n);
void	ft_putchar(char c, int *count);
int		count_n(int n);

#endif
