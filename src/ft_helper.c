/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:38:27 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/26 19:04:27 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_tolowercase(char *str)
{
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str = *str - 'A' + 'a';
		str = str + 1;
	}
}

void		ft_apply_field_width(char **str, int field, char neg)
{
	int		len;
	char	*s;
	int		i;
	char	*tmp;

	len = ft_strlen(*str);
	if (len >= field)
		return ;
	if (!(s = ft_strnew(field)) && !(i = -1))
		return ;
	ft_strcpy(neg == '-' ? s : (s + field - len), *str);
	tmp = s + (neg == '-' ? len : 0);
	while (++i < field - len)
		tmp[i] = (neg == '0' ? '0' : ' ');
	ft_strdel(str);
	*str = s;
}

void		ft_apply_precision(char **str, int precision, int type)
{
	int		len;
	char	*s;

	len = !type || !precision ? ft_strlen(*str) : \
		ft_strlen(ft_strchr(*str, '.') + 1);
	if (!precision || (len >= precision))
		return ;
	if (!type)
	{
		if (!(s = ft_strnew(precision)))
			return ;
		ft_strcpy(s + precision - len, *str);
		ft_memset(s, '0', precision - len);
	}
	else
	{
		if (!(s = ft_strnew(ft_strlen(*str) - len + precision)))
			return ;
		ft_strcpy(s, *str);
		ft_memset(s + len, '0', precision - len);
	}
	ft_strdel(str);
	*str = s;
}
