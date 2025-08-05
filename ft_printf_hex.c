/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Micampil <micampil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:12:30 by Micampil          #+#    #+#             */
/*   Updated: 2025/05/15 16:02:08 by Micampil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_hex(unsigned long n, int uppercase)
{
	int		count;
	char	*hex;

	count = 0;
	if (uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_putnbr_hex(n / 16, uppercase);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_putnbr_hex((unsigned long)ptr, 0);
	return (count);
}
