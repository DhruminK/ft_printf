/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:55:55 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/26 18:02:32 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_delfront(char **str)
{
	char	*s;
	int		len;

	if (!str || !*str)
		return ;
	len = ft_strlen(*str);
	if (!(s = ft_strnew(len - 1)))
		return ;
	ft_strcpy(s, (*str) + 1);
	ft_strdel(str);
	*str = s;
}

void	ft_addstr(char **str, char ch, int front)
{
	char	*tmp;
	char	*dup;

	if (!str)
		return ;
	if (!(dup = ft_strnew(1)))
		return ;
	*dup = ch;
	tmp = ft_strjoin(front ? dup : *str, front ? *str : dup);
	ft_strdel(str);
	ft_strdel(&dup);
	*str = tmp;
}
