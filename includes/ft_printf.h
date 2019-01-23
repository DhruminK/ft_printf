/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:30:04 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/23 17:57:06 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>

/*
** Functions to find Conversion and Flags
*/
char		*ft_find_int_flag(char *str, va_list ap);
char		*ft_int_conv(char ch, int flag, va_list ap);
char		*ft_float_conv(int flag, int precision, va_list ap);
char		*ft_find_float_flag(char *str, va_list ap);
char		*ft_flag_string(char *str, char *result);
char		*ft_flag_pointer(char *s, void *p);
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
void		ft_addback(char **str, char ch);
void		ft_tolowercase(char *str);
int			ft_findzero(char *str);
char		*ft_apply_field_width(char *str, int field, char neg);
void		ft_space_plus_flag(char **str, char ch);
char		*ft_unsigned_int_flag(char *str, char *result, int field);
#endif
