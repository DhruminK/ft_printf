/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:07:02 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/31 17:33:32 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_point_conv(int *arr, va_list ap)
{
	void	*p;
	long	num;
	char	*tmp;
	char	*s;

	p = (void*)va_arg(ap, void*);
	num = (long)p - 0;
	tmp = ft_itoa_base(num, 16);
	*arr = *arr | ft_flag_bin('#');
	ft_apply_precision(&tmp, arr[2], 0);
	if (!(s = ft_strnew(ft_strlen(tmp) + 2)))
		return (tmp);
	ft_strcpy(s + 2, tmp);
	*s = '0';
	*(s + 1) = 'X';
	ft_strdel(&tmp);
	tmp = s;
	ft_tolowercase(tmp);
	return (tmp);
}

static char		*ft_string_conv(char *ch, int *arr, va_list ap)
{
	char	*tmp;
	char	*val;
	char	c;

	tmp = 0;
	if (*ch == 's')
	{
		val = va_arg(ap, char*);
		if (!val)
			val = "(null)";
		if (arr[2] == -1 || !arr[2])
			tmp = arr[2] == -1 ? ft_strdup(val) : ft_strdup("");
		tmp = (arr[2] && arr[2] != -1) ? ft_strndup(val, arr[2]) : tmp;
	}
	else
	{
		c = *ch == 'c' ? va_arg(ap, int) : '%';
		if (!c && (*ch = '\''))
		{
			arr[1] = arr[1] == -1 ? arr[1] : arr[1] - 1;
			return (ft_strdup(""));
		}
		ft_addstr(&tmp, c, 0);
	}
	return (tmp);
}

static void		ft_handle_field_width(char **str, int *arr, char ch)
{
	char	*s;
	char	c;

	c = *arr & ft_flag_bin('-') ? '-' : 0;
	c = (!c) && (*arr & ft_flag_bin('0')) ? '0' : c;
	ft_apply_field_width(str, arr[1], c);
	if ((*arr & ft_flag_bin('0')) && (ch == 'x' || ch == 'X' || ch == 'p') && \
			(*arr & ft_flag_bin('#')) && ((s = ft_strchr(*str, 'x')) || \
					(s = ft_strchr(*str, 'X'))) && s != (*str) + 1)
	{
		*((*str) + 1) = *s;
		*s = '0';
	}
	if ((*arr & ft_flag_bin('0')) && (ch == 'd' || ch == 'i' || ch == 'f') && \
			((s = ft_strchr(*str, '-')) || \
			(((*arr & ft_flag_bin('+')) || (*arr & ft_flag_bin(' '))) && \
			((s = ft_strchr(*str, '+')) || \
			(s = ft_strchr(*str, ' '))))) && *str != s)
	{
		**str = *s;
		*s = '0';
	}
}

char			*ft_convert(char *c, int *arr, va_list ap)
{
	char	*tmp;
	char	ch;

	tmp = 0;
	ch = *c;
	if (arr[2] == -2)
		ft_addstr(&tmp, ch, 0);
	else if (ch == 's' || ch == 'c' || ch == '%')
		tmp = ft_string_conv(c, arr, ap);
	else if (ch == 'd' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'x' \
			|| ch == 'X' || ch == 'O' || ch == 'D' || ch == 'U')
		tmp = ft_int_conv(ch, arr, ap);
	else if (ch == 'f' || ch == 'F')
		tmp = ft_float_conv(arr, ap);
	else if (ch == 'p')
		tmp = ft_point_conv(arr, ap);
	if (!arr[2] && tmp[ft_strlen(tmp) - 1] == '0' && \
			!(ch == 'p' && (tmp = ft_strdup("0x"))))
	{
		ft_strdel(&tmp);
		tmp = (ch == 'o' && (*arr & ft_flag_bin('#'))) ? \
				ft_strdup("0") : ft_strdup("");
	}
	ft_handle_field_width(&tmp, arr, ch);
	return (tmp);
}
