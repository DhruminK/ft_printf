/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:38:48 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/23 15:47:49 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_findlen(long long num, int base)
{
	int		len;

	len = num < 0 ? 1 : 0;
	if (num == 0)
		return (1);
	while (num != 0 && (len = len + 1))
		num = num / base;
	return (len);
}

static void		ft_conv(char *str, long long num, int base, int len)
{
	char		*bs;
	int			ret;
	long long	value;

	bs = "0123456789ABCDEF";
	value = num;
	if (num == 0 && !(str[len] = 0))
		return ;
	while (num != 0)
	{
		ret = (num % base) * (value < 0 ? -1 : 1);
		str[len--] = bs[ret];
		num = num / base;
	}
}

char			*ft_itoa(long long num)
{
	int		len;
	char	*str;

	len = ft_findlen(num, 10);
	if (!(str = ft_strnew(len)))
		return (0);
	str[len--] = 0;
	ft_conv(str, num, 10, len);
	str[0] = num < 0 ? '-' : str[0];
	return (str);
}
