/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:55:47 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/23 15:42:08 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_call_func(va_list ap, int flag)
{
	if (!flag)
		return (ft_itoa(va_arg(ap, int)));
	if (flag == -1)
		return (ft_itoa((short)va_arg(ap, int)));
	if (flag == -2)
		return (ft_itoa((signed char)va_arg(ap, int)));
	if (flag == 1)
		return (ft_itoa(va_arg(ap, long)));
	if (flag == 2)
		return (ft_itoa(va_arg(ap, long long)));
	return (0);
}

static char		*ft_call_ufunc(va_list ap, int flag, int base)
{
	if (!flag)
		return (ft_itoa_base(va_arg(ap, unsigned int), base));
	if (flag == -1)
		return (ft_itoa_base((unsigned short)va_arg(ap, int), base));
	if (flag == -2)
		return (ft_itoa_base((unsigned char)va_arg(ap, int), base));
	if (flag == 1)
		return (ft_itoa_base(va_arg(ap, unsigned long), base));
	if (flag == 2)
		return (ft_itoa_base(va_arg(ap, unsigned long long), base));
	return (0);
}

char			*ft_int_conv(char ch, int flag, va_list ap)
{
	char	*s;

	if (ch == 'd' || ch == 'i')
		return (ft_call_func(ap, flag));
	if (ch == 'x' || ch == 'X')
	{
		s = ft_call_ufunc(ap, flag, 16);
		if (ch == 'x')
			ft_tolowercase(s);
		return (s);
	}
	if (ch == 'o')
		return (ft_call_ufunc(ap, flag, 8));
	if (ch == 'u')
		return (ft_call_ufunc(ap, flag, 10));
	return (0);
}
