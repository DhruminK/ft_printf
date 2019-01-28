/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:23:46 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/28 19:20:10 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_putstrwrapper(char **str)
{
	int		len;

	if (!str || !*str)
		return (0);
	len = ft_strlen(*str);
	ft_putstr(*str);
	ft_strdel(str);
	return (len);
}

static int		ft_parse(char *str, va_list ap)
{
	int		len;
	char	*tmp;

	len = 0;
	while (*str)
	{
		if (*str == '%' && (str = str + 1))
		{
			if ((tmp = ft_conversion(&str, ap)))
				len += ft_putstrwrapper(&tmp);
		}
		else if ((len = len + 1))
			ft_putchar(*(str++));
	}
	return (len);
}

int				ft_printf(const char *str, ...)
{
	va_list		ap;
	int			len;
	char		*dup;

	dup = ft_strdup(str);
	va_start(ap, str);
	len = ft_parse(dup, ap);
	va_end(ap);
	free(dup);
	return (len);
}
