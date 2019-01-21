/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:17:49 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/21 17:31:03 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_addback(char **str, char ch)
{
	char *tmp;
	char *dup;

	dup = ft_strnew(2);
	dup[0] = ch;
	tmp = ft_strjoin(*str, dup);
	ft_strdel(&dup);
	ft_strdel(str);
	*str = tmp;
}

static char		*ft_float(long double num, int percision)
{
	long long	num_int;
	char		*str;

	num_int = (long long)num;
	str = ft_itoa(num_int);
	if (percision == 0)
		return (str);
	ft_addback(&str, '.');
	num = num < 0 ? num * -1 : num;
	num_int = num_int < 0 ? num_int * -1 : num;
	num = num - num_int;
	while (percision-- > 0)
	{
		num = num * 10;
		num_int = num;
		ft_addback(&str, (int)num_int + '0');
		num = num - num_int;
	}
	return (str);
}

char			*ft_float_conv(int flag, va_list ap)
{
	if (!flag)
		return (ft_float(va_arg(ap, double), 6));
	if (flag > 0)
		return (ft_float(va_arg(ap, long double), 6));
	return (0);
}
