/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:31:57 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/31 17:59:32 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_isvalid(char ch)
{
	if (ch == 'd' || ch == 'i' || ch == 'u' || \
			ch == 'o' || ch == 'x' || ch == 'X' || ch == 's' || \
			ch == 'c' || ch == 'p' || ch == 'f' || ch == '%' || ch == 'D' || \
			ch == 'U' || ch == 'F' || ch == 'O')
		return (1);
	if (ft_isdigit(ch) || ch == '.' || ch == '#' || ch == '+' || ch == ' ' || \
			ch == '0' || ch == '-' || ch == 'L' || ch == 'l' || ch == 'h' || \
			ch == 'z' || ch == 'j')
		return (0);
	return (-1);
}

static void		ft_flag(char ch, int *flag)
{
	if (ch != 'l' && ch != 'h' && ch != 'z' && ch != 'j')
		*flag = *flag | ft_flag_bin(ch);
	else if (ch == 'h' && !(*flag & ft_flag_bin(2)))
		*flag = *flag + ft_flag_bin(ch);
	else if (ch == 'l' && !(*flag & ft_flag_bin(1)))
		*flag = *flag + ft_flag_bin(ch);
	else if (ch == 'z' || ch == 'j')
		*flag = *flag | ft_flag_bin(1);
}

static char		*ft_find_flag(char *str, int *arr)
{
	int		ret;
	int		i;

	i = 0;
	while (str[i] && !(ret = ft_isvalid(str[i])))
	{
		if (str[i] != '0' || (str[i] == '0' && \
					(i == 0 || \
					(!ft_isdigit(str[i - 1]) && str[i - 1] != '.'))))
			ft_flag(str[i], arr);
		if (ft_isdigit(str[i]) && (i == 0 || \
					(!ft_isdigit(str[i - 1]) && str[i - 1] != '.')))
			(arr)[1] = ft_max(arr[1], ft_atoi(str + i));
		if (i != 0 && str[i - 1] == '.')
			(arr)[2] = ft_atoi(str + i);
		i = i + 1;
	}
	if (ret == -1)
		arr[2] = -2;
	else
		(arr)[2] = i != 0 && str[i - 1] == '.' ? 0 : (arr)[2];
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
	*str = end + (!*end ? 0 : 1);
	if ((*end == 'D' || *end == 'O' || *end == 'U') && \
			(*end = *end - 'A' + 'a'))
		arr[0] = arr[0] | ft_flag_bin('l');
	tmp = ft_convert(end, arr, ap);
	free(arr);
	return (tmp);
}
