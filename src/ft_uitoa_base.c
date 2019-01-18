/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:48:22 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/18 16:04:20 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_findlen(unsigned long long num, int base)
{
	int		len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0 && (len = len + 1))
		num = num / base;
	return (len);
}

static void		ft_conv(char *str, unsigned long long num, int base, int len)
{
	char				*bs;
	int					ret;
	unsigned long long	value;

	value = num;
	bs = "0123456789ABCDEF";
	if (num == 0 && !(str[len] = 0))
		return ;
	while (num != 0)
	{
		ret = (num % base);
		str[len--] = bs[ret];
		num = num / base;
	}
}

char		*ft_itoa_base(unsigned long long num, int base)
{
	int		len;
	char	*str;

	if (base > 16 || base < 2)
		return (0);
	len = ft_findlen(num, base);
	if (!(str = ft_strnew(len)))
		return (0);
	str[len--] = 0;
	ft_conv(str, num, base, len);
	return (str);
}
