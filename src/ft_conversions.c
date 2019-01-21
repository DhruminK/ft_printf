/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:08:50 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/21 17:00:57 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_isint(char c)
{
	if (c == 'd' || c == 'i' || c =='o' || c == 'u' || c == 'x' || \
			c == 'X')
		return (1);
	return (0);
}

static int		ft_isvalid(char c)
{
	if (ft_isint(c) || c == 'c' || c == 's' || c == 'f')
		return (1);
	if (c == 'h' || c == 'l')
		return (0);
	return (-1);
}

static char		*ft_find_flags(char *str, int **flag)
{
	int		flags;
	int		ret;

	flags = 0;
	while (!(ret = ft_isvalid(*str)))
	{
		if (*str == 'h' && flags <= 0 && flags > -2)
			flags = flags - 1;
		else if (*str == 'l' && flags >= 0 && flags < 2)
			flags = flags + 1;
		str = str + 1;
	}
	if (ret == -1)
		*flag = 0;
	else
		**flag = flags;
	return (str);
}

char			*ft_find_conv(char **str, va_list ap)
{
	char	*end;
	int		flag;
	int		*fpt;
	char	*cflags;

	flag = 0;
	cflags = 0;
	fpt = &flag;
	end = ft_find_flags(*str, &fpt);
	*str = end + (fpt ? 1 : 0);
	if (!fpt)
		return (0);
	if (ft_isint(*end))
		return (ft_int_conv(*end, flag, ap));
	if (*end == 'f')
		return (ft_float_conv(flag, ap));
	if (*end == 's')
		return (va_arg(ap, char *));
	if (*end == 'c' && (end = ft_strnew(1)) && \
			(*end = (char)va_arg(ap, int)))
		return (end);
	return (0);
}
