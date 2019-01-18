/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:56:07 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/18 16:43:27 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_putstrwrapper(char *str)
{
	int		len;

	len = ft_strlen(str);
	ft_putstr(str);
	return (len);
}

int				ft_printf(const char *val, ...)
{
	va_list		ap;
	int			count;
	int			len;
	char		*str;
	char		*tmp;

	va_start(ap, val);
	len = 0;
	str = ft_strdup(val);
	while (*str)
	{
		if (*str == '%' && (tmp = str + 1))
		{
			count = ft_putstrwrapper(ft_find_conv(&tmp, ap));
			len += count;
			str = tmp;
		}
		else if ((len = len + 1))
			ft_putchar(*(str++));
	}
	return (len);
}
