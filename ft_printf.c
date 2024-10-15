/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmajer <fmajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:40:57 by fmajer            #+#    #+#             */
/*   Updated: 2024/10/15 14:12:38 by fmajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}

int	ft_print_ptr(size_t ptr)
{
	char	str[17];
	int		i;
	char	*base;
	int		count;

	base = "0123456789abcdef";
	i = 0;
	count = 0;
	if (ptr == 0)
	{
		count = ft_printstr("(nil)");
		return (count);
	}
	count = ft_printstr("0x");
	while (ptr)
	{
		str[i] = base[ptr % 16];
		ptr /= 16;
		i++;
	}
	while (i--)
		count += ft_putchar(str[i]);
	return (count);
}

int	ft_print_arg(va_list args_p, const char **format)
{
	int	count;

	count = 0;
	if (**format == 'd' || **format == 'i')
		count = ft_putnbr(va_arg(args_p, int), 10);
	else if (**format == 'x')
		count = ft_putnbr_hex(va_arg(args_p, unsigned int), 'x');
	else if (**format == 'X')
		count = ft_putnbr_hex(va_arg(args_p, unsigned int), 'X');
	else if (**format == 'c')
		count = ft_putchar((char)va_arg(args_p, int));
	else if (**format == 'u')
		count = ft_putnbr(va_arg(args_p, unsigned int), 10);
	else if (**format == 's')
		count = ft_printstr(va_arg(args_p, char *));
	else if (**format == 'p')
		count = ft_print_ptr(va_arg(args_p, size_t));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args_p;
	int		count;

	count = 0;
	va_start(args_p, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				count += ft_putchar('%');
			else if (ft_strchr("cspdiuxXl", *format))
				count += ft_print_arg(args_p, &format);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args_p);
	return (count);
}
