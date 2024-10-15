/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmajer <fmajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:02:35 by fmajer            #+#    #+#             */
/*   Updated: 2024/10/15 14:14:48 by fmajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
int		ft_printstr(char *str);
int		ft_print_ptr(size_t ptr);
int		ft_print_arg(va_list args_p, const char **format);
int		ft_putchar(char ch);
int		ft_putnbr(long nb, int base);
int		ft_putnbr_long(long long nb, int base);
char	*ft_strchr(const char *str, int x);
int		ft_putnbr_hex(uintptr_t nb, char specifier);

#endif