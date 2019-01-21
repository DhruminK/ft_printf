/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:56:07 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/21 16:58:37 by dkhatri          ###   ########.fr       */
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

static int		ft_parse(char *str, va_list ap)
{
	int		len;
	char	*tmp;
	char	ch;
	int		count;

	len = 0;
	while (*str)
	{
		if (*str == '%' && (str = str + 1))
		{
			if (!(tmp = ft_find_conv(&str, ap)))
			{
				ft_putchar(*(str++));
				continue ;
			}
			len += ft_putstrwrapper(tmp);
		}
		else if ((len = len + 1))
			ft_putchar(*(str++));
	}
	return (len);
}

int				ft_printf(const char *val, ...)
{
	va_list		ap;
	int			len;
	char		*str;

	va_start(ap, val);
	len = 0;
	str = ft_strdup(val);
	len = ft_parse(str, ap);
	va_end(ap);
	free(str);
	return (len);
}
