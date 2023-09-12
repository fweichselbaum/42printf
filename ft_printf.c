/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fweichse <fweichse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:03:09 by fweichse          #+#    #+#             */
/*   Updated: 2023/09/11 18:21:59 by fweichse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_args(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int), "0123456789"));
	else if (c == 'u')
		return (ft_putnbr(va_arg(args, unsigned int), "0123456789"));
	else if (c == 'x')
		return (ft_putnbr(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (c == '%' || c == '\0')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		bytes;

	bytes = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			bytes += handle_args(*format, args);
		}
		else
			bytes += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (bytes);
}
