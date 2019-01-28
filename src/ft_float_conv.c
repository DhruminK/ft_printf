/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:05:36 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/28 20:01:36 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_float(double num, int precision)
{
	char	*str;
	char	ret;

	str = ft_itoa((long)num);
	num = num - (long)num;
	if (precision)
		ft_addstr(&str, '.', 0);
	while (precision-- > 0)
	{
		num = num * 10;
		ret = (char)num;
		ft_addstr(&str, (char)(ret + '0'), 0);
		num = num - ret;
	}
	return (str);
}

static char		*ft_lfloat(long double num, int precision)
{
	char	*str;
	char	ret;

	str = ft_itoa((long long)num);
	num = num - (long long)num;
	if (precision)
		ft_addstr(&str, '.', 0);
	while (precision-- > 0)
	{
		num = num * 10;
		ret = (char)num;
		ft_addstr(&str, (char)(ret + '0'), 0);
		num = num - ret;
	}
	return (str);
}

char			*ft_float_conv(int *arr, va_list ap)
{
	char	*tmp;
	int		pre;

	pre = arr[2] == -1 ? 6 : arr[2];
	tmp = !(arr[0] & ft_flag_bin('L')) ? \
		ft_float((double)va_arg(ap, double), pre) : \
		ft_lfloat((long double)va_arg(ap, long double), pre);
	if ((*arr & ft_flag_bin('+')) || (*arr & ft_flag_bin(' ')))
		ft_sign_flag(&tmp, *arr & ft_flag_bin('+') ? 1 : 0);
	if ((*arr & ft_flag_bin('#')) && !arr[2])
		ft_addstr(&tmp, '.', 0);
	return (tmp);
}
