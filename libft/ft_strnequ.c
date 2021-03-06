/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:57:31 by dkhatri           #+#    #+#             */
/*   Updated: 2018/11/26 12:45:48 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (i < n && *s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (0);
		s1 = s1 + 1;
		s2 = s2 + 1;
		i = i + 1;
	}
	if (i < n)
	{
		if (*s1 != '\0' && *s2 == '\0')
			return (0);
		if (*s2 != '\0' && *s1 == '\0')
			return (0);
	}
	return (1);
}
