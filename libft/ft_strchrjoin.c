/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:50:51 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/18 17:55:06 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrjoin(char *str, char ch)
{
	char	*s;
	size_t	len;
	size_t	i;

	if (!str && !ch)
		return (0);
	len = str ? ft_strlen(str) : 0;
	i = -1;
	s = ft_strnew(len + 1);
	if (!s)
		return (0);
	while (++i < len)
		*(s + i) = *(str + i);
	*(s + ++i) = ch;
	*(s + ++i) = 0;
	return (s);
}
