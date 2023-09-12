/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fweichse <fweichse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 23:51:23 by fweichse          #+#    #+#             */
/*   Updated: 2023/09/11 18:50:44 by fweichse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr(long long lnb, char *base, int b)
{
	char	digits[32];
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (lnb < 0)
	{
		len += write(1, "-", 1);
		lnb = -lnb;
	}
	while (lnb > 0)
	{
		digits[i++] = base[lnb % b];
		lnb /= b;
	}
	while (--i >= 0)
		len += write(1, digits + i, 1);
	return (len);
}

int	ft_putnbr(long long nb, char *base)
{
	if (nb == 0)
		return (write(1, base, 1));
	return (putnbr(nb, base, ft_strlen(base)));
}
