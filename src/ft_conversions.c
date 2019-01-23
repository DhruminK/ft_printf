/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:08:50 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/23 17:42:39 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_isint(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || \
			c == 'X')
		return (1);
	return (0);
}

static int		ft_isvalid(char c)
{
	if (ft_isint(c) || c == 'c' || c == 's' || c == 'f' \
			|| c == '%' || c == 'p')
		return (1);
	if (c == 'h' || c == 'l' || c == 'L' || ft_isdigit(c) || c == '.' || \
			c == ' ' || c == '#' || c == '-' || c == '+' || c == '0')
		return (0);
	return (-1);
}

static char		*ft_find_flags(char *str, int *flag)
{
	int		ret;

	while (!(ret = ft_isvalid(*str)))
		str = str + 1;
	if (ret == -1)
		*flag = 0;
	else
		*flag = 1;
	return (str);
}

char			*ft_find_conv(char **str, va_list ap)
{
	char	*s;
	char	*end;
	int		flag;
	char	*tmp;

	flag = 0;
	end = ft_find_flags(*str, &flag);
	s = ft_strndup(*str, end - *str + 1);
	*str = end + (flag ? 1 : 0);
	if (!flag)
		return (0);
	if (ft_isint(*end))
		return (ft_find_int_flag(s, ap));
	if (*end == 'f')
		return (ft_find_float_flag(s, ap));
	if (*end == 's' || ((*end == 'c' || *end == '%') && \
				(tmp = ft_strnew(1)) && \
				(*tmp = *end == 'c' ? (char)va_arg(ap, int) : '%')))
		return (ft_flag_string(s, *end == 'c' || *end == '%' ? \
					tmp : va_arg(ap, char*)));
	if (*end == 'p')
		return (ft_flag_pointer(s, va_arg(ap, void*)));
	return (0);
}
