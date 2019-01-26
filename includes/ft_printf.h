/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:30:04 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/26 19:04:48 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>

int			ft_printf(const char *str, ...);

/*
** Function to field width, precision and all the flags
*/
char		*ft_conversion(char **str, va_list ap);

/*
** Function to convert the input to character array
*/
char		*ft_convert(char ch, int *arr, va_list ap);

/*
** Function to perform conversion from int to character array
*/
char		*ft_int_conv(char ch, int *arr, va_list ap);

/*
** Function to perform conversion from double to character array
*/
char		*ft_float_conv(int *arr, va_list ap);

/*
** Helper functions
*/
void		ft_tolowercase(char *str);
void		ft_apply_field_width(char **str, int field, char neg);
void		ft_apply_precision(char **str, int precision, int type);
void		ft_delfront(char **str);
void		ft_addstr(char **str, char ch, int front);
void		ft_hash_flag(char **str, int hex);
void		ft_sign_flag(char **str, int sign);
char		*ft_itoa(long long num);
char		*ft_itoa_base(unsigned long long num, int base);

#endif
