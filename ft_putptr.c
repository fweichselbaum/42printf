/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fweichse <fweichse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:14:00 by fweichse          #+#    #+#             */
/*   Updated: 2023/09/11 18:50:06 by fweichse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putptr(unsigned long long lnb, char *base, int b)
{
	char	digits[100];
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (lnb > 0)
	{
		digits[i++] = base[lnb % b];
		lnb /= b;
	}
	while (--i >= 0)
		len += write(1, digits + i, 1);
	return (len);
}

int	ft_putptr(void *ptr)
{
	unsigned long long	lptr;
	int					len;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	lptr = (unsigned long long)ptr;
	len = 0;
	len += write(1, "0x", 2);
	len += putptr(lptr, "0123456789abcdef", 16);
	return (len);
}
