/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowercase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:20:28 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/15 15:24:22 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlowercase(char *str)
{
	char	*str1;
	int		i;

	if (!str)
		return (0);
	i = ft_strlen(str);
	str1 = (char*)malloc(sizeof(char) * (i + 1));
	str1[i] = 0;
	while (--i >= 0)
		str1[i] = str[i] >= 'A' && str[i] <= 'Z' ? str[i] + 32 : str[i];
	return (str);
}
