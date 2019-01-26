/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:31:57 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/26 18:58:16 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_isvalid(char ch)
{
	if (ch == 'd' || ch == 'i' || ch == 'u' || \
			ch == 'o' || ch == 'x' || ch == 'X' || ch == 's' || \
			ch == 'c' || ch == 'p' || ch == 'f')
		return (1);
	if (ch == '#' || ch == '+' || ch == ' ' || ch == '0' || ch == '-' || \
			ch == 'L' || ch == 'l' || ch == 'h')
		return (0);
	return (-1);
}

static void		ft_flag(char ch, int *flag)
{
	int		i;

	i = 0b10000000;
	if (ch == '#')
		*flag = *flag | i;
	if (ch == '+')
		*flag = *flag | (i >> 1);
	if (ch == ' ')
		*flag = *flag | (i >> 2);
	if (ch == '0')
		*flag = *flag | (i >> 3);
	if (ch == '-')
		*flag = *flag | (i >> 4);
	if (ch == 'L')
		*flag = *flag | (i >> 5);
	if (ch == 'l' && !(*flag & (i >> 6)))
		*flag = *flag + (i >> 7);
	if (ch == 'h' && !(*flag & (i >> 8)))
		*flag = *flag + (i >> 9);
}

static char		*ft_find_flag(char *str, int *arr)
{
	int		ret;
	int		i;

	i = 0;
	while (str[i] && !(ret = ft_isvalid(str[i])))
	{
		if (str[i] != '0' || (str[i] == '0' && \
					(i == 0 || !ft_isdigit(str[i - 1]))))
			ft_flag(str[i], arr);
		if (ft_isdigit(str[i]) && (i == 0 || \
					(!ft_isdigit(str[i - 1]) && str[i - 1] != '.')))
			arr[1] = ft_atoi(str + i);
		if (ft_isdigit(str[i]) && i != 0 && str[i - 1] == '.')
			arr[2] = ft_atoi(str + i);
		i = i + 1;
	}
	if (ret == -1)
		arr = 0;
	return (str + i);
}

char			*ft_conversion(char **str, va_list ap)
{
	int		*arr;
	char	*end;
	char	*tmp;

	arr = (int*)malloc(sizeof(int) * 3);
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = -1;
	end = ft_find_flag(*str, arr);
	*str = end + (arr ? 1 : 0);
	tmp = ft_convert(*end, arr, ap);
	free(arr);
	return (tmp);
}
