/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Micampil <micampil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:09:48 by Micampil          #+#    #+#             */
/*   Updated: 2025/05/15 17:16:46 by Micampil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_process_format(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (specifier == 'p')
		count += ft_print_ptr(va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (specifier == 'x')
		count += ft_putnbr_hex(va_arg(args, unsigned int), 0);
	else if (specifier == 'X')
		count += ft_putnbr_hex(va_arg(args, unsigned int), 1);
	else if (specifier == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += ft_process_format(format[i + 1], args);
			i++;
		}
		else if (format[i] != '%')
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
