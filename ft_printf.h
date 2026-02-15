/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:39:32 by tokyrand          #+#    #+#             */
/*   Updated: 2026/02/15 17:24:24 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_printf(const char *format, ...)__attribute__((format(printf, 1, 2)));
int		ft_print_ptr(void *ptr);
int		ft_print_str(char *str);
int		ft_print_u(unsigned long u);
int		ft_putnbr(int n);
int		ft_putchar(char c);
size_t	ft_strlen(const char *str);
int		count_int(int n);
void	ft_putnbr_base(unsigned long long nbr, char *base, int *count, int b);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif