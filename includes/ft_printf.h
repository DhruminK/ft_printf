/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:30:04 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/18 17:11:24 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>

/*
** Functions to find Conversion and Flags
*/
char		*ft_int_conv(char ch, int flag, va_list ap);
char		*ft_find_conv(char **str, va_list ap);

/*
** Signed itoa function and unsigned itoa function
*/
char		*ft_itoa(long long num);
char		*ft_itoa_base(unsigned long long num, int base);

/*
** Functions to Parse the String
*/
int			ft_printf(const char *val, ...);

/*
** Helper functions
*/
void		ft_tolowercase(char *str);
#endif
