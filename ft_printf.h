/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fweichse <fweichse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:03:43 by fweichse          #+#    #+#             */
/*   Updated: 2023/09/11 17:59:33 by fweichse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

int	ft_strlen(char *str);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(long long nb, char *base);
int	ft_putptr(void *ptr);

#endif
