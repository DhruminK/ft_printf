/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:43:47 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/23 18:11:35 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_addfront(char **str, char ch)
{
	char *tmp;
	char *dup;

	dup = ft_strnew(2);
	dup[0] = ch;
	tmp = ft_strjoin(dup, *str);
	ft_strdel(&dup);
	ft_strdel(str);
	*str = tmp;
}

char		*ft_flag_string(char *str, char *result)
{
	int		field;
	char	neg;
	int		i;
	int		len;
	char	*tmp;

	i = -1;
	field = 0;
	len = ft_strlen(str);
	while (++i < len - 1)
		if (ft_isdigit(str[i]) && (i == 0 || \
					(!ft_isdigit(str[i - 1]) && str[i - 1] != '.')))
			field = ft_atoi(str + i);
	if (!(neg = ft_strchr(str, '-') ? '-' : 0))
		neg = ft_findzero(str) ? '0' : 0;
	tmp = ft_apply_field_width(result, field, neg);
	return (tmp);
}

char		*ft_flag_pointer(char *str, void *p)
{
	long	num;
	char	*res;
	int		i;
	int		field;
	int		len;

	num = (long)(p - 0);
	ft_addfront(&str, '#');
	ft_addback(&str, 'x');
	while (++i < len - 1)
		if (ft_isdigit(str[i]) && (i == 0 || \
					(!ft_isdigit(str[i - 1]) && str[i - 1] != '.')))
			field = ft_atoi(str + i);
	res = ft_itoa_base(num, 16);
	ft_tolowercase(res);
	return (ft_unsigned_int_flag(str, res, field));
}
