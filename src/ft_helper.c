/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:58:46 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/22 17:13:33 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_tolowercase(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str = *str - 'A' + 'a';
		str = str + 1;
	}
}

int		ft_findzero(char *str)
{
	int		len;
	int		i;

	len = ft_strlen(str);
	i = -1;
	while (str[++i])
		if (str[i] == '0' && (i == 0 || !ft_isdigit(str[i - 1])))
			return (1);
	return (0);
}

char	*ft_apply_field_width(char *str, int field, char neg)
{
	char	*res;
	int		len;

	if ((len = ft_strlen(str)) >= field)
		return (str);
	res = ft_strnew(field);
	if (neg == '-')
		ft_strcpy(res, str);
	else
		ft_strcpy(res + field - len, str);
	ft_memset(res + (neg == '-' ? ft_strlen(str) : 0), \
			!neg || neg == '-' ? ' ' : '0', \
			field - len);
	free(str);
	return (res);
}
