/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmajer <fmajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:01:49 by fmajer            #+#    #+#             */
/*   Updated: 2024/10/14 16:54:46 by fmajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char ch)
{
	write(1, &ch, 1);
	return (1);
}

int	ft_putnbr(long nb, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= base)
		count += ft_putnbr(nb / base, base);
	count += ft_putchar(symbols[nb % base]);
	return (count);
}

int	ft_putnbr_long(long long nb, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= base)
		count += ft_putnbr_long(nb / base, base);
	count += ft_putchar(symbols[nb % base]);
	return (count);
}

char	*ft_strchr(const char *str, int x)
{
	char	c;

	c = (char)x;
	if (str == NULL)
		return (NULL);
	while (*str && *str != c)
		str++;
	if (*str == c)
		return ((char *)str);
	return (NULL);
}

int	ft_putnbr_hex(uintptr_t nb, char specifier)
{
	int		count;
	char	*symbols;
	char	current_char;

	count = 0;
	symbols = "0123456789abcdef";
	current_char = symbols[nb % 16];
	if (nb >= 16)
		count += ft_putnbr_hex(nb / 16, specifier);
	if (specifier == 'X' && current_char >= 'a' && current_char <= 'z')
		count += ft_putchar(current_char - 32);
	else
		count += ft_putchar(current_char);
	return (count);
}
