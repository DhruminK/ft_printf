/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:17:47 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/28 20:04:21 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				ft_hash_flag(char **str, int hex)
{
	char	*s;

	if (ft_strlen(*str) == 1 && **str == '0')
		return ;
	if (!(s = ft_strnew(ft_strlen(*str) + (hex ? 2 : 1))))
		return ;
	ft_strcpy(s + (hex ? 2 : 1), *str);
	*s = '0';
	*(s + 1) = hex ? 'X' : *(s + 1);
	ft_strdel(str);
	*str = s;
}

void				ft_sign_flag(char **str, int sign)
{
	char	*s;

	if (**str == '-')
		return ;
	if (!(s = ft_strnew(ft_strlen(*str) + 1)))
		return ;
	ft_strcpy(s + 1, *str);
	*s = sign ? '+' : ' ';
	ft_strdel(str);
	*str = s;
}

static char			*ft_conv(int arr, int sign, int base, va_list ap)
{
	int		i;

	i = 0b1000;
	if (arr & i)
		return (sign ? ft_itoa((long long)va_arg(ap, long long)) : \
				ft_itoa_base((unsigned long long)va_arg(ap, \
						unsigned long long), base));
	if (arr & (i >> 1))
		return (sign ? ft_itoa((long)va_arg(ap, long)) : \
				ft_itoa_base((unsigned long)va_arg(ap, unsigned long), base));
	if (arr & (i >> 2))
		return (sign ? ft_itoa((signed char)va_arg(ap, int)) : \
				ft_itoa_base((unsigned char)va_arg(ap, int), base));
	if (arr & (i >> 3))
		return (sign ? ft_itoa((short)va_arg(ap, int)) : \
				ft_itoa_base((unsigned short)va_arg(ap, int), base));
	return (sign ? ft_itoa((int)va_arg(ap, int)) : \
			ft_itoa_base((unsigned int)va_arg(ap, unsigned int), base));
}

char				*ft_int_conv(char ch, int *arr, va_list ap)
{
	char	*tmp;

	if (arr[2] != -1)
		*arr = *arr & (~ft_flag_bin('0'));
	if ((ch == 'x' || ch == 'X' || ch == 'o'))
		tmp = ft_conv(arr[0], 0, ch == 'o' ? 8 : 16, ap);
	else
		tmp = ft_conv(arr[0], ch == 'u' ? 0 : 1, 10, ap);
	if (*tmp == '-')
	{
		ft_delfront(&tmp);
		ft_apply_precision(&tmp, arr[2], 0);
		ft_addstr(&tmp, '-', 1);
	}
	else
		ft_apply_precision(&tmp, arr[2], 0);
	if ((ch == 'o' || ch == 'x' || ch == 'X') && (*arr & ft_flag_bin('#')))
		ft_hash_flag(&tmp, ch == 'o' ? 0 : 1);
	else if ((ch == 'd' || ch == 'i') && ((*arr & ft_flag_bin('+')) || \
				(*arr & ft_flag_bin(' '))))
		ft_sign_flag(&tmp, *arr & ft_flag_bin('+') ? 1 : 0);
	if (ch == 'x')
		ft_tolowercase(tmp);
	return (tmp);
}
