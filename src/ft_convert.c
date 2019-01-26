/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:07:02 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/26 19:03:48 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_point_conv(int *arr, va_list ap)
{
	void	*p;
	long	num;
	char	*tmp;

	p = (void*)va_arg(ap, void*);
	num = (long)p - 0;
	tmp = ft_itoa_base(num, 16);
	ft_apply_precision(&tmp, arr[2], 0);
	ft_hash_flag(&tmp, 1);
	return (tmp);
}

static void		ft_handle_field_width(char **str, int *arr, char ch)
{
	char	*s;

	ft_apply_field_width(str, arr[1], (*arr & 0b100000) ? '-' : \
			(*arr & 0b1000000) ? '0' : 0);
	if ((*arr & 0b1000000) && (ch == 'x' || ch == 'X') && (*arr & 0b1000000000))
	{
		s = ft_strchr(*str, 'x');
		*((*str) + 1) = *s;
		*s = '0';
	}
	if ((*arr & 0b1000000) && (ch == 'd' || ch == 'i' || ch == 'f') && \
			((*arr & 0b100000000) || (*arr & 0b10000000)) && \
			((s = ft_strchr(*str, '-')) || \
			(s = ft_strchr(*str, '+')) || \
			(s = ft_strchr(*str, ' '))))
	{
		**str = *s;
		*s = '0';
	}
}

char			*ft_convert(char ch, int *arr, va_list ap)
{
	char	*tmp;

	if (ch == 's')
		tmp = ft_strdup(va_arg(ap, char*));
	if (ch == 'c')
	{
		if (!(tmp = ft_strnew(1)))
			return (0);
		*tmp = (char)va_arg(ap, int);
	}
	if (ch == 'd' || ch == 'i' || ch == 'o' || ch == 'u' || \
			ch == 'x' || ch == 'X')
		tmp = ft_int_conv(ch, arr, ap);
	if (ch == 'f')
		tmp = ft_float_conv(arr, ap);
	if (ch == 'p')
		tmp = ft_point_conv(arr, ap);
	ft_handle_field_width(&tmp, arr, ch);
	return (tmp);
}
