/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 14:30:16 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/23 15:49:01 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_space_plus_flag(char **str, char ch)
{
	char	*s;

	if (!ch)
		return ;
	if (**str == '-')
		return ;
	s = ft_strnew(ft_strlen(*str) + 1);
	ft_strcpy(s + 1, *str);
	s[0] = ch == ' ' ? ' ' : '+';
	ft_strdel(str);
	*str = s;
}

char		*ft_signed_int_flag(char *str, char *result, int field)
{
	char	*s;
	char	neg;
	char	*tmp;

	if ((s = ft_strchr(str, '+')) \
			|| (s = ft_strchr(str, ' ')))
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

void		ft_hash_flag(char **str, char ch)
{
	char	*s;

	s = ft_strnew(ft_strlen(*str) + (ch == 'o' ? 1 : 2));
	if (ch == 'o')
	{
		ft_strcpy(s + 1, *str);
		s[0] = '0';
	}
	else if (ch == 'x' || ch == 'X')
	{
		ft_strcpy(s + 2, *str);
		s[0] = '0';
		s[1] = ch == 'x' ? 'x' : 'X';
	}
	ft_strdel(str);
	*str = s;
}

char		*ft_unsigned_int_flag(char *str, char *result, int field)
{
	char	*s;
	int		len;
	char	neg;
	char	*tmp;
	int		iszero;

	len = ft_strlen(str);
	iszero = ft_strlen(result) == 1 && result[0] == '0';
	if (str[len - 1] != 'u' && !iszero && (s = ft_strchr(str, '#')))
		ft_hash_flag(&result, str[len - 1]);
	if (field <= ft_strlen(result))
		return (result);
	if (!(neg = ft_strchr(str, '-') ? '-' : 0))
		neg = ft_findzero(str) ? '0' : 0;
	tmp = ft_apply_field_width(result, field, neg);
	if (!iszero && neg == '0' && s && (str[len - 1] == 'x' || \
		str[len - 1] == 'X') && ((s = ft_strchr(tmp, 'x')) || \
			(s = ft_strchr(tmp, 'X'))))
	{
		*(tmp + 1) = *s;
		*s = '0';
	}
	return (tmp);
}

char		*ft_find_int_flag(char *str, va_list ap)
{
	int		count;
	int		len;
	char	*res;
	int		field;
	int		i;

	i = -1;
	len = ft_strlen(str);
	field = 0;
	while (++i < len - 1)
	{
		if (ft_isdigit(str[i]) && (i == 0 || !ft_isdigit(str[i - 1])))
			field = ft_atoi(str + i);
	}
	len = ft_strlen(str);
	if (!(count = ft_strcnt(str, 'l')) || \
			!(count = count > 2 ? 2 : count))
		count = ft_strcnt(str, 'h') > 2 ? -2 : ft_strcnt(str, 'h') * -1;
	res = ft_int_conv(str[len - 1], count, ap);
	if (str[len - 1] == 'd' || str[len - 1] == 'i')
		return (ft_signed_int_flag(str, res, field));
	else if (str[len - 1] == 'o' || str[len - 1] == 'u' || \
			str[len - 1] == 'x' || str[len - 1] == 'X')
		return (ft_unsigned_int_flag(str, res, field));
	return (0);
}
