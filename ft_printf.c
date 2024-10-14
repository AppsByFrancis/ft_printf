#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>
#include <limits.h>
#include "ft_printf.h"

int ft_putchar(char ch) {
    write(1, &ch, 1);
    return 1;
}

int ft_putnbr(long nb, int base) {
    int count = 0;
    char *symbols = "0123456789abcdef";
    if (nb < 0) {
        count += ft_putchar('-');
        nb = -nb;
    }
    if (nb >= base) {
        count += ft_putnbr(nb / base, base);
    }
    count += ft_putchar(symbols[nb % base]);
    return count;
}

int ft_putnbr_long(long long nb, int base) {
    int count = 0;
    char *symbols = "0123456789abcdef";
    if (nb < 0) {
        count += ft_putchar('-');
        nb = -nb;
    }
    if (nb >= base) {
        count += ft_putnbr_long(nb / base, base);
    }
    count += ft_putchar(symbols[nb % base]);
    return count;
}

char *ft_strchr(const char *str, int x) {
    char c;
    if (str == NULL)
        return (NULL);
    c = (char)x;
    while (*str && *str != c) {
        str++;
    }
    if (*str == c) {
        return ((char *)str);
    }
    return (NULL);
}

int ft_putnbr_hex(uintptr_t nb, char specifier) {
    int count = 0;
    char *symbols = "0123456789abcdef";
    if (nb >= 16) {
        count += ft_putnbr_hex(nb / 16, specifier);
    }
    if (specifier == 'X') {
        count += ft_putchar(symbols[nb % 16] - 32); // Convert to uppercase
    } else {
        count += ft_putchar(symbols[nb % 16]); // Lowercase
    }
    return count;
}

int ft_printstr(char *str) {
    int count = 0;
    if (str == NULL)
        str = "(null)";
    while (*str) {
        count += ft_putchar(*str);
        str++;
    }
    return count;
}

void ft_print_ptr(void *ptr) {
    uintptr_t address = (uintptr_t)ptr;
    ft_putchar('0');
    ft_putchar('x');
    ft_putnbr_hex(address, 'x');
}

int ft_print_arg(va_list args_p, const char **format) {
    int count = 0;
    if (**format == 'd' || **format == 'i')
    {
        count = ft_putnbr(va_arg(args_p, int), 10);
    } else if (**format == 'x')
    {
        count = ft_putnbr_hex(va_arg(args_p, unsigned int), 'x');
    } else if (**format == 'X')
    {
        count = ft_putnbr_hex(va_arg(args_p, unsigned int), 'X');
    } else if (**format == 'c')
    {
        count = ft_putchar((char)va_arg(args_p, int)); // char is promoted to int
    } else if (**format == 'u')
    {
        count = ft_putnbr(va_arg(args_p, unsigned int), 10);
    } else if (**format == 's')
    {
        count = ft_printstr(va_arg(args_p, char *));
    } else if (**format == 'p')
    {
        ft_print_ptr(va_arg(args_p, void *));
    }
    return count;
}

int ft_printf(const char *format, ...) {
    va_list args_p;
    va_start(args_p, format);
    int count = 0;

    while (*format) {
        if (*format == '%') {
            format++;
            if (*format == '%') {
                count += ft_putchar('%');
            } else if (ft_strchr("cspdiuxXl", *format)) {
                count += ft_print_arg(args_p, &format);
            }
        } else {
            count += ft_putchar(*format);
        }
        format++;
    }
    va_end(args_p);
    return count;
}

int main() {
    // ft_printf("Integer: %d, Hex: %x, Pointer: %p\n", 10, 10, &10);
    // ft_printf("Long: %ld, Unsigned Long: %lu\n", LONG_MAX, ULONG_MAX);
    // ft_printf("Long Long: %lld, Unsigned Long Long: %llu\n", LLONG_MAX, ULLONG_MAX);
    int a = ft_printf(" %c %d ", '2', 3);
    printf("%d", a);
    return 0;
}
