/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:09:29 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/23 16:54:20 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_float_flag(char *str, char *result, int field, int precision)
{
	char	*tmp;
	char	neg;
	char	*s;

	if (precision == 0 && ft_strchr(str, '#'))
		ft_addback(&result, '.');
	if ((s = ft_strchr(str, '+')) || \
			(s = ft_strchr(str, ' ')))
		ft_space_plus_flag(&result, *s);
	if (field <= ft_strlen(result))
		return (result);
	if (!(neg = ft_strchr(str, '-') ? '-' : 0))
		neg = ft_findzero(str) ? '0' : 0;
	tmp = ft_apply_field_width(result, field, neg);
	if (neg == '0' && (s || ft_strchr(result, '-')) && \
			((s = ft_strchr(tmp, '+')) || \
			 (s = ft_strchr(tmp, '-')) || \
			 (s = ft_strchr(tmp, ' '))))
	{
		*tmp = *s;
		*s = '0';
	}
	return (tmp);
}

char			*ft_find_float_flag(char *str, va_list ap)
{
	int		precision;
	char	*res;
	int		field;
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(str);
	field = 0;
	precision = 6;
	while (++i < len - 1)
	{
		if (ft_isdigit(str[i]) && (i == 0 || \
					(!ft_isdigit(str[i - 1]) && str[i - 1] != '.')))
			field = ft_atoi(str + i);
		else if (i != 0 && ft_isdigit(str[i]) && str[i - 1] == '.')
			precision = ft_atoi(str + i);
	}
	if ((i = 0) || ft_strchr(str, 'L'))
		i = 1;
	res = ft_float_conv(i, precision, ap);
	return (ft_float_flag(str, res, field, precision));
}
